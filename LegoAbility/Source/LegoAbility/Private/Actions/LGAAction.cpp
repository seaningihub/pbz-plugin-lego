// Copyright S-Game, Inc. All Rights Reserved.

#include "Actions/LGAAction.h"
#include "LegoAbility.h"
#include "LGATimeline.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemComponent.h"
#include "Engine/InputDelegateBinding.h"
#include "AbilitySystemGlobals.h"
#include "Components/InputComponent.h"
#include "Engine/BlueprintGeneratedClass.h"

#define LOCTEXT_NAMESPACE "LegoAbilityAction"

ULGAAction::ULGAAction()
	: NetExecutionPolicy(EGameplayActionNetExecutionPolicy::Always)
{
#if WITH_EDITORONLY_DATA
	bSupportPreview = false;
	ActionColor = FColor(255, 200, 200, 255);
#endif // WITH_EDITORONLY_DATA

	auto ImplementedInBlueprint = [](const UFunction* Func) -> bool
	{
		return Func && ensure(Func->GetOuter())
			&& (Func->GetOuter()->IsA(UBlueprintGeneratedClass::StaticClass()));
	};
	{
		static FName FuncName = FName(TEXT("K2_CanActivateAction"));
		UFunction* CanActivateFunction = GetClass()->FindFunctionByName(FuncName);
		bHasBlueprintCanActivate = ImplementedInBlueprint(CanActivateFunction);
	}
}

ULGAAction::~ULGAAction()
{

}

void ULGAAction::OnTimelineBegin()
{
	Received_TimelineBegin();
}

void ULGAAction::OnTimelineEnd(bool bTimelineFinished)
{
	Received_TimelineEnd(bTimelineFinished);
}

void ULGAAction::ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime)
{
	Received_ActionBegin(ElapsedTime, TotalDuration, BeginTime);

	if (UInputDelegateBinding::SupportsInputDelegate(GetClass()) && GetAvatarActor() && IsValid(GetAvatarActor()->InputComponent))
	{
		UInputDelegateBinding::BindInputDelegates(GetClass(), GetAvatarActor()->InputComponent, this);
	}
}

void ULGAAction::ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime)
{
	Received_ActionTick(ElapsedTime, TotalDuration, DeltaTime);
}

void ULGAAction::ActionSkip(float ElapsedTime, float TotalDuration)
{
	Received_ActionSkip(ElapsedTime, TotalDuration);
}

void ULGAAction::ActionEnd(bool bAbilityFinished, bool bActionFinished)
{
	Received_ActionEnd(bAbilityFinished, bActionFinished);

	if (GetAvatarActor() && IsValid(GetAvatarActor()->InputComponent))
	{
		GetAvatarActor()->InputComponent->ClearBindingsForObject(this);
	}
}

FString ULGAAction::GetActionName_Implementation() const
{
	FString ActionName;

#if WITH_EDITORONLY_DATA
	if (UObject* ClassGeneratedBy = GetClass()->ClassGeneratedBy)
	{
		// GeneratedBy will be valid for blueprint types and gives a clean name without a suffix
		ActionName = ClassGeneratedBy->GetName();
	}
	else
#endif
	{
		// Native notify classes are clean without a suffix otherwise
		ActionName = GetClass()->GetName();
	}

	return ActionName;
}


bool ULGAAction::CanActivateAction() const
{
	if (!CheckNetExecutionPolicy())
	{
		return false;
	}

	//Check tag requirements
	{
		FGameplayTagContainer OwnerTags;
		GetAbilitySystemComponent()->GetOwnedGameplayTags(OwnerTags);

		if (!ActivationRequirements.RequirementsMet(OwnerTags))
		{
			return false;
		}
	}

	//Call blueprint check function
	if (bHasBlueprintCanActivate && !K2_CanActivateAction())
	{
		return false;
	}

	return true;
}

void ULGAAction::BeginAction(float ElapsedTime, float TotalDuration, float BeginTime)
{
	ULegoAbility* Ability = GetAbility();
	if (!Ability)
	{
		return;
	}

	UAbilitySystemComponent* ASC = Ability->GetAbilitySystemComponentFromActorInfo();
	if (!ASC)
	{
		return;
	}

	if (bIsSingleFrame)
	{
		TotalDuration = 0.f;
	}

	switch (NetExecutionPolicy)
	{
	case EGameplayActionNetExecutionPolicy::Always:
		InternalActivateAction(ElapsedTime, TotalDuration, BeginTime);
		break;
	case EGameplayActionNetExecutionPolicy::LocalOnly:
		if (IsLocallyControlled())
		{
			InternalActivateAction(ElapsedTime, TotalDuration, BeginTime);
		}
		break;
	case EGameplayActionNetExecutionPolicy::ServerOnly:
		if (HasAuthority())
		{
			InternalActivateAction(ElapsedTime, TotalDuration, BeginTime);
		}
		break;
	}
}

void ULGAAction::TickAction(float ElapsedTime, float TotalDuration, float DeltaTime)
{
	ActionTick(ElapsedTime, TotalDuration, DeltaTime);
}

void ULGAAction::SkipAction(float ElapsedTime, float TotalDuration)
{
	ActionSkip(ElapsedTime, TotalDuration);
}

void ULGAAction::EndAction(bool bAbilityFinished, bool bActionFinished)
{
	InternalEndAction(bAbilityFinished, bActionFinished);
}


bool ULGAAction::InternalActivateAction(float ElapsedTime, float TotalDuration, float BeginTime)
{
	ActionBegin(ElapsedTime, TotalDuration, BeginTime);

	if (HasAuthority() && bReplicateToSimulation)
	{
		/*if (URORAbilitySystemComponent* ASC = GetASC())
		{
			if (TotalDuration > 0.f)
			{
				ASC->AddActiveSimulateAction(this, TotalDuration, ActivationData);
			}
			else
			{
				ASC->NetMulticast_InvokeSimulationAction(this, ActivationData);
			}
		}*/
	}

	return true;
}

void ULGAAction::InternalEndAction(bool bAbilityFinished, bool bActionFinished)
{
	ActionEnd(bAbilityFinished, bActionFinished);

	/*if (HasAuthority() && bReplicateToSimulation)
	{
		if (URORAbilitySystemComponent* ASC = GetASC())
		{
			ASC->RemoveActiveSimulateAction(this);
		}
	}*/
}


AActor* ULGAAction::GetAvatarActor() const
{
	if (ULegoAbility* Ability = GetAbility())
	{
		return Ability->GetAvatarActorFromActorInfo();
	}

	return nullptr;
}

UAbilitySystemComponent* ULGAAction::GetAbilitySystemComponent() const
{
	if (ULegoAbility* Ability = GetAbility())
	{
		return Ability->GetAbilitySystemComponentFromActorInfo();
	}

	return nullptr;
}

ULegoAbility* ULGAAction::GetAbility() const
{
	return GetTypedOuter<ULegoAbility>();
}

ULGATimeline* ULGAAction::GetTimeline() const
{
	return GetTypedOuter<ULGATimeline>();
}

FLGAActionEvent* ULGAAction::GetActionEvent() const
{
	FLGAActionEvent* ActionEvent = nullptr;
	if (ULGATimeline* Timeline = GetTimeline())
	{
		ActionEvent = Timeline->GetActionEventByAction(this);
	}

	return ActionEvent;
}

void ULGAAction::GetActionEvent(FLGAActionEvent& Event) const
{
	if (ULGATimeline* Timeline = GetTimeline())
	{
		Event = *Timeline->GetActionEventByAction(this);
	}
}

bool ULGAAction::IsSimulatedAction() const
{
	if (AActor* OuterActor = GetAvatarActor())
	{
		return OuterActor->GetLocalRole() == ENetRole::ROLE_SimulatedProxy;
	}
	return true;
}

bool ULGAAction::IsLocallyControlled() const
{
	if (ULegoAbility* Ability = GetAbility())
	{
		return Ability->IsLocallyControlled();
	}

	return false;
}

bool ULGAAction::HasAuthority() const
{
	if (ULegoAbility* Ability = GetAbility())
	{
		return Ability->K2_HasAuthority();
	}

	return false;
}

UWorld* ULGAAction::GetWorld() const
{
	if (ULegoAbility* Ability = GetAbility())
	{
		return Ability->GetWorld();
	}

#if WITH_EDITOR
	else if (ULGATimeline* Timeline = GetTimeline())
	{
		return Timeline->PreviewWorld;
	}
	else if (PreviewWorld)
	{
		return PreviewWorld;
	}
#endif

	return nullptr;
}

bool ULGAAction::CheckNetExecutionPolicy() const
{
	switch (NetExecutionPolicy)
	{
	case EGameplayActionNetExecutionPolicy::LocalOnly:
		return IsLocallyControlled();
	case EGameplayActionNetExecutionPolicy::ServerOnly:
		return HasAuthority();
	default:
		return true;
	}
}

#if WITH_EDITOR

bool ULGAAction::CanChangeDuration() const
{
	return true;
}

void ULGAAction::OnDurationChanged(float NewDuration)
{

}

void ULGAAction::OnSectionDurationChanged()
{

}

bool ULGAAction::InputWidgetDelta(AActor* PreviewActor, FViewport* InViewport, EAxisList::Type CurrentAxis, const FVector& Drag, const FRotator& Rot, const FVector& Scale)
{
	bool Result = Received_InputWidgetDelta(PreviewActor, Drag, Rot, Scale);

	return Result;
}

void ULGAAction::SetActionNodeDuration(float NewDuration)
{
	if (ULGATimeline* Timeline = Cast<ULGATimeline>(GetOuter()))
	{
		if (FLGAActionEvent* Event = Timeline->GetActionEventByAction(this))
		{
			Event->Duration = NewDuration;
		}
	}
}

float ULGAAction::GetMinimumDuration() const
{
	return 1.f/30.f;
}

bool ULGAAction::CanPreview(AActor* PreviewActor, ULGATimeline* PreviewTimeline)
{
	if (!bSupportPreview)
	{
		return false;
	}

	//Check tag requirements
	if(PreviewActor)
	{
		FGameplayTagContainer OwnerTags;
		UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(PreviewActor);
		if (ASC)
		{
			ASC->GetOwnedGameplayTags(OwnerTags);
			OwnerTags.AddTag(PreviewTimeline->PreviewWeapon);

			if (!ActivationRequirements.RequirementsMet(OwnerTags))
			{
				return false;
			}
		}
	}

	return true;
}

void ULGAAction::UpdateActualEventTime()
{
	if (ULGATimeline* Timeline = GetTimeline())
	{
		if (FLGAActionEvent* ActionEvent = GetActionEvent())
		{
			ActualStartTime = Timeline->GetScaledTimeStep(0, ActionEvent->GetStartTime());
			ActualEndTime = Timeline->GetScaledTimeStep(0, ActionEvent->GetEndTime());
			ActualDuration = ActualEndTime - ActualStartTime;
		}
	}
}

void ULGAAction::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, bIsSingleFrame))
	{
		if (ULGATimeline* Timeline = Cast<ULGATimeline>(GetOuter()))
		{
			if (FLGAActionEvent* Event = Timeline->GetActionEventByAction(this))
			{
				if (bIsSingleFrame)
				{
					Event->SetDuration(0.f);
				}
				else if (Event->Duration == 0.f)
				{
					Event->SetDuration(1 / 30.f);
				}
			}
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void ULGAAction::PostLoad()
{
	Super::PostLoad();
	
	UpdateActualEventTime();
}

#endif


#undef LOCTEXT_NAMESPACE