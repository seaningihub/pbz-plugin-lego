// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineModel.h"
#include "LGATimelineTrack_Actions.h"
#include "LGATimelineTrack_ActionsPanel.h"
#include "LGATimelineTrack_TimingPanel.h"
#include "FrameNumberDisplayFormat.h"
#include "Framework/Commands/UICommandList.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorSettings.h"
#include "LGATimeline.h"
#include "LGATimelinePreviewer.h"
#include "Timeline/LGATimelineTrack_FloatCurve.h"
#include "Animation/AnimCurveTypes.h"

#define LOCTEXT_NAMESPACE "FAnimModel_AnimSequence"

FLGATimelineModel::FLGATimelineModel(const TSharedRef<FUICommandList>& InCommandList, TSharedPtr<FLegoAbilityEditor> AbilityEditor, ULGATimeline* InTimeline)
	: FLGATimelineModelBase(InCommandList, AbilityEditor)
	, Timeline(InTimeline)
{
	UpdateRange();

	// Clear timing display flags
	for (bool& bElementNodeDisplayFlag : TimingElementNodeDisplayFlags)
	{
		bElementNodeDisplayFlag = true;
	}

	// Clear actions timing display flags
	for (bool& bElementNodeDisplayFlag : ActionsTimingElementNodeDisplayFlags)
	{
		bElementNodeDisplayFlag = true;
	}
}

void FLGATimelineModel::Initialize()
{
	const FLegoAbilityEditorTimelineCommands& Commands = FLegoAbilityEditorTimelineCommands::Get();
	TSharedRef<FUICommandList> CommandList = WeakCommandList.Pin().ToSharedRef();

	CommandList->MapAction(
		Commands.DisplayFrames,
		FExecuteAction::CreateSP(this, &FLGATimelineModel::SetDisplayFormat, EFrameNumberDisplayFormats::Frames),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FLGATimelineModel::IsDisplayFormatChecked, EFrameNumberDisplayFormats::Frames));

	CommandList->MapAction(
		Commands.DisplaySeconds,
		FExecuteAction::CreateSP(this, &FLGATimelineModel::SetDisplayFormat, EFrameNumberDisplayFormats::Seconds),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FLGATimelineModel::IsDisplayFormatChecked, EFrameNumberDisplayFormats::Seconds));

	CommandList->MapAction(
		Commands.DisplayPercentage,
		FExecuteAction::CreateSP(this, &FLGATimelineModel::ToggleDisplayPercentage),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FLGATimelineModel::IsDisplayPercentageChecked));

	CommandList->MapAction(
		Commands.DisplaySecondaryFormat,
		FExecuteAction::CreateSP(this, &FLGATimelineModel::ToggleDisplaySecondary),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FLGATimelineModel::IsDisplaySecondaryChecked));
}

void FLGATimelineModel::RefreshTracks()
{
	ClearTrackSelection();

	// Clear all tracks
	RootTracks.Empty();

	// Add notifies
	RefreshNotifyTracks();

	// Add curves
	RefreshCurveTracks();

	// Tell the UI to refresh
	OnTracksChangedDelegate.Broadcast();

	UpdateRange();
}

void FLGATimelineModel::RefreshNotifyTracks()
{
	Timeline->InitializeNotifyTrack();

	// Add the timing panel
	if (!TimingPanel.IsValid())
	{
		TimingPanel = MakeShared<FLGATimelineTrack_TimingPanel>(SharedThis(this));
	}
	RootTracks.Add(TimingPanel.ToSharedRef());

	// Add root track for actions
	if (!ActionRoot.IsValid())
	{
		ActionRoot = MakeShared<FLGATimelineTrack_Actions>(SharedThis(this));
	}

	ActionRoot->ClearChildren();
	RootTracks.Add(ActionRoot.ToSharedRef());

	// Add tracks for actions
	if (!ActionPanel.IsValid())
	{
		ActionPanel = MakeShared<FLGATimelineTrack_ActionsPanel>(SharedThis(this));
		ActionRoot->SetAnimNotifyPanel(ActionPanel.ToSharedRef());
	}
	ActionPanel->Update();

	ActionRoot->AddChild(ActionPanel.ToSharedRef());
}

void FLGATimelineModel::RefreshCurveTracks()
{
	if (!CurveRoot.IsValid())
	{
		// Add a root track for curves
		CurveRoot = MakeShared<FLGATimelineTrack_Curves>(SharedThis(this));
	}

	CurveRoot->ClearChildren();
	RootTracks.Add(CurveRoot.ToSharedRef());

	// Next add a track for each float curve
	for (const FFloatCurve& FloatCurve : Timeline->FloatCurves)
	{
		CurveRoot->AddChild(MakeShared<FLGATimelineTrack_FloatCurve>(FloatCurve.GetName(), SharedThis(this)));
	}
}

void FLGATimelineModel::SetDisplayFormat(EFrameNumberDisplayFormats InFormat)
{
	GetMutableDefault<ULegoAbilityEditorSettings>()->TimelineDisplayFormat = InFormat;
	SaveSettings();
}

bool FLGATimelineModel::IsDisplayFormatChecked(EFrameNumberDisplayFormats InFormat) const
{
	return GetDefault<ULegoAbilityEditorSettings>()->TimelineDisplayFormat == InFormat;
}

void FLGATimelineModel::ToggleDisplayPercentage()
{
	GetMutableDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayPercentage = !GetDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayPercentage;
	SaveSettings();
}

bool FLGATimelineModel::IsDisplayPercentageChecked() const
{
	return GetDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayPercentage;
}

void FLGATimelineModel::ToggleDisplaySecondary()
{
	GetMutableDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayFormatSecondary = !GetDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayFormatSecondary;
	SaveSettings();
}

bool FLGATimelineModel::IsDisplaySecondaryChecked() const
{
	return GetDefault<ULegoAbilityEditorSettings>()->bTimelineDisplayFormatSecondary;
}

void FLGATimelineModel::SaveSettings()
{
	GetMutableDefault<ULegoAbilityEditorSettings>()->SaveConfig();
}

void FLGATimelineModel::UpdateRange(bool ResetWorkingRange)
{
	if (Timeline.IsValid())
	{
		FAnimatedRange PlaybackRange = FAnimatedRange(0.0, (double)Timeline->GetPlayLength());

		if (ResetWorkingRange)
		{
			float Offset = 0.5f;
			WorkingRange = FAnimatedRange(PlaybackRange.GetLowerBoundValue() - Offset, PlaybackRange.GetUpperBoundValue() + Offset);
		}

		// Update view/range if playback range changed
		SetViewRange(PlaybackRange);
	}
}

bool FLGATimelineModel::IsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType) const
{
	return TimingElementNodeDisplayFlags[ElementType];
}

void FLGATimelineModel::ToggleTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType)
{
	TimingElementNodeDisplayFlags[ElementType] = !TimingElementNodeDisplayFlags[ElementType];
}

bool FLGATimelineModel::IsActionsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType) const
{
	return ActionsTimingElementNodeDisplayFlags[ElementType];
}

void FLGATimelineModel::ToggleActionsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType)
{
	ActionsTimingElementNodeDisplayFlags[ElementType] = !ActionsTimingElementNodeDisplayFlags[ElementType];
}

bool FLGATimelineModel::ClampToEndTime(float NewEndTime)
{
	float SequenceLength = Timeline->GetPlayLength();

	//if we had a valid sequence length before and our new end time is shorter
	//then we need to clamp.
	return (SequenceLength > 0.f && NewEndTime < SequenceLength);
}

void FLGATimelineModel::SetAbilityTimeline(ULGATimeline* InTimeline)
{
	if (Timeline != InTimeline)
	{
		Timeline = InTimeline;
		UpdateRange(true);
	}
	
	RefreshTracks();

	GetTimelinePreviewer()->SetCurrentTimeline(InTimeline);
}

#undef LOCTEXT_NAMESPACE