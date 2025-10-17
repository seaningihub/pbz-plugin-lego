// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATask_PlayTimeline.h"
#include "AbilitySystemGlobals.h"
#include "Actions/LGAAction.h"
#include "LegoAbility.h"
#include "LegoAbilityLog.h"
#include "LGATimeline.h"
#include "LegoAbilitySystemComponent.h"
#if WITH_EDITOR
#include "AbilitySystemComponent.h"
#endif
#include "Engine/World.h"
#include "LGATimeline.h"

ULGATask_PlayTimeline::ULGATask_PlayTimeline()
	: PlayRate(1.f)
	, SectionPlayRate(1.0f), SectionPlayRateStart(0), SectionPlayRateEnd(0), SectionPlayRateClamp(false),
	Timeline(nullptr)
	, CurrentTime(0.f)
	, bPaused(false)
	, bCompleted(false)
{
	bTickingTask = true;
}

ULGATask_PlayTimeline* ULGATask_PlayTimeline::PlayTimeline(UGameplayAbility* OwningAbility, const FName TaskInstanceName,
	ULGATimeline* InTimeline, float PlayRate, const float SyncPoint, float StartTimeSeconds, FName InPreviousTimelineName)
{
	if (!InTimeline)
	{
		UE_LOG(LogLegoAbility, Error, TEXT("Ability[%s] Timeline is None"), *OwningAbility->GetName());
		return nullptr;
	}

	if (ULegoAbility* LegoAbility = Cast<ULegoAbility>(OwningAbility))
	{
		if (!LegoAbility->LockScopeTimeline())
		{
			UE_LOG(LogLegoAbility, Warning, TEXT("Playing Ability[%s] Timeline[%s] failed to get lock!"), 
				*OwningAbility->GetName(), *InTimeline->GetName());
			return nullptr;
		}

		if (ULGATask_PlayTimeline* Task = LegoAbility->GetPlayTimelineTask())
		{
			Task->CancelTimeline();
			Task->EndTask();
		}

		LegoAbility->ReleaseScopeTimeline();
	}

	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(PlayRate);

	if (const FLGATimelineBlendSetting* BlendSetting = InTimeline->GetDyanamicBlendSetting(InPreviousTimelineName))
	{
		StartTimeSeconds = BlendSetting->StartTimeSeconds;
	}

	ULGATask_PlayTimeline* MyObj = NewAbilityTask<ULGATask_PlayTimeline>(OwningAbility, TaskInstanceName);
	MyObj->Timeline = InTimeline;
	MyObj->PlayRate = PlayRate;
	MyObj->AddSyncPoint(SyncPoint);
	MyObj->CurrentTime = StartTimeSeconds >= 0.f ? StartTimeSeconds : InTimeline->StartTimeSeconds;
	MyObj->PreviousTimelineName = InPreviousTimelineName;

	return MyObj;
}

#if WITH_EDITOR
FString ULGATask_PlayTimeline::GetNetModeString() const
{
	FString Prefix;
	if (UWorld* World = Ability->GetWorld())
	{
		if (World->WorldType == EWorldType::PIE)
		{
			switch (World->GetNetMode())
			{
			case NM_Client:
				// GPlayInEditorID 0 is always the server, so 1 will be first client.
				// You want to keep this logic in sync with GeneratePIEViewportWindowTitle and UpdatePlayInEditorWorldDebugString
				Prefix = FString::Printf(TEXT("Client %d: "),  UE::GetPlayInEditorID());
				break;
			case NM_DedicatedServer:
			case NM_ListenServer:
				Prefix = FString::Printf(TEXT("Server: "));
				break;
			case NM_Standalone:
				break;
			}
		}
	}

	return Prefix;
}
#endif

void ULGATask_PlayTimeline::Activate()
{
	if (Timeline)
	{
#if WITH_EDITOR
		UE_LOG(LogLegoAbility, Verbose, TEXT("%sAbility[%s] Timeline[%s] is started"), *GetNetModeString(),
			*Ability->GetName(), *Timeline->GetName());
#else
		UE_LOG(LogLegoAbility, Verbose, TEXT("Ability[%s] Timeline[%s] is started"), *Ability->GetName(), *Timeline->GetName());
#endif

		for (FLGAActionEvent& Action : Timeline->Actions)
		{
			if (Action.Action)
			{
				Action.Action->SetLoopAction(
					FMath::IsNearlyZero(Action.GetStartTime()) && FMath::IsNearlyEqual(Action.GetEndTime(),
						Timeline->GetPlayLength()));

				Action.Action->OnTimelineBegin();
			}
		}


		// Trigger actions that ignore initial skip
		if (CurrentTime > 0.f)
		{
			for (FLGAActionEvent& ActionEvent : Timeline->Actions)
			{
				if (ActionEvent.GetStartTime() <= CurrentTime && ActionEvent.Action && ActionEvent.Action->IsSingleFrame() && ActionEvent.Action->IsIgnoreInitialSkip())
				{
					if (!ActionEvent.Action->CanActivateAction())
					{
						continue;
					}

					// activate action
					ActionEvent.Action->BeginAction(CurrentTime - ActionEvent.StartTime, ActionEvent.Duration, 0.f);
				}
			}
		}
	}
	else
	{
		EndTask();
	}
}

void ULGATask_PlayTimeline::TickTask(const float DeltaTime)
{
	if (bPaused)
	{
		return;
	}

	float Step = Timeline->GetOriginalStep(CurrentTime, DeltaTime * PlayRate);
	float FinalStep = 0.0f;
	if (SectionPlayRateEnd > 0.0f && CurrentTime >= SectionPlayRateStart && CurrentTime <= SectionPlayRateEnd)
	{
		constexpr float FPSStep = 1.0f / 60.0f;
		float SubStep = 0.0f;
		while (true)
		{
			float S;
			if (CurrentTime + SubStep > SectionPlayRateEnd)
			{
				if (SectionPlayRateClamp)
				{
					FinalStep = SectionPlayRateEnd - CurrentTime;
				}
				else
				{
					FinalStep += Step;
				}
				SectionPlayRateStart = 0.0f;
				SectionPlayRateEnd = 0.0f;
				break;
			}
			if (SectionPlayRate >= 1.0f)
			{
				S = FPSStep;
			}
			else
			{
				S = FPSStep * SectionPlayRate;
			}
			SubStep += S;
			const float ScaledStep = S / SectionPlayRate;
				
			if (Step <= ScaledStep)
			{
				FinalStep += SectionPlayRate * Step;
				break;
			}
			Step -= ScaledStep;
			FinalStep += S;
		}
	}
	else
	{
		FinalStep = Step;
	}
	PendingSteps.Emplace(FinalStep, false);
	HandlePendingStep();
}

void ULGATask_PlayTimeline::AdvanceStep(const float LastTime, const float CurTime, const bool bSkip)
{
	// Start new action
	for (int32 i = 0; i < Timeline->Actions.Num(); ++i)
	{
		FLGAActionEvent& ActionEvent = Timeline->Actions[i];

		if (ActionEvent.Action->IsSingleFrame())
		{
			if ((ActionEvent.StartTime > LastTime && ActionEvent.StartTime <= CurTime) || (ActionEvent.StartTime <= 0.f &&
				LastTime == 0.f))
			{
				if (!ActionEvent.Action)
				{
					continue;
				}

				if (!ActionEvent.Action->CanActivateAction())
				{
					continue;
				}

				// activate action
				ActionEvent.Action->BeginAction(CurTime - ActionEvent.StartTime, ActionEvent.Duration, 0.f);

				if (!IsActive())
				{
					return;
				}
			}
		}
		else if (FMath::Max(ActionEvent.StartTime, LastTime) < FMath::Min(ActionEvent.GetEndTime(), CurTime))
		{
			if (ActiveActionEvents.Contains(&ActionEvent))
			{
				continue;
			}

			if (!ActionEvent.Action)
			{
				continue;
			}

			if (!ActionEvent.Action->CanActivateAction())
			{
				continue;
			}

			// add ActionEvent to ActiveActionEvents before call BeginAction because BeginAction may cause this play timeline task ended
			{
				// insert ActionEvent to ActiveActionEvents and keep it sorted by end time
				int32 InsertIndex = 0;
				float EndTime = ActionEvent.GetEndTime();
				for (const FLGAActionEvent* Event : ActiveActionEvents)
				{
					if (EndTime < Event->GetEndTime())
					{
						break;
					}
					InsertIndex++;
				}
				ActiveActionEvents.Insert(&ActionEvent, InsertIndex);
			}

			// activate action
			ActionEvent.Action->BeginAction(CurTime - ActionEvent.StartTime, ActionEvent.Duration, FMath::Clamp(LastTime - ActionEvent.StartTime, 0.f, ActionEvent.Duration));

			if (!IsActive())
			{
				return;
			}
		}
	}

	// Update active actions
	for (int32 i = 0; i < ActiveActionEvents.Num();)
	{
		FLGAActionEvent* ActionEvent = ActiveActionEvents[i];
		if (CurTime >= ActionEvent->GetEndTime())
		{
			// if the action was skipped, we should notify the action.
			if (bSkip)
			{
				ActionEvent->Action->SkipAction(CurTime - ActionEvent->StartTime, ActionEvent->Duration);
			}

			if (!Timeline->bLooping || !ActionEvent->Action->IsLoopAction())
			{
				// remove ActionEvent from ActiveActionEvents before call EndAction becase EndAction may cause this play timeline task ended
				ActiveActionEvents.RemoveAt(i);
				ActionEvent->Action->EndAction(false, true);
			}
			else
			{
				++i;
			}
		}
		else
		{
			if (bSkip)
			{
				ActionEvent->Action->SkipAction(CurTime - ActionEvent->StartTime, ActionEvent->Duration);
			}
			else
			{
				ActionEvent->Action->TickAction(CurTime - ActionEvent->StartTime, ActionEvent->Duration,
					CurTime - LastTime);
			}
			++i;
		}

		if (!IsActive())
		{
			return;
		}
	}

	// Complete this task
	if (CurTime >= Timeline->GetPlayLength())
	{
		// Complete all no loop active actions
		for (int32 i = 0; i < ActiveActionEvents.Num();)
		{
			if (!Timeline->bLooping || !ActiveActionEvents[i]->Action->IsLoopAction())
			{
				FLGAActionEvent* ActionEvent = ActiveActionEvents[i];

				ActiveActionEvents.RemoveAt(i);
				ActionEvent->Action->EndAction(false, true);
			}
			else
			{
				++i;
			}
		}

		if (Timeline->bLooping)
		{
			CurrentTime = 0.f;
		}
		else
		{
			bCompleted = true;
			OnTimelineEnded();
		}
	}
}

void ULGATask_PlayTimeline::OnTimelineEnded()
{
	for (FLGAActionEvent& ActionEvent : Timeline->Actions)
	{
		if (ActionEvent.Action)
		{
			ActionEvent.Action->OnTimelineEnd(true);
		}
	}

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnCompleted.Broadcast();
	}

	EndTask();
}

void ULGATask_PlayTimeline::HandlePendingStep()
{
	while (!PendingSteps.IsEmpty())
	{
		TPair<float, bool> StepInfo = PendingSteps[0];
		PendingSteps.RemoveAt(0, 1, false);

		float LastTime = CurrentTime;
		CurrentTime += StepInfo.Key;
		AdvanceStep(LastTime, CurrentTime, StepInfo.Value);
	}
}

void ULGATask_PlayTimeline::OnDestroy(const bool bAbilityFinished)
{
	while (!ActiveActionEvents.IsEmpty())
	{
		FLGAActionEvent* ActionEvent = ActiveActionEvents[0];
		ActiveActionEvents.RemoveAt(0);

		ActionEvent->Action->EndAction(bAbilityFinished, false);
	}

	if (!bCompleted)
	{
		for (FLGAActionEvent& ActionEvent : Timeline->Actions)
		{
			if (ActionEvent.Action)
			{
				ActionEvent.Action->OnTimelineEnd(false);
			}
		}

		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnCancelled.Broadcast();
		}
	}

	// Trigger actions that is guaranteed to trigger
	for (FLGAActionEvent& ActionEvent : Timeline->Actions)
	{
		if (ActionEvent.GetStartTime() > CurrentTime && ActionEvent.Action && ActionEvent.Action->IsSingleFrame() && ActionEvent.Action->IsGuaranteedToBeTriggered())
		{
			if (!ActionEvent.Action->CanActivateAction())
			{
				continue;
			}

			// activate action
			ActionEvent.Action->BeginAction(CurrentTime - ActionEvent.StartTime, ActionEvent.Duration, 0.f);
		}
	}

	Super::OnDestroy(bAbilityFinished);


#if WITH_EDITOR
	UE_LOG(LogLegoAbility, Verbose, TEXT("%sAbility[%s] Timeline[%s] is ended"), *GetNetModeString(),
		*Ability->GetName(), *GetNameSafe(Timeline));
#else
	UE_LOG(LogLegoAbility, Verbose, TEXT("Ability[%s] Timeline[%s] is ended"), *Ability->GetName(), *GetNameSafe(Timeline));
#endif
}

void ULGATask_PlayTimeline::SetPlayRate(float InPlayRate)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(InPlayRate);

	if (PlayRate != InPlayRate)
	{
		for (FLGAActionEvent* ActionEvent : ActiveActionEvents)
		{
			ActionEvent->Action->OnPlayRateChanged(PlayRate, InPlayRate);
		}
	}

	PlayRate = InPlayRate;
}

void ULGATask_PlayTimeline::SetSectionPlayRate(const float InPlayRate, const float StartTime, const float EndTime, const bool bSectionPlayRateClamp)
{
	if (InPlayRate == 0.0f)
	{
		SectionPlayRate = 0.00001f;
	}
	else
	{
		SectionPlayRate = InPlayRate;
	}
	SectionPlayRateStart = StartTime;
	SectionPlayRateEnd = EndTime;
	SectionPlayRateClamp = bSectionPlayRateClamp;
}

void ULGATask_PlayTimeline::CancelTimeline()
{
	while (!ActiveActionEvents.IsEmpty())
	{
		FLGAActionEvent* ActionEvent = ActiveActionEvents[0];
		ActiveActionEvents.RemoveAt(0);

		ActionEvent->Action->EndAction(false, false);
	}
}

void ULGATask_PlayTimeline::SkipSection(float Duration)
{
	if (Duration > 0.f)
	{
		PendingSteps.Emplace(Duration, true);
	}
}

bool ULGATask_PlayTimeline::NextSyncPoint(float& OutPoint)
{
	if (SyncPoints.IsEmpty())
	{
		return false;
	}

	OutPoint = SyncPoints[0];
	SyncPoints.RemoveAt(0);

	return true;
}

const FLGATimelineBlendSetting* ULGATask_PlayTimeline::GetDynamicTimelineBlendSetting()
{
	if (const FLGATimelineBlendSetting* BlendSetting = Timeline->GetDyanamicBlendSetting(PreviousTimelineName))
	{
		return BlendSetting;
	}

	return nullptr;
}
