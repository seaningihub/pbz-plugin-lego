// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "LegoAbility.generated.h"

class ULGAAction;
class ULGATimeline;

USTRUCT(BlueprintType)
struct FLGAEventAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "LegoAbility", meta = (Categories = "GameplayEvent"))
	FGameplayTag EventTag;

	UPROPERTY(EditAnywhere, Instanced, Category = "LegoAbility")
	ULGAAction_Executable*	ExecuteAction = nullptr;
};


UCLASS(Blueprintable)
class LEGOABILITY_API ULegoAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Actions on event")
	TArray<ULGAAction_Executable*> ExecuteOnActivate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Actions on event")
	TArray<ULGAAction_Executable*> ExecuteOnEnd;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Actions on event")
	TArray<FLGAEventAction> ExecuteOnGameplayEvent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Actions on event")
	TArray<ULGAAction_Executable*> ExecuteOnInputPressed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Actions on event")
	TArray<ULGAAction_Executable*> ExecuteOnInputReleased;

public:
	virtual void PostInitProperties() override;
	
	/** Returns the name of the Ability in a print friendly format (without class identifiers).	*/
	UFUNCTION(BlueprintPure, Category = Ability)
	FString GetDisplayName() const;

	/** Returns the Timelines of this Ability. */
	const TArray<ULGATimeline*>& GetTimelines() const { return Timelines; }

	/** Returns the Timeline which has specified instance name of this Ability. */
	UFUNCTION(BlueprintCallable, Category = Ability)
	ULGATimeline* GetTimelineByName(FName TimelineName = "NewTimeline") const;

	UFUNCTION(BlueprintCallable, Category = Ability)
	ULGATimeline* GetTimelineByIndex(int Index) const;

	UFUNCTION(BlueprintCallable, Category = Ability)
	ULGAAction* GetActionByName(FName TimelineName, FName ActionName) const;

	UFUNCTION(BlueprintCallable, Category = Ability)
	TArray<ULGAAction*> GetActionsByTag(TSubclassOf<ULGAAction> ActionClass, FGameplayTagRequirements ActionTagReqs);

	/** Returns all actions which need to replicate to simulation on the timelines of this Ability. */
	TArray<ULGAAction*> GetActionsNeedToReplicate() const;

	bool LockScopeTimeline();
	void ReleaseScopeTimeline();

	/* Start a task to play ability timeline */
	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void PlayTimeline(ULGATimeline* Timeline, float PlayRate = 1.f, float SyncPoint = 0.f, float StartTimeSeconds = 0.f, FName PreviousTimlineName = NAME_None);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void PlayTimelineByName(FName TimelineName, float PlayRate = 1.f, float SyncPoint = 0.f, float StartTimeSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void EndTimeline(ULGATimeline* Timeline);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void EndTimelineByName(FName TimelineName);

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	bool IsPlayingTimeline(ULGATimeline* Timeline) const;

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	bool IsPlayingAnyTimeline(TArray<ULGATimeline*> InTimelines);

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	float GetCurveValue(FName CurveName, float DefaultValue = 0);

	/** Returns the active PlayTimeline task of this Ability. */
	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	class ULGATask_PlayTimeline* GetPlayTimelineTask() const;

	/** Adds a Timeline to the Ability. */
	void AddTimeline(ULGATimeline* Timeline) { Timelines.Add(Timeline); }

	// Execute an executable action within this ability.
	UFUNCTION(BlueprintCallable, Category = "Action")
	void ExecuteAction(ULGAAction_Executable* Action, FLGAActionExecutionContextHandle Context);

	virtual FName GetTimeStrechCurveNameSuffix() { return FName(); };

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	TArray<FName> GetAllTimelineNames();

	bool IsInDynamicBlendOut() { return bIsInDynamicBlendOut; }

protected:
	/** Do boilerplate init stuff and then call ActivateAbility */
	virtual void PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate, const FGameplayEventData* TriggerEventData = nullptr) override;

	/** Actually activate ability, do not call this directly */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	/** Destroys instanced-per-execution abilities. Instance-per-actor abilities should 'reset'. Any active ability state tasks receive the 'OnAbilityStateInterrupted' event. Non instance abilities - what can we do? */
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;

	/** Native function, called if an ability ends normally or abnormally. If bReplicate is set to true, try to replicate the ending to the client/server */
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	// Handle gameplay event, execute registered actions
	void OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Data);

	/** Input binding stub. */
	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo);

	/** Input binding stub. */
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo);

protected:
	/** Array of all Timelines in this Ability */
	UPROPERTY(BlueprintReadOnly, Transient, DuplicateTransient, TextExportTransient, Category = "LegoAbility")
	TArray<ULGATimeline*> Timelines;

	FName CanceledTimelineName;
	bool bIsInDynamicBlendOut = false;

private:
	FGameplayTagContainer EventTagsBound;
	FDelegateHandle EventDelegateHandle;

	bool bScopeLockTimeline = false;
};
