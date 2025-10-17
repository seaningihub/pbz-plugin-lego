// Fill out your copyright notice in the Description page of Project Settings.


#include "SLGATimelineTransportControls.h"
#include "SlateOptMacros.h"
#include "EditorWidgetsModule.h"
#include "LGATimelinePreviewer.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorSettings.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLGATimelineTransportControls::Construct(const FArguments& InArgs, TSharedPtr<FLGATimelinePreviewer> InTimelinePreviewer)
{
	TimelinePreviewer = InTimelinePreviewer;

	check(TimelinePreviewer.IsValid());

	FEditorWidgetsModule& EditorWidgetsModule = FModuleManager::LoadModuleChecked<FEditorWidgetsModule>("EditorWidgets");

	FTransportControlArgs TransportControlArgs;
	TransportControlArgs.OnForwardPlay = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_Forward);
	TransportControlArgs.OnForwardStep = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_Forward_Step);
	TransportControlArgs.OnBackwardStep = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_Backward_Step);
	TransportControlArgs.OnForwardEnd = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_Forward_End);
	TransportControlArgs.OnBackwardEnd = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_Backward_End);
	TransportControlArgs.OnToggleLooping = FOnClicked::CreateSP(this, &SLGATimelineTransportControls::OnClick_ToggleLoop);
	TransportControlArgs.OnGetLooping = FOnGetLooping::CreateSP(this, &SLGATimelineTransportControls::IsLoopStatusOn);
	TransportControlArgs.OnGetPlaybackMode = FOnGetPlaybackMode::CreateSP(InTimelinePreviewer.Get(), &FLGATimelinePreviewer::GetPlaybackMode);

	ChildSlot
	[
		EditorWidgetsModule.CreateTransportControl(TransportControlArgs)
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION



FReply SLGATimelineTransportControls::OnClick_Forward_Step()
{
	TimelinePreviewer.Pin()->AdvanceTime(FLegoAbilityEditor::GetEditorSettings().GetAbilityTimeStepDelta());
	return FReply::Handled();
}

FReply SLGATimelineTransportControls::OnClick_Forward_End()
{
	TSharedPtr<FLGATimelinePreviewer> TimelinePreviewerPin = TimelinePreviewer.Pin();
	if (TimelinePreviewerPin.IsValid())
	{
		TimelinePreviewerPin->GotoEnd();
	}

	return FReply::Handled();
}

FReply SLGATimelineTransportControls::OnClick_Backward_Step()
{
	TimelinePreviewer.Pin()->AdvanceTime(- FLegoAbilityEditor::GetEditorSettings().GetAbilityTimeStepDelta());
	return FReply::Handled();
}

FReply SLGATimelineTransportControls::OnClick_Backward_End()
{
	TSharedPtr<FLGATimelinePreviewer> TimelinePreviewerPin = TimelinePreviewer.Pin();
	if (TimelinePreviewerPin.IsValid())
	{
		TimelinePreviewerPin->Reset();
	}
	
	return FReply::Handled();
}

FReply SLGATimelineTransportControls::OnClick_Forward()
{
	TimelinePreviewer.Pin()->TogglePlay();
	return FReply::Handled();
}

FReply SLGATimelineTransportControls::OnClick_ToggleLoop()
{
	TimelinePreviewer.Pin()->ToggleLoop();

	return FReply::Handled();
}

bool SLGATimelineTransportControls::IsLoopStatusOn() const
{
	return TimelinePreviewer.Pin()->GetLoop();
}

EPlaybackMode::Type SLGATimelineTransportControls::GetPlaybackMode() const
{
	return TimelinePreviewer.Pin()->GetPlaybackMode();
}


