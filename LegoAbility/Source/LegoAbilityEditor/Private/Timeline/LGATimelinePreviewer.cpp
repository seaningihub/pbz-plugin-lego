// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelinePreviewer.h"
#include "SLGATimeline.h"
#include "Actions/LGAAction.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorViewportClient.h"

FLGATimelinePreviewer::FLGATimelinePreviewer(FLGATimelineModelBase* InTimelineModel)
	: TimelineModel(InTimelineModel)
{

}

void FLGATimelinePreviewer::SetCurrentTimeline(ULGATimeline* Timeline)
{
	if (PreviewTimeline.Get() != Timeline)
	{
		Reset();
	}

	PreviewTimeline = Timeline;
}

void FLGATimelinePreviewer::SetPosition(float InPosition)
{
	if (!PreviewTimeline.IsValid())
	{
		return;
	}

	float LastPosition = Position;
	Position = FMath::Clamp(InPosition, 0, GetLength());

	TWeakPtr<FLegoAbilityEditor> Editor = TimelineModel->GetAbilityEditor();
	AActor* PreviewActor = Editor.Pin()->GetAbilityPreviewActor();

	// Start new action
	for (int32 i = 0; i < PreviewTimeline->Actions.Num(); ++i)
	{
		FLGAActionEvent& ActionEvent = PreviewTimeline->Actions[i];
		ULGAAction* CurrentAction = GetAction(ActionEvent);
		if (!CurrentAction)
		{
			continue;
		}

		if (!CurrentAction->CanPreview(PreviewActor, PreviewTimeline.Get()))
		{
			continue;
		}

		if (CurrentAction->IsSingleFrame())
		{
			if (CurrentAction->bSupportPreview && ActionEvent.StartTime <= Position && ActionEvent.StartTime > LastPosition)
			{
				// activate action
				CurrentAction->BeginPreview(PreviewActor, ActionEvent.Duration);
				continue;
			}
		}
		else if (FMath::Max(ActionEvent.StartTime, LastPosition) <= FMath::Min(ActionEvent.GetEndTime(), Position))
		{
			if (!CurrentAction->bSupportPreview)
			{
				continue;
			}

			if (ActiveActionEvents.Contains(ActionEvent.Guid))
			{
				continue;
			}

			// add ActionEvent to ActiveActionEvents
			ActiveActionEvents.Add(ActionEvent.Guid);

			// activate action
			CurrentAction->BeginPreview(PreviewActor, ActionEvent.Duration);
		}
	}

	TArray< FLGAActionEvent*, TInlineAllocator<128> > ExpiredAction;

	// Update active actions
	TArray<FGuid, TInlineAllocator<128>> InvalidGuid;
	for (FGuid ActionGuid : ActiveActionEvents)
	{
		FLGAActionEvent* ActionEvent = PreviewTimeline->Actions.FindByPredicate([&](const FLGAActionEvent& Action) {return Action.Guid == ActionGuid; });
		if (ActionEvent)
		{
			if (Position < ActionEvent->GetStartTime() || Position > ActionEvent->GetEndTime())
			{
				ExpiredAction.Add(ActionEvent);
			}
			else
			{
				GetAction(*ActionEvent)->SetPosition(PreviewActor, Position - ActionEvent->GetStartTime(), ActionEvent->Duration);
			}
		}
		else
		{
			InvalidGuid.Add(ActionGuid);
		}
	}

	// Clear Invalid Guid
	for (FGuid ActionGuid : InvalidGuid)
	{
		ActiveActionEvents.Remove(ActionGuid);
	}


	// Sort by end time
	ExpiredAction.StableSort([](FLGAActionEvent& A, FLGAActionEvent& B) { return A.GetEndTime() > B.GetEndTime(); });
	for (FLGAActionEvent* ActionEvent : ExpiredAction)
	{
		GetAction(*ActionEvent)->EndPreview(PreviewActor);

		// remove ActionEvent from ActiveActionEvents
		ActiveActionEvents.Remove(ActionEvent->Guid);
	}

	// Viewport camera
	bool bFollowCamera = false;
	for (FGuid ActionGuid : ActiveActionEvents)
	{
		FLGAActionEvent* ActionEvent = PreviewTimeline->Actions.FindByPredicate([&](const FLGAActionEvent& Action) {return Action.Guid == ActionGuid; });
		if (ActionEvent)
		{
			if (GetAction(*ActionEvent)->NeedFollowCamera())
			{
				bFollowCamera = true;
			}
		}
	}
	if (FLegoAbilityEditorViewportClient* Viewport = TimelineModel->GetAbilityEditor().Pin()->GetViewportClient())
	{
		Viewport->SetFollowPreview(bFollowCamera);
		Viewport->bNeedsRedraw = true;
	}

	PreviewTimeline->PreviewPosition = Position;
}

void FLGATimelinePreviewer::AdvanceTime(float DeltaTime)
{
	SetPosition(Position + DeltaTime);
}

void FLGATimelinePreviewer::TogglePlay()
{
	bPlaying = !bPlaying;

	CurrentMode = bPlaying ? EPlaybackMode::PlayingForward : EPlaybackMode::Stopped;
}


void FLGATimelinePreviewer::Tick(float DeltaTime)
{
	if (bPlaying)
	{
		float LastPosition = Position;

		if (PreviewTimeline.IsValid())
		{
			DeltaTime = PreviewTimeline->GetOriginalStep(Position, DeltaTime);
		}

		if (LastPosition + DeltaTime > GetLength())
		{
			Reset();
			bPlaying = bLoop ? true : false;

			return;
		}

		SetPosition(Position + DeltaTime);
	}
}

void FLGATimelinePreviewer::Pause()
{
	bPlaying = false;

	CurrentMode = EPlaybackMode::Stopped;
}

void FLGATimelinePreviewer::Reset()
{
	if (PreviewTimeline.IsValid())
	{
		TWeakPtr<FLegoAbilityEditor> Editor = TimelineModel->GetAbilityEditor();
		AActor* PreviewActor = Editor.Pin()->GetAbilityPreviewActor();

		for (FGuid ActionGuid : ActiveActionEvents)
		{
			FLGAActionEvent* ActionEvent = PreviewTimeline->Actions.FindByPredicate([&](const FLGAActionEvent& Action) {return Action.Guid == ActionGuid; });
			if (ActionEvent)
			{
				GetAction(*ActionEvent)->EndPreview(PreviewActor);
			}
		}
	}
	ActiveActionEvents.Reset();

	CurrentMode = EPlaybackMode::Stopped;
	SetPosition(0);

	bPlaying = false;
}

void FLGATimelinePreviewer::GotoEnd()
{
	if (PreviewTimeline.IsValid())
	{
		SetPosition(PreviewTimeline->SequenceLength);
	}
}

float FLGATimelinePreviewer::GetLength()
{
	return PreviewTimeline.IsValid() ? PreviewTimeline->SequenceLength : 0.f;
}


ULGAAction* FLGATimelinePreviewer::GetAction(const FLGAActionEvent& ActionEvent)
{
	TWeakPtr<FLegoAbilityEditor> Editor = TimelineModel->GetAbilityEditor();
	ULegoAbilityBlueprint* Blueprint = Editor.Pin()->GetAbilityBlueprint();

	if (Blueprint)
	{
		ULGAAction* OverrideAction = Blueprint->GetOverrideAction(PreviewTimeline.Get(), ActionEvent.Guid);
		if (OverrideAction)
		{
			OverrideAction->PreviewWorld = PreviewTimeline->PreviewWorld;
			return OverrideAction;
		}
	}

	return ActionEvent.Action;
}
