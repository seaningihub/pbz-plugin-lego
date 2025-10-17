#include "Tasks/AbilityTask_PlayMontageAnadWaitPlus.h"

#include "AbilitySystemGlobals.h"
#include "Interface/AdvancedAnimPlayerActorInterface.h"

UAbilityTask_PlayMontageAnadWaitPlus::UAbilityTask_PlayMontageAnadWaitPlus(): DisableSliding(false)
{
}

void UAbilityTask_PlayMontageAnadWaitPlus::Activate()
{
	if (AActor* Actor = GetAvatarActor())
	{
		if (Actor->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()))
		{
			IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(Actor, DisableSliding);
		}
	}

	Super::Activate();
}

void UAbilityTask_PlayMontageAnadWaitPlus::ExternalCancel()
{
	if (DisableSliding)
	{
		if (AActor* Actor = GetAvatarActor())
		{
			if (Actor->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()))
			{
				IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(Actor, false);
			}
		}
	}

	Super::ExternalCancel();
}

void UAbilityTask_PlayMontageAnadWaitPlus::OnDestroy(const bool bInOwnerFinished)
{
	if (DisableSliding)
	{
		if (AActor* Actor = GetAvatarActor())
		{
			if (Actor->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()))
			{
				IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(Actor, false);
			}
		}
	}

	Super::OnDestroy(bInOwnerFinished);
}

UAbilityTask_PlayMontageAnadWaitPlus* UAbilityTask_PlayMontageAnadWaitPlus::CreatePlayMontageAndWaitPlusProxy(
	UGameplayAbility* OwningAbility, const FName TaskInstanceName, UAnimMontage* Montage, float PlayRate,
	const FName StartSect, const bool StopWhenAbilityEnds, const float RootMotionTranslationScale,
	const float StartTime,
	const bool AllowInterruptAfterBlendOut, const bool DisableSliding)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(PlayRate);

	UAbilityTask_PlayMontageAnadWaitPlus* MyObj = NewAbilityTask<UAbilityTask_PlayMontageAnadWaitPlus>(
		OwningAbility, TaskInstanceName);
	MyObj->MontageToPlay = Montage;
	MyObj->Rate = PlayRate;
	MyObj->StartSection = StartSect;
	MyObj->AnimRootMotionTranslationScale = RootMotionTranslationScale;
	MyObj->bStopWhenAbilityEnds = StopWhenAbilityEnds;
	MyObj->bAllowInterruptAfterBlendOut = AllowInterruptAfterBlendOut;
	MyObj->StartTimeSeconds = StartTime;
	MyObj->DisableSliding = DisableSliding;

	return MyObj;
}
