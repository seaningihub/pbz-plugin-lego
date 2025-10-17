// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineTrack_TimingPanel.h"
#include "LGATimelineModel.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PersonaUtils.h"
#include "SLGATimelineTimingPanel.h"

#define LOCTEXT_NAMESPACE "FAnimTimelineTrack_TimingPanel"

FLGATimelineTrack_TimingPanel::FLGATimelineTrack_TimingPanel(const TSharedRef<FLGATimelineModelBase>& InModel) : FLGATimelineTrack(LOCTEXT("TimingLabel", "Timing"), LOCTEXT("TimingTooltip", "The timing of the various elements in this timeline"), InModel)
{
	SetHeight(24.0f);
}

TSharedRef<SWidget> FLGATimelineTrack_TimingPanel::GenerateContainerWidgetForTimeline()
{
	return SAssignNew(AnimTimingPanel, SLGATimelineTimingPanel, StaticCastSharedRef<FLGATimelineModel>(GetModel()))
		.InputMin(this, &FLGATimelineTrack_TimingPanel::GetMinInput)
		.InputMax(this, &FLGATimelineTrack_TimingPanel::GetMaxInput)
		.ViewInputMin(this, &FLGATimelineTrack_TimingPanel::GetViewMinInput)
		.ViewInputMax(this, &FLGATimelineTrack_TimingPanel::GetViewMaxInput)
		.OnSetInputViewRange(this, &FLGATimelineTrack_TimingPanel::OnSetInputViewRange);
}

TSharedRef<SWidget> FLGATimelineTrack_TimingPanel::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedPtr<SBorder> OuterBorder;
	TSharedPtr<SHorizontalBox> InnerHorizontalBox;
	TSharedPtr<SWidget> OutlinerWidget = GenerateStandardOutlinerWidget(InRow, true, OuterBorder, InnerHorizontalBox);

	InnerHorizontalBox->AddSlot()
		.AutoWidth()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(OutlinerRightPadding, 1.0f)
		[
			PersonaUtils::MakeTrackButton(LOCTEXT("EditCurvesButtonText", "Timing"), FOnGetContent::CreateSP(this, &FLGATimelineTrack_TimingPanel::BuildTimingSubMenu), MakeAttributeSP(this, &FLGATimelineTrack_TimingPanel::IsHovered))
		];

	return OutlinerWidget.ToSharedRef();
}

TSharedRef<SWidget> FLGATimelineTrack_TimingPanel::BuildTimingSubMenu()
{
	FMenuBuilder Builder(true, nullptr);

	Builder.BeginSection("TimingPanelOptions", LOCTEXT("TimingPanelOptionsHeader", "Options"));
	{
		Builder.AddMenuEntry(
			LOCTEXT("ToggleTimingNodes_Notifies", "Show Instant Action Timing Nodes"),
			LOCTEXT("ShowNotifyTimingNodes", "Show or hide the timing display for instant actions"),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateSP(AnimTimingPanel.Get(), &SLGATimelineTimingPanel::OnElementDisplayEnabledChanged, ELGATimingElementType::InstantAction),
				FCanExecuteAction(),
				FIsActionChecked::CreateSP(AnimTimingPanel.Get(), &SLGATimelineTimingPanel::IsElementDisplayEnabled, ELGATimingElementType::InstantAction)
			),
			NAME_None,
			EUserInterfaceActionType::ToggleButton
		);
	}
	Builder.EndSection();

	return Builder.MakeWidget();
}

#undef LOCTEXT_NAMESPACE