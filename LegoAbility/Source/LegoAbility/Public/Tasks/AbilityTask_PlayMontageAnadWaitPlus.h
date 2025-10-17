#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "AbilityTask_PlayMontageAnadWaitPlus.generated.h"

/**
 *
 */
UCLASS()
class LEGOABILITY_API UAbilityTask_PlayMontageAnadWaitPlus : public UAbilityTask_PlayMontageAndWait
{
	GENERATED_BODY()

public:
	UAbilityTask_PlayMontageAnadWaitPlus();

	virtual void Activate() override;
	virtual void ExternalCancel() override;
	virtual void OnDestroy(bool bInOwnerFinished) override;

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta = (DisplayName="PlayMontageAndWaitPlus",
		HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_PlayMontageAnadWaitPlus* CreatePlayMontageAndWaitPlusProxy(UGameplayAbility* OwningAbility,
		FName TaskInstanceName, UAnimMontage* Montage, float PlayRate = 1.f, FName StartSect = NAME_None,
		bool StopWhenAbilityEnds = true, float RootMotionTranslationScale = 1.f, float StartTime = 0.f,
		bool AllowInterruptAfterBlendOut = false, bool DisableSliding = true);

private:
	UPROPERTY()
	bool DisableSliding;
};
