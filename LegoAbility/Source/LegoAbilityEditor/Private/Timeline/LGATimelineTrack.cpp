// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineTrack.h"
#include "LGATimelineModelBase.h"
#include "EditorStyleSet.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SExpanderArrow.h"
#include "SLGATimelineOutlinerItem.h"
#include "LegoAbilityEditorStyle.h"
#include "LGATimeline.h"
 
#define LOCTEXT_NAMESPACE "FAnimTimelineTrack"

const float FLGATimelineTrack::OutlinerRightPadding = 8.0f;

FText FLGATimelineTrack::GetLabel() const
{
	return DisplayName;
}

FText FLGATimelineTrack::GetToolTipText() const
{
	return ToolTipText;
}

bool FLGATimelineTrack::Traverse_ChildFirst(const TFunctionRef<bool(FLGATimelineTrack&)>& InPredicate, bool bIncludeThisTrack)
{
	for (TSharedRef<FLGATimelineTrack>& Child : Children)
	{
		if (!Child->Traverse_ChildFirst(InPredicate, true))
		{
			return false;
		}
	}

	return bIncludeThisTrack ? InPredicate(*this) : true;
}

bool FLGATimelineTrack::Traverse_ParentFirst(const TFunctionRef<bool(FLGATimelineTrack&)>& InPredicate, bool bIncludeThisTrack)
{
	if (bIncludeThisTrack && !InPredicate(*this))
	{
		return false;
	}

	for (TSharedRef<FLGATimelineTrack>& Child : Children)
	{
		if (!Child->Traverse_ParentFirst(InPredicate, true))
		{
			return false;
		}
	}

	return true;
}

bool FLGATimelineTrack::TraverseVisible_ChildFirst(const TFunctionRef<bool(FLGATimelineTrack&)>& InPredicate, bool bIncludeThisTrack)
{
	// If the item is not expanded, its children ain't visible
	if (IsExpanded())
	{
		for (TSharedRef<FLGATimelineTrack>& Child : Children)
		{
			if (Child->IsVisible() && !Child->TraverseVisible_ChildFirst(InPredicate, true))
			{
				return false;
			}
		}
	}

	if (bIncludeThisTrack && IsVisible())
	{
		return InPredicate(*this);
	}

	// Continue iterating regardless of visibility
	return true;
}

bool FLGATimelineTrack::TraverseVisible_ParentFirst(const TFunctionRef<bool(FLGATimelineTrack&)>& InPredicate, bool bIncludeThisTrack)
{
	if (bIncludeThisTrack && IsVisible() && !InPredicate(*this))
	{
		return false;
	}

	// If the item is not expanded, its children ain't visible
	if (IsExpanded())
	{
		for (TSharedRef<FLGATimelineTrack>& Child : Children)
		{
			if (Child->IsVisible() && !Child->TraverseVisible_ParentFirst(InPredicate, true))
			{
				return false;
			}
		}
	}

	return true;
}

TSharedRef<SWidget> FLGATimelineTrack::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedPtr<SBorder> OuterBorder;
	TSharedPtr<SHorizontalBox> InnerHorizontalBox;
	TSharedRef<SWidget> Widget = GenerateStandardOutlinerWidget(InRow, true, OuterBorder, InnerHorizontalBox);

	if (bIsHeaderTrack)
	{
		OuterBorder->SetBorderBackgroundColor(FLegoAbilityEditorStyle::GetColor("AnimTimeline.Outliner.HeaderColor"));
	}

	return Widget;
}

TSharedRef<SWidget> FLGATimelineTrack::GenerateStandardOutlinerWidget(const TSharedRef<SLGATimelineOutlinerItem>& InRow, bool bWithLabelText, TSharedPtr<SBorder>& OutOuterBorder, TSharedPtr<SHorizontalBox>& OutInnerHorizontalBox)
{
	TSharedRef<SWidget> Widget =
		SAssignNew(OutOuterBorder, SBorder)
		.ToolTipText(this, &FLGATimelineTrack::GetToolTipText)
		.BorderImage(FAppStyle::GetBrush("Sequencer.Section.BackgroundTint"))
		.BorderBackgroundColor(FLegoAbilityEditorStyle::GetColor("AnimTimeline.Outliner.ItemColor"))
		[
			SAssignNew(OutInnerHorizontalBox, SHorizontalBox)
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.AutoWidth()
			.Padding(4.0f, 1.0f)
			[
				SNew(SExpanderArrow, InRow)
			]
		];

	if (bWithLabelText)
	{
		OutInnerHorizontalBox->AddSlot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Left)
			.Padding(2.0f, 1.0f)
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.TextStyle(&FLegoAbilityEditorStyle::Get()->GetWidgetStyle<FTextBlockStyle>("AnimTimeline.Outliner.Label"))
				.Text(this, &FLGATimelineTrack::GetLabel)
				.HighlightText(InRow->GetHighlightText())
			];
	}

	return Widget;
}

TSharedRef<SWidget> FLGATimelineTrack::GenerateContainerWidgetForTimeline()
{
	return SNullWidget::NullWidget;
}

void FLGATimelineTrack::AddToContextMenu(FMenuBuilder& InMenuBuilder, TSet<FName>& InOutExistingMenuTypes) const
{

}

float FLGATimelineTrack::GetMaxInput() const
{
	return GetModel()->GetAbilityTimeline()->GetPlayLength();
}

float FLGATimelineTrack::GetViewMinInput() const
{
	return GetModel()->GetViewRange().GetLowerBoundValue();
}

float FLGATimelineTrack::GetViewMaxInput() const
{
	return GetModel()->GetViewRange().GetUpperBoundValue();
}

float FLGATimelineTrack::GetScrubValue() const
{
	const int32 Resolution = FMath::RoundToInt(GetModel()->GetFrameRate() * 1000);
	return (float)((double)GetModel()->GetScrubPosition().Value / (double)Resolution);
}

void FLGATimelineTrack::SelectObjects(const TArray<UObject*>& SelectedItems)
{
	GetModel()->SelectObjects(SelectedItems);
}

void FLGATimelineTrack::OnSetInputViewRange(float ViewMin, float ViewMax)
{
	GetModel()->SetViewRange(TRange<double>(ViewMin, ViewMax));
}

#undef LOCTEXT_NAMESPACE