// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGAAction.h"
#include "Animation/AnimationAsset.h"
#include "Animation/AnimMontage.h"
#include "LGAAction_PlayMontage.generated.h"

/**
 * Ability Action to simply play a montage.
 */
UCLASS(meta = (DisplayName = "Play Montage"))
class LEGOABILITY_API ULGAAction_PlayMontage : public ULGAAction
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMontageBlendOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnMontageCompleted(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnAbilityEnded(UGameplayAbility* Ability);

	ULGAAction_PlayMontage();
	virtual void BeginDestroy() override;

	virtual void ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime) override;
	virtual void ActionSkip(float ElapsedTime, float TotalDuration) override;
	virtual void ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime) override;
	virtual void ActionEnd(bool bAbilityFinished, bool bActionFinished) override;

	virtual FString GetActionName_Implementation() const override;

	bool SampleSocketTransform(AActor* Owner, float SampleTime, FName BoneName, FTransform& OutTransform, bool bExtractRootMotion = true);

	bool CalculateRootmotion(float BeginTime, float EndTime, FRootMotionMovementParams& OutRootMotionMovmentParams);

	float GetTimelinePositionFromAnimPosition(float AnimPosition);
	float GetAnimPositionFromActionPosition(float ActionPosition);
	float GetAnimPositionFromTimelinePosition(float TimelinePosition);

#if WITH_EDITOR
	float GetPlayLength() const;
	
	virtual void BeginPreview(AActor* PreviewActor, float TotalDuration) override;
	virtual void SetPosition(AActor* PreviewActor, float Position, float TotalDuration) override;
	virtual void EndPreview(AActor* PreviewActor) override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	void OnObjectPropertyChanged(UObject* Object, FPropertyChangedEvent& PropChangedEvent);

	FTransform DefaultPreviewActorTransfrom;
	EMovementMode PreviousMode;
#endif

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	FName TaskInstanceName;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	class UAnimMontage* MontageToPlay;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	float PlayRate;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	FName StartSection;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bStopWhenAbilityEnds;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bStopWhenActionEnds;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	float AnimRootMotionTranslationScale;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	float ClampSpeedWhenCanceled;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	float ForceClampSpeed;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bDisableSliding;

	// Actions On Event
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Trigger Actions", meta = (DisplayName = "On Blend Out"))
	class ULGAAction_Executable* OnBlendOutAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Trigger Actions", meta = (DisplayName = "On Complete"))
	class ULGAAction_Executable* OnCompletedAction;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bDebug;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	bool bDebugRootMotion = true;

protected:
	FAnimMontageInstance* GetCurrentMontageInstance();

	int32 MontageInstanceID;
};