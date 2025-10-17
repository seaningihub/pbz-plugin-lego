// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGAAction.h"
#include "Animation/AnimationAsset.h"
#include "Animation/AnimMontage.h"
#include "LGAAction_PlayMontage_Base.generated.h"

/**
 * Ability Action to simply play a montage.
 */
UCLASS(Abstract, Blueprintable, meta = (DisplayName = "Play Montage Base"))
class LEGOABILITY_API ULGAAction_PlayMontage_Base : public ULGAAction
{
	GENERATED_BODY()

public:
	UAnimMontage* GetMontageToPlay() const;

	UFUNCTION(BlueprintNativeEvent)
	UAnimInstance* GetAnimInstance(AActor* PreviewActor);

	UFUNCTION()
	void OnMontageBlendOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnMontageCompleted(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnAbilityEnded(UGameplayAbility* Ability);

	ULGAAction_PlayMontage_Base();
	virtual void BeginDestroy() override;

	virtual void ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime) override;
	virtual void ActionSkip(float ElapsedTime, float TotalDuration) override;
	virtual void ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime) override;
	virtual void ActionEnd(bool bAbilityFinished, bool bActionFinished) override;

	virtual FString GetActionName_Implementation() const override;


#if WITH_EDITOR
	float GetPlayLength() const;
	
	virtual void BeginPreview(AActor* PreviewActor, float TotalDuration) override;
	virtual void SetPosition(AActor* PreviewActor, float Position, float TotalDuration) override;
	virtual void EndPreview(AActor* PreviewActor) override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	void OnObjectPropertyChanged(UObject* Object, FPropertyChangedEvent& PropChangedEvent);

	FTransform DefaultPreviewActorTransfrom;
#endif

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	FName TaskInstanceName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LegoAbility")
	class UAnimSequenceBase* Animation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LegoAbility")
	float PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LegoAbility")
	FName StartSection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LegoAbility")
	bool bStopWhenAbilityEnds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LegoAbility")
	bool bStopWhenActionEnds;

	// Actions On Event
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Trigger Actions", meta = (DisplayName = "On Blend Out"))
	class ULGAAction_Executable* OnBlendOutAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Trigger Actions", meta = (DisplayName = "On Complete"))
	class ULGAAction_Executable* OnCompletedAction;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bDebug;

protected:
	FAnimMontageInstance* GetCurrentMontageInstance();

	UPROPERTY(Transient)
	mutable UAnimMontage* DynamicMontage;
	int32 MontageInstanceID;
};