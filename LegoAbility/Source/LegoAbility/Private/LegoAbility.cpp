// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbility.h"
#include "Actions/LGAAction.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LGATask_PlayTimeline.h"
#include "LGATimeline.h"
#include "Net/UnrealNetwork.h"
#include "LegoAbilityBlueprintLibrary.h"
#include "Engine/InputDelegateBinding.h"
#include "AbilitySystemComponent.h"
#include "Components/InputComponent.h"
#include "LegoAbilitySystemComponent.h"

void ULegoAbility::PostInitProperties()
{
	Super::PostInitProperties();

	if (ULegoAbilityBlueprintGeneratedClass* BGClass = Cast<ULegoAbilityBlueprintGeneratedClass>(GetClass()))
	{
		BGClass->InitializeAbility(this);
	}
}

FString ULegoAbility::GetDisplayName() const
{
	FString Result;
	GetName(Result);
	int32 UnderscoreIndex;

	// Chop off the variant (_A/B/C/D) from the Left side.
	if (Result.FindLastChar('_', UnderscoreIndex))
	{
		int32 UnderscoreSize = Result.Len() - UnderscoreIndex;

		static FString DefaultString(TEXT("Default__"));
		if (Result.Find(DefaultString) >= 0)
		{
			int32 StringSize = Result.Len() - UnderscoreSize - DefaultString.Len();
			Result = Result.Mid(DefaultString.Len(), StringSize);
		}
		else
		{
			Result = Result.LeftChop(UnderscoreSize);
		}
	}

	return Result;
}

ULGATimeline* ULegoAbility::GetTimelineByName(FName TimelineName) const
{
	for (ULGATimeline* Timeline : Timelines)
	{
		if (Timeline && Timeline->GetFName() == TimelineName)
		{
			return Timeline;
		}
	}

	return nullptr;
}

ULGATimeline* ULegoAbility::GetTimelineByIndex(const int Index) const
{
	if (Timelines.IsValidIndex(Index))
	{
		return Timelines[Index];
	}

	return nullptr;
}

ULGAAction* ULegoAbility::GetActionByName(FName TimelineName, FName ActionName) const
{
	if (ULGATimeline* Timeline = GetTimelineByName(TimelineName))
	{
		if (FLGAActionEvent* Event = Timeline->GetActionEventByName(ActionName))
		{
			return Event->Action;
		}
	}

	return nullptr;
}

TArray<ULGAAction*> ULegoAbility::GetActionsByTag(TSubclassOf<ULGAAction> ActionClass, FGameplayTagRequirements ActionTagReqs)
{
	TArray<ULGAAction*> Actions;
	for (ULGATimeline* Timeline : Timelines)
	{
		for (const FLGAActionEvent& Event : Timeline->Actions)
		{
			ULGAAction* Action = Event.Action;
			if (ActionClass && !Action->IsA(ActionClass))
			{
				continue;
			}

			if (ActionTagReqs.RequirementsMet(Action->GetActionTags()))
			{
				Actions.Add(Action);
			}
		}
	}

	return Actions;
}


ULGATask_PlayTimeline* ULegoAbility::GetPlayTimelineTask() const
{
	for (UGameplayTask* ActiveTask : ActiveTasks)
	{
		if (ULGATask_PlayTimeline* PlayTimelineTask = Cast<ULGATask_PlayTimeline>(ActiveTask))
		{
			return PlayTimelineTask;
		}
	}

	return nullptr;
}

void ULegoAbility::ExecuteAction(ULGAAction_Executable* Action, FLGAActionExecutionContextHandle Context)
{
	if (Action && Action->CanActivateAction() && !Action->IsSimulatedAction())
	{
		Action->ExecuteAction(Context);
	}
}

TArray<FName> ULegoAbility::GetAllTimelineNames()
{
	TArray<FName> TimelineNames;
	if(ULegoAbilityBlueprintGeneratedClass* AbilityClass = Cast<ULegoAbilityBlueprintGeneratedClass>(GetClass()))
	{
		TArray<const ULGATimeline*> AllTimelines = AbilityClass->GetAllTimelines();
		for (const ULGATimeline* Timeline : AllTimelines)
		{
			TimelineNames.Add(FName(*Timeline->GetName()));
		}
	}

	TimelineNames.Sort([](const FName& A, const FName& B)
	{
		return A.ToString() < B.ToString();
	});
	TimelineNames.Insert(NAME_None, 0);
	
	return MoveTemp(TimelineNames);
}

void ULegoAbility::PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData /*= nullptr*/)
{
	ULegoAbilitySystemComponent* LegoASC = Cast<ULegoAbilitySystemComponent>(ActorInfo->AbilitySystemComponent.Get());
	if (LegoASC)
	{
		LegoASC->CurrentPreActiveAbility = this;
	}

	Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate, TriggerEventData);
	
	if (LegoASC)
	{
		LegoASC->CurrentPreActiveAbility = nullptr;
	}
}

void ULegoAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	// Auto play timeline
	for (ULGATimeline* Timeline : Timelines)
	{
		if (Timeline->bAutoPlay)
		{
			PlayTimeline(Timeline, 1.f, 0.f, Timeline->StartTimeSeconds, CanceledTimelineName);
			break;
		}
	}

	// Register gameplay event actions
	for (const FLGAEventAction& EA : ExecuteOnGameplayEvent)
	{
		if (EA.EventTag.IsValid() && EA.ExecuteAction)
		{
			EventTagsBound.AddTag(EA.EventTag);
		}
	}
	if (!EventTagsBound.IsEmpty())
	{
		EventDelegateHandle = GetAbilitySystemComponentFromActorInfo_Checked()->AddGameplayEventTagContainerDelegate(EventTagsBound, FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &ULegoAbility::OnGameplayEvent));
	}
	
	// Call parent
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	// Execute startup actions
	for (ULGAAction_Executable* Action : ExecuteOnActivate)
	{
		ExecuteAction(Action, ULegoAbilityBlueprintLibrary::ActionContextFromActor(GetAvatarActorFromActorInfo()));
	}

	if (UInputDelegateBinding::SupportsInputDelegate(GetClass()) && IsValid(ActorInfo->OwnerActor->InputComponent))
	{
		UInputDelegateBinding::BindInputDelegates(GetClass(), ActorInfo->OwnerActor->InputComponent, this);
	}

	bIsInDynamicBlendOut = false;
}

void ULegoAbility::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	if (ULGATask_PlayTimeline* PlayTimelineTask = GetPlayTimelineTask())
	{
		if (ULGATimeline* PlayingTimeline = PlayTimelineTask->GetTimeline())
		{
			ULegoAbilitySystemComponent* LegoASC = Cast<ULegoAbilitySystemComponent>(ActorInfo->AbilitySystemComponent.Get());
			if (LegoASC && LegoASC->CurrentPreActiveAbility.IsValid())
			{
				ULegoAbility* NextActivatedAbility = LegoASC->CurrentPreActiveAbility.Get();
				NextActivatedAbility->CanceledTimelineName = FName(FString::Printf(TEXT("%s.%s"), *GetClass()->GetName(), *PlayingTimeline->GetName()));
	
				for (ULGATimeline* Timeline : NextActivatedAbility->Timelines)
				{
					if (Timeline->bAutoPlay && Timeline->GetDyanamicBlendSetting(NextActivatedAbility->CanceledTimelineName))
					{
						bIsInDynamicBlendOut = true;
					}
				}
			}
		}
	}
	
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

void ULegoAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	if (IsValid(ActorInfo->OwnerActor->InputComponent))
	{
		ActorInfo->OwnerActor->InputComponent->ClearBindingsForObject(this);
	}

	// Unregister event actions
	if (EventDelegateHandle.IsValid())
	{
		GetAbilitySystemComponentFromActorInfo_Checked()->RemoveGameplayEventTagContainerDelegate(EventTagsBound, EventDelegateHandle);
		EventDelegateHandle.Reset();
	}

	// Execute end actions
	for (ULGAAction_Executable* Action : ExecuteOnEnd)
	{
		ExecuteAction(Action, ULegoAbilityBlueprintLibrary::ActionContextFromActor(GetAvatarActorFromActorInfo()));
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	CanceledTimelineName = NAME_None;
}

void ULegoAbility::OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Data)
{
	for (const FLGAEventAction& EA : ExecuteOnGameplayEvent)
	{
		if (EA.EventTag == EventTag && EA.ExecuteAction)
		{
			ExecuteAction(EA.ExecuteAction, ULegoAbilityBlueprintLibrary::ActionContextFromGameplayEvent(Data ? *Data : FGameplayEventData()));
		}
	}
}

void ULegoAbility::InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	for (ULGAAction_Executable* Action : ExecuteOnInputPressed)
	{
		ExecuteAction(Action, ULegoAbilityBlueprintLibrary::ActionContextFromActor(GetAvatarActorFromActorInfo()));
	}
}

void ULegoAbility::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	for (ULGAAction_Executable* Action : ExecuteOnInputReleased)
	{
		ExecuteAction(Action, ULegoAbilityBlueprintLibrary::ActionContextFromActor(GetAvatarActorFromActorInfo()));
	}
}

TArray<ULGAAction*> ULegoAbility::GetActionsNeedToReplicate() const
{
	TArray<ULGAAction*> Actions;
	for (ULGATimeline* Timeline : Timelines)
	{
		ForEachObjectWithOuter(Timeline, [&Actions](UObject* Object)
		{
			ULGAAction* Action = Cast<ULGAAction>(Object);
			if (Action && Action->ShouldReplicateToSimulation())
			{
				Actions.Add(Action);
			}
		});
	}
	return Actions;
}

bool ULegoAbility::LockScopeTimeline()
{
	if (!bScopeLockTimeline)
	{
		bScopeLockTimeline = true;
		return true;
	}

	return false;
}

void ULegoAbility::ReleaseScopeTimeline()
{
	bScopeLockTimeline = false;
}

void ULegoAbility::PlayTimeline(ULGATimeline* Timeline, float PlayRate, float SyncPoint /*= 0.f*/, float StartTimeSeconds /*= 0.f*/, FName PreviewsTimlineName)
{
	if (!Timeline)
	{
		return;
	}

	FName TaskInstanceName;
	ULGATask_PlayTimeline* Task = ULGATask_PlayTimeline::PlayTimeline(this, TaskInstanceName, Timeline, PlayRate, SyncPoint, StartTimeSeconds, PreviewsTimlineName);
	if (!Task)
	{
		return;
	}

	if (!Timeline->bLooping && Timeline->bStopAbility)
	{
		Task->OnCompleted.AddDynamic(this, &ULegoAbility::K2_EndAbility);
	}
	Task->ReadyForActivation();
}

void ULegoAbility::PlayTimelineByName(FName TimelineName, float PlayRate /*= 1.f*/, float SyncPoint/* = 0.f*/, float StartTimeSeconds /*= 0.f*/)
{
	ULGATimeline* Timeline = GetTimelineByName(TimelineName);
	if (Timeline)
	{
		PlayTimeline(Timeline, PlayRate, SyncPoint, StartTimeSeconds);
	}
}

void ULegoAbility::EndTimeline(ULGATimeline* Timeline)
{
	if (ULGATask_PlayTimeline* PlayTimelineTask = GetPlayTimelineTask())
	{
		if (!Timeline || PlayTimelineTask->GetTimeline() == Timeline)
		{
			PlayTimelineTask->EndTask();
		}
	}
}

void ULegoAbility::EndTimelineByName(FName TimelineName)
{
	ULGATimeline* Timeline = GetTimelineByName(TimelineName);
	if (Timeline)
	{
		EndTimeline(Timeline);
	}
}

bool ULegoAbility::IsPlayingTimeline(ULGATimeline* Timeline) const
{
	if (ULGATask_PlayTimeline* PlayTimelineTask = GetPlayTimelineTask())
	{
		return Timeline == nullptr ? true : (PlayTimelineTask->GetTimeline() == Timeline);
	}

	return false;
}

bool ULegoAbility::IsPlayingAnyTimeline(TArray<ULGATimeline*> InTimelines)
{
	if (ULGATask_PlayTimeline* PlayTimelineTask = GetPlayTimelineTask())
	{
		return InTimelines.Contains(PlayTimelineTask->GetTimeline());
	}
	
	return false;
}

float ULegoAbility::GetCurveValue(FName CurveName, float DefaultValue /*= 0*/)
{
	if (ULGATask_PlayTimeline* PlayTimelineTask = GetPlayTimelineTask())
	{
		if (ULGATimeline* PlayingTimeline = PlayTimelineTask->GetTimeline())
		{
			if (FFloatCurve * FloatCurve = PlayingTimeline->GetCurveByName(CurveName))
			{
				return FloatCurve->Evaluate(PlayTimelineTask->GetCurrentTime());
			}
		}
	}

	return DefaultValue;
}
