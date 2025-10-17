// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineOutlinerItem.h"
#include "LGATimelineTrack.h"
#include "Widgets/Text/STextBlock.h"
#include "SLGATimelineOutliner.h"
#include "Widgets/SOverlay.h"

SLGATimelineOutlinerItem::~SLGATimelineOutlinerItem()
{
	TSharedPtr<SLGATimelineOutliner> Outliner = StaticCastSharedPtr<SLGATimelineOutliner>(OwnerTablePtr.Pin());
	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (Outliner.IsValid() && PinnedTrack.IsValid())
	{
		Outliner->OnChildRowRemoved(PinnedTrack.ToSharedRef());
	}
}

void SLGATimelineOutlinerItem::Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTableView, const TSharedRef<FLGATimelineTrack>& InTrack)
{
	Track = InTrack;
	HighlightText = InArgs._HighlightText;

	SMultiColumnTableRow::Construct(
		SMultiColumnTableRow::FArguments()
			.ShowSelection(true),
		InOwnerTableView);
}

TSharedRef<SWidget> SLGATimelineOutlinerItem::GenerateWidgetForColumn(const FName& ColumnId)
{
	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (PinnedTrack.IsValid())
	{
		return SNew(SOverlay)
		+SOverlay::Slot()
		[
			PinnedTrack->GenerateContainerWidgetForOutliner(SharedThis(this))
		];
	}

	return SNullWidget::NullWidget;
}

void SLGATimelineOutlinerItem::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	StaticCastSharedPtr<SLGATimelineOutliner>(OwnerTablePtr.Pin())->ReportChildRowGeometry(Track.Pin().ToSharedRef(), AllottedGeometry);
}

FVector2D SLGATimelineOutlinerItem::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (PinnedTrack.IsValid())
	{
		return FVector2D(100.0f, PinnedTrack->GetHeight() + PinnedTrack->GetPadding().Combined());
	}

	return FVector2D(100.0f, 16.0f);
}

void SLGATimelineOutlinerItem::AddTrackAreaReference(const TSharedPtr<SLGATimelineTrack>& InTrackWidget)
{
	TrackWidget = InTrackWidget;
}

void SLGATimelineOutlinerItem::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SMultiColumnTableRow<TSharedRef<FLGATimelineTrack>>::OnMouseEnter(MyGeometry, MouseEvent);

	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (PinnedTrack.IsValid())
	{
		PinnedTrack->SetHovered(true);
	}
}

void SLGATimelineOutlinerItem::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	SMultiColumnTableRow<TSharedRef<FLGATimelineTrack>>::OnMouseLeave(MouseEvent);

	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (PinnedTrack.IsValid())
	{
		PinnedTrack->SetHovered(false);
	}
}

bool SLGATimelineOutlinerItem::IsHovered() const
{
	TSharedPtr<FLGATimelineTrack> PinnedTrack = Track.Pin();
	if (PinnedTrack.IsValid())
	{
		return SMultiColumnTableRow<TSharedRef<FLGATimelineTrack>>::IsHovered() || PinnedTrack->IsHovered();
	}

	return SMultiColumnTableRow<TSharedRef<FLGATimelineTrack>>::IsHovered();
}