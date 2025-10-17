// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineTrack_Actions.h"
#include "Animation/AnimSequenceBase.h"
#include "LGATimelineModel.h"
#include "LGATimelineTrack_ActionsPanel.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PersonaUtils.h"
#include "ScopedTransaction.h"
#include "LegoAbilityEditorCommands.h"
#include "LGATimeline.h"
#include "Widgets/Layout/SBorder.h"

#define LOCTEXT_NAMESPACE "FLGATimelineTrack_Actions"

FLGATimelineTrack_Actions::FLGATimelineTrack_Actions(const TSharedRef<FLGATimelineModelBase>& InModel)
	: FLGATimelineTrack(LOCTEXT("ActionsRootTrackLabel", "Actions"), LOCTEXT("ActionsRootTrackToolTip", "Actions"), InModel)
{
}

TSharedRef<SWidget> FLGATimelineTrack_Actions::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedPtr<SBorder> OuterBorder;
	TSharedPtr<SHorizontalBox> InnerHorizontalBox;
	TSharedRef<SWidget> OutlinerWidget = GenerateStandardOutlinerWidget(InRow, true, OuterBorder, InnerHorizontalBox);

	OuterBorder->SetBorderBackgroundColor(FLegoAbilityEditorStyle::GetColor("AnimTimeline.Outliner.HeaderColor"));

	InnerHorizontalBox->AddSlot()
		.AutoWidth()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(OutlinerRightPadding, 1.0f)
		[
			PersonaUtils::MakeTrackButton(LOCTEXT("AddTrackButtonText", "Track"), FOnGetContent::CreateSP(this, &FLGATimelineTrack_Actions::BuildNotifiesSubMenu), MakeAttributeSP(this, &FLGATimelineTrack_Actions::IsHovered))
		];

	return OutlinerWidget;
}

TSharedRef<SWidget> FLGATimelineTrack_Actions::BuildNotifiesSubMenu()
{
	FMenuBuilder MenuBuilder(true, GetModel()->GetCommandList());

	MenuBuilder.BeginSection("Actions", LOCTEXT("ActionsMenuSection", "Actions"));
	{
		MenuBuilder.AddMenuEntry(
			FLegoAbilityEditorTimelineCommands::Get().AddActionTrack->GetLabel(),
			FLegoAbilityEditorTimelineCommands::Get().AddActionTrack->GetDescription(),
			FLegoAbilityEditorTimelineCommands::Get().AddActionTrack->GetIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FLGATimelineTrack_Actions::AddTrack)
			)
		);
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("TimingPanelOptions", LOCTEXT("TimingPanelOptionsHeader", "Options"));
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("ToggleTimingNodes_Actions", "Show Action Timing Nodes"),
			LOCTEXT("ShowActionTimingNodes", "Show or hide the timing display for actions in the action panel"),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateSP(&StaticCastSharedRef<FLGATimelineModel>(GetModel()).Get(), &FLGATimelineModel::ToggleActionsTimingElementDisplayEnabled, ELGATimingElementType::InstantAction),
				FCanExecuteAction(),
				FIsActionChecked::CreateSP(&StaticCastSharedRef<FLGATimelineModel>(GetModel()).Get(), &FLGATimelineModel::IsActionsTimingElementDisplayEnabled, ELGATimingElementType::InstantAction)
			),
			NAME_None,
			EUserInterfaceActionType::ToggleButton
		);
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

void FLGATimelineTrack_Actions::AddTrack()
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	FScopedTransaction Transaction(LOCTEXT("AddActionTrack", "Add Action Track"));
	Timeline->Modify();

	FLGAActionTrack NewItem;
	NewItem.TrackName = GetNewTrackName(Timeline);
	NewItem.TrackColor = FLinearColor::White;

	Timeline->AbilityActionTracks.Add(NewItem);

	NotifiesPanel.Pin()->RequestTrackRename(Timeline->AbilityActionTracks.Num() - 1);

	NotifiesPanel.Pin()->Update();
}

FName FLGATimelineTrack_Actions::GetNewTrackName(ULGATimeline* Timeline)
{
	TArray<FName> TrackNames;
	TrackNames.Reserve(50);

	for (const FLGAActionTrack& Track : Timeline->AbilityActionTracks)
	{
		TrackNames.Add(Track.TrackName);
	}

	FName NameToTest;
	int32 TrackIndex = 1;
	
	do 
	{
		NameToTest = *FString::FromInt(TrackIndex++);
	} while (TrackNames.Contains(NameToTest));

	return NameToTest;
}

#undef LOCTEXT_NAMESPACE