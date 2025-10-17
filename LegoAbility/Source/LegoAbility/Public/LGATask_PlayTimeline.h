// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "LGATask_PlayTimeline.generated.h"

struct FLGATimelineBlendSetting;
class ULGATimeline;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTimelineWaitSimpleDelegate);

/**
 * Play Timeline
 */
UCLASS()
class LEGOABILITY_API ULGATask_PlayTimeline : public UAbilityTask
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	ULGATask_PlayTimeline();
	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	virtual void OnDestroy(bool bAbilityFinished) override;

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void SetPlayRate(float InPlayRate);
	float GetPlayRate() const { return PlayRate; }

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void SetSectionPlayRate(float InPlayRate, float StartTime, float EndTime, bool bSectionPlayRateClamp);

	void SetTimelinePaused(bool bInPaused) { bPaused = bInPaused; }

	void CancelTimeline();

	float GetCurrentTime(){ return CurrentTime; }

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void SkipSection(float Duration);

	void AddSyncPoint(float TimePoint){ SyncPoints.Add(TimePoint); }
	bool NextSyncPoint(float& OutPoint);

	ULGATimeline* GetTimeline() const { return Timeline; }

	const FLGATimelineBlendSetting* GetDynamicTimelineBlendSetting();

	UPROPERTY(BlueprintAssignable)
	FTimelineWaitSimpleDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FTimelineWaitSimpleDelegate	OnCancelled;

	/** Play Timeline */
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static ULGATask_PlayTimeline* PlayTimeline(UGameplayAbility* OwningAbility, FName TaskInstanceName, ULGATimeline* InTimeline, float PlayRate = 1.f, float SyncPoint = 0.f, float StartTimeSeconds = 0.f, FName InPreviousTimelineName = NAME_None);

#if WITH_EDITOR
	/** Returns net mode string for log. */
	FString GetNetModeString() const;
#endif

protected:
	virtual void AdvanceStep(float LastTime, float CurTime, bool bSkip = false);
	virtual void OnTimelineEnded();

	void HandlePendingStep();

protected:
	/** Playback rate */
	float PlayRate;

	float SectionPlayRate;
	float SectionPlayRateStart;
	float SectionPlayRateEnd;
	bool SectionPlayRateClamp;

	/** The timeline need to play */
	UPROPERTY(BlueprintReadOnly, Category = "LegoAbility")
	ULGATimeline* Timeline;

	/** Advance step pipeline */
	TArray<TPair<float, bool>> PendingSteps;

	/** Array of actions currently being executed. */
	TArray<struct FLGAActionEvent*> ActiveActionEvents;

	/** The Current Time of the Timeline. */
	UPROPERTY(BlueprintReadOnly, Category = "LegoAbility")
	float CurrentTime;

	/** Whether timeline is paused */
	bool bPaused;

	/** Whether timeline is completed */
	bool bCompleted;

	TArray<float> SyncPoints;

	FName PreviousTimelineName;

};
