// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineOutliner.h"
#include "LGATimelineModelBase.h"
#include "LGATimelineTrack.h"
#include "SLGATimelineOutlinerItem.h"
#include "SLGATimelineTrackArea.h"
#include "Widgets/Input/SButton.h"
#include "SLGATimelineTrack.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Misc/TextFilterExpressionEvaluator.h"
#include "LegoAbilityEditor.h"

#define LOCTEXT_NAMESPACE "SLGATimelineOutliner"

SLGATimelineOutliner::~SLGATimelineOutliner()
{
	if (AnimModel.IsValid())
	{
		AnimModel.Pin()->OnTracksChanged().Remove(TracksChangedDelegateHandle);
	}
}

void SLGATimelineOutliner::Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModelBase>& InAnimModel, const TSharedRef<SLGATimelineTrackArea>& InTrackArea)
{	
	AnimModel = InAnimModel;
	TrackArea = InTrackArea;
	FilterText = InArgs._FilterText;
	bPhysicalTracksNeedUpdate = false;

	TracksChangedDelegateHandle = InAnimModel->OnTracksChanged().AddSP(this, &SLGATimelineOutliner::HandleTracksChanged);

	TextFilter = MakeShareable(new FTextFilterExpressionEvaluator(ETextFilterExpressionEvaluatorMode::BasicString));

	HeaderRow = SNew(SHeaderRow)
		.Visibility(EVisibility::Collapsed);

	HeaderRow->AddColumn(
		SHeaderRow::Column(TEXT("Outliner"))
		.FillWidth(1.0f)
	);

	STreeView::Construct
	(
		STreeView::FArguments()
		.TreeItemsSource(&InAnimModel->GetRootTracks())
		.SelectionMode(ESelectionMode::Multi)
		.OnGenerateRow(this, &SLGATimelineOutliner::HandleGenerateRow) 
		.OnGetChildren(this, &SLGATimelineOutliner::HandleGetChildren)
		.HeaderRow(HeaderRow)
		.ExternalScrollbar(InArgs._ExternalScrollbar)
		.OnExpansionChanged(this, &SLGATimelineOutliner::HandleExpansionChanged)
		.AllowOverscroll(EAllowOverscroll::No)
		.OnContextMenuOpening(this, &SLGATimelineOutliner::HandleContextMenuOpening)
	);

	// expand all
	for (TSharedRef<FLGATimelineTrack>& RootTrack : InAnimModel->GetRootTracks())
	{
		RootTrack->Traverse_ParentFirst([this](FLGATimelineTrack& InTrack)
		{
			SetItemExpansion(InTrack.AsShared(), InTrack.IsExpanded());
			return true;
		});
	}
}

void SLGATimelineOutliner::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	bool bTimlineEditable = (AnimModel.Pin()->GetAbilityEditor().Pin()->IsCurrentTimelineLocal());
	this->SetEnabled(bTimlineEditable);

	STreeView::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	// These are updated in both tick and paint since both calls can cause changes to the cached rows and the data needs
	// to be kept synchronized so that external measuring calls get correct and reliable results.
	if (bPhysicalTracksNeedUpdate)
	{
		PhysicalTracks.Reset();
		CachedTrackGeometry.GenerateValueArray(PhysicalTracks);

		PhysicalTracks.Sort([](const FCachedGeometry& A, const FCachedGeometry& B)
		{
			return A.Top < B.Top;
		});

		bPhysicalTracksNeedUpdate = false;
	}
}

int32 SLGATimelineOutliner::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	LayerId = STreeView::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	// These are updated in both tick and paint since both calls can cause changes to the cached rows and the data needs
	// to be kept synchronized so that external measuring calls get correct and reliable results.
	if (bPhysicalTracksNeedUpdate)
	{
		PhysicalTracks.Reset();
		CachedTrackGeometry.GenerateValueArray(PhysicalTracks);

		PhysicalTracks.Sort([](const FCachedGeometry& A, const FCachedGeometry& B) 
		{
			return A.Top < B.Top;
		});

		bPhysicalTracksNeedUpdate = false;
	}

	return LayerId + 1;
}

TSharedRef<ITableRow> SLGATimelineOutliner::HandleGenerateRow(TSharedRef<FLGATimelineTrack> InTrack, const TSharedRef<STableViewBase>& OwnerTable)
{
	TSharedRef<SLGATimelineOutlinerItem> Row =
		SNew(SLGATimelineOutlinerItem, OwnerTable, InTrack)
		.HighlightText(FilterText);

	// Ensure the track area is kept up to date with the virtualized scroll of the tree view
	TSharedPtr<SLGATimelineTrack> TrackWidget = TrackArea->FindTrackSlot(InTrack);

	if (!TrackWidget.IsValid())
	{
		// Add a track slot for the row
		TrackWidget = SNew(SLGATimelineTrack, InTrack, SharedThis(this))
			.ViewRange(AnimModel.Pin().Get(), &FLGATimelineModelBase::GetViewRange)
			[
				 InTrack->GenerateContainerWidgetForTimeline()
			];

		TrackArea->AddTrackSlot(InTrack, TrackWidget);
	}

	if (ensure(TrackWidget.IsValid()))
	{
		Row->AddTrackAreaReference(TrackWidget);
	}

	return Row;
}

void SLGATimelineOutliner::HandleGetChildren(TSharedRef<FLGATimelineTrack> Item, TArray<TSharedRef<FLGATimelineTrack>>& OutChildren)
{
	class FAnimOutlinerContext : public ITextFilterExpressionContext
	{
	public:
		explicit FAnimOutlinerContext(const FText& InFilterText)
			: FilterText(InFilterText)
		{
		}

		virtual bool TestBasicStringExpression(const FTextFilterString& InValue, const ETextFilterTextComparisonMode InTextComparisonMode) const override
		{
			return TextFilterUtils::TestBasicStringExpression(FilterText.ToString(), InValue, InTextComparisonMode);
		}

		virtual bool TestComplexExpression(const FName& InKey, const FTextFilterString& InValue, const ETextFilterComparisonOperation InComparisonOperation, const ETextFilterTextComparisonMode InTextComparisonMode) const override
		{
			return false;
		}

	private:
		FText FilterText;
	};


	if (!FilterText.Get().IsEmpty())
	{
		for (const TSharedRef<FLGATimelineTrack>& Child : Item->GetChildren())
		{
			if (!Child->SupportsFiltering() || TextFilter->TestTextFilter(FAnimOutlinerContext(Child->GetLabel())))
			{
				OutChildren.Add(Child);
			}
		}
	}
	else
	{
		OutChildren.Append(Item->GetChildren());
	}
}

void SLGATimelineOutliner::HandleExpansionChanged(TSharedRef<FLGATimelineTrack> InTrack, bool bIsExpanded)
{
	InTrack->SetExpanded(bIsExpanded);
	
	// Expand any children that are also expanded
	for (const TSharedRef<FLGATimelineTrack>& Child : InTrack->GetChildren())
	{
		if (Child->IsExpanded())
		{
			SetItemExpansion(Child, true);
		}
	}
}

TSharedPtr<SWidget> SLGATimelineOutliner::HandleContextMenuOpening()
{
	const bool bShouldCloseWindowAfterMenuSelection = true;
	FMenuBuilder MenuBuilder(bShouldCloseWindowAfterMenuSelection, AnimModel.Pin()->GetCommandList());

	AnimModel.Pin()->BuildContextMenu(MenuBuilder);

	// > 1 because the search widget is always added
	return MenuBuilder.GetMultiBox()->GetBlocks().Num() > 1 ? MenuBuilder.MakeWidget() : TSharedPtr<SWidget>();
}

void SLGATimelineOutliner::HandleTracksChanged()
{
	RequestTreeRefresh();
}

void SLGATimelineOutliner::ReportChildRowGeometry(const TSharedRef<FLGATimelineTrack>& InTrack, const FGeometry& InGeometry)
{
	float ChildOffset = TransformPoint(
		Concatenate(
			InGeometry.GetAccumulatedLayoutTransform(),
			GetCachedGeometry().GetAccumulatedLayoutTransform().Inverse()
		),
		FVector2D(0,0)
	).Y;

	FCachedGeometry* ExistingGeometry = CachedTrackGeometry.Find(InTrack);
	if (ExistingGeometry == nullptr || (ExistingGeometry->Top != ChildOffset || ExistingGeometry->Height != InGeometry.Size.Y))
	{
		CachedTrackGeometry.Add(InTrack, FCachedGeometry(InTrack, ChildOffset, InGeometry.Size.Y));
		bPhysicalTracksNeedUpdate = true;
	}
}

void SLGATimelineOutliner::OnChildRowRemoved(const TSharedRef<FLGATimelineTrack>& InTrack)
{
	CachedTrackGeometry.Remove(InTrack);
	bPhysicalTracksNeedUpdate = true;
}

TOptional<SLGATimelineOutliner::FCachedGeometry> SLGATimelineOutliner::GetCachedGeometryForTrack(const TSharedRef<FLGATimelineTrack>& InTrack) const
{
	if (const FCachedGeometry* FoundGeometry = CachedTrackGeometry.Find(InTrack))
	{
		return *FoundGeometry;
	}

	return TOptional<FCachedGeometry>();
}

TOptional<float> SLGATimelineOutliner::ComputeTrackPosition(const TSharedRef<FLGATimelineTrack>& InTrack) const
{
	// Positioning strategy:
	// Attempt to root out any visible track in the specified track's sub-hierarchy, and compute the track's offset from that
	float NegativeOffset = 0.f;
	TOptional<float> Top;
	
	// Iterate parent first until we find a tree view row we can use for the offset height
	auto Iter = [&](FLGATimelineTrack& InTrack)
	{		
		TOptional<FCachedGeometry> ChildRowGeometry = GetCachedGeometryForTrack(InTrack.AsShared());
		if (ChildRowGeometry.IsSet())
		{
			Top = ChildRowGeometry->Top;
			// Stop iterating
			return false;
		}

		NegativeOffset -= InTrack.GetHeight() + InTrack.GetPadding().Combined();
		return true;
	};

	InTrack->TraverseVisible_ParentFirst(Iter);

	if (Top.IsSet())
	{
		return NegativeOffset + Top.GetValue();
	}

	return Top;
}

void SLGATimelineOutliner::ScrollByDelta(float DeltaInSlateUnits)
{
	ScrollBy(GetCachedGeometry(), DeltaInSlateUnits, EAllowOverscroll::No);
}

void SLGATimelineOutliner::Private_SetItemSelection( TSharedRef<FLGATimelineTrack> TheItem, bool bShouldBeSelected, bool bWasUserDirected )
{
	if (TheItem->SupportsSelection())
	{
		AnimModel.Pin()->SetTrackSelected(TheItem, bShouldBeSelected);

		STreeView::Private_SetItemSelection(TheItem, bShouldBeSelected, bWasUserDirected);
	}
}

void SLGATimelineOutliner::Private_ClearSelection()
{
	AnimModel.Pin()->ClearTrackSelection();

	STreeView::Private_ClearSelection();
}

void SLGATimelineOutliner::Private_SelectRangeFromCurrentTo( TSharedRef<FLGATimelineTrack> InRangeSelectionEnd )
{
	STreeView::Private_SelectRangeFromCurrentTo(InRangeSelectionEnd);

	for (TSet<TSharedRef<FLGATimelineTrack>>::TIterator Iter = SelectedItems.CreateIterator(); Iter; ++Iter)
	{
		if (!(*Iter)->SupportsSelection())
		{
			Iter.RemoveCurrent();
		}
	}

	for (const TSharedRef<FLGATimelineTrack>& SelectedItem : SelectedItems)
	{
		AnimModel.Pin()->SetTrackSelected(SelectedItem, true);
	}
}

void SLGATimelineOutliner::RefreshFilter()
{
	TextFilter->SetFilterText(FilterText.Get());

	RequestTreeRefresh();
}

#undef LOCTEXT_NAMESPACE