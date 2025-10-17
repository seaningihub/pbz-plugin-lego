// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "UnrealClient.h"
#include "LGAAction.generated.h"

UENUM(BlueprintType)
enum class EGameplayActionNetExecutionPolicy : uint8
{
	// This action will always be executed
	Always				UMETA(DisplayName = "Always"),

	// This action will only run on the client or server that has local control
	LocalOnly			UMETA(DisplayName = "Local Only"),

	// This action will only run on the server
	ServerOnly			UMETA(DisplayName = "Server Only"),
};

struct FLGAActionEvent;

UCLASS(Abstract, Blueprintable, HideCategories = Object, CollapseCategories)
class LEGOABILITY_API ULGAAction : public UObject
{
	GENERATED_BODY()

public:
	ULGAAction();
	virtual ~ULGAAction();
	
public:
	/** Returns true if this action can be activated */
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "CanActivateAction")
	bool K2_CanActivateAction() const;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "ActionBegin")
	void Received_ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "ActionTick")
	void Received_ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "ActionSkip")
	void Received_ActionSkip(float ElapsedTime, float TotalDuration);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "ActionEnd")
	void Received_ActionEnd(bool bAbilityFinished, bool bActionFinished);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "TimelineBegin")
	void Received_TimelineBegin();

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "TimelineEnd")
	void Received_TimelineEnd(bool bTimelineFinished);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "PreviewBegin")
	void Received_PreviewBegin(AActor* PreviewActor, float TotalDuration);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "SetPosition")
	void Received_SetPosition(AActor* PreviewActor, float Position, float TotalDuration);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "PreviewEnd")
	void Received_PreviewEnd(AActor* PreviewActor);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "NeedShowTransformWidget")
	bool Received_NeedShowTransformWidget();

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "GetWidgetLocation")
	FVector Received_GetWidgetLocation(AActor* PreviewActor);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "GetWidgetRotation")
	FRotator Received_GetWidgetRotation(AActor* PreviewActor);

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "InputWidgetDelta")
	bool Received_InputWidgetDelta(AActor* PreviewActor, const FVector& Drag, const FRotator& Rot, const FVector& Scale);

	virtual void OnTimelineBegin();
	virtual void OnTimelineEnd(bool bTimelineFinished);
	virtual void ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime);
	virtual void ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime);
	virtual void ActionSkip(float ElapsedTime, float TotalDuration);
	virtual void ActionEnd(bool bAbilityFinished, bool bActionFinished);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	bool IsLoopAction() { return bLoopAction; }

	void SetLoopAction(bool bLoop) { bLoopAction = bLoop; }

	virtual void OnPlayRateChanged(float OldPlayRate, float NewPlayRate){};

public:
	/** 
	 * Implementable event to get a custom name for the action
	 */
	UFUNCTION(BlueprintNativeEvent)
	FString GetActionName() const;

	virtual bool CanActivateAction() const;

	void BeginAction(float ElapsedTime, float TotalDuration, float BeginTime);
	void TickAction(float ElapsedTime, float TotalDuration, float DeltaTime);
	void SkipAction(float ElapsedTime, float TotalDuration);
	void EndAction(bool bAbilityFinished, bool bActionFinished);

private:
	bool InternalActivateAction(float ElapsedTime, float TotalDuration, float BeginTime);
	void InternalEndAction(bool bAbilityFinished, bool bActionFinished);

public:
	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	AActor* GetAvatarActor() const;

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	class ULegoAbility* GetAbility() const;

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	class ULGATimeline* GetTimeline() const;

	FLGAActionEvent* GetActionEvent() const;
	
	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	void GetActionEvent(FLGAActionEvent& Event) const;

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	bool IsSimulatedAction() const;

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	bool IsLocallyControlled() const;

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	bool HasAuthority() const;

	virtual UWorld* GetWorld() const override;
	
	/* Returns whether this action will be executed during a single frame. */
	bool IsSingleFrame() const { return bIsSingleFrame; }

	bool IsGuaranteedToBeTriggered() const{ return bGuaranteedToBeTriggered;  }

	bool IsIgnoreInitialSkip() const { return bIgnoreInitialSkip; }

	bool ShouldReplicateToSimulation() { return bReplicateToSimulation; }

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	const FGameplayTagContainer& GetActionTags() const { return ActionTags; }

	/* Checks the action's network execution policy. */
	bool CheckNetExecutionPolicy() const;

#if WITH_EDITOR
	virtual void RefreshCacheData() {};
	virtual bool CanChangeDuration() const;
	virtual void OnDurationChanged(float NewDuration);
	virtual void OnSectionDurationChanged();

	virtual bool NeedShowTransformWidget() {return Received_NeedShowTransformWidget();}
	virtual FVector GetWidgetLocation(AActor* PreviewActor) {return Received_GetWidgetLocation(PreviewActor);}
	virtual FRotator GetWidgetRotation(AActor* PreviewActor) { return Received_GetWidgetRotation(PreviewActor); }
	virtual bool InputWidgetDelta(AActor* PreviewActor, FViewport* InViewport, EAxisList::Type CurrentAxis, const FVector& Drag, const FRotator& Rot, const FVector& Scale);

	virtual bool NeedFollowCamera() { return false; }

	void SetActionNodeDuration(float NewDuration);
	virtual float GetMinimumDuration() const;

	virtual bool CanPreview(AActor* PreviewActor, ULGATimeline* PreviewTimeline);
	virtual void BeginPreview(AActor* PreviewActor, float TotalDuration) { Received_PreviewBegin(PreviewActor, TotalDuration); };
	virtual void SetPosition(AActor* PreviewActor, float Position, float TotalDuration) { Received_SetPosition(PreviewActor, Position, TotalDuration); }
	virtual void EndPreview(AActor* PreviewActor) { Received_PreviewEnd(PreviewActor); };

	void UpdateActualEventTime();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	FLinearColor GetEditorColor() const { return FLinearColor(ActionColor); }
	const FString& GetDescription() const { return Description; }

	virtual void PostLoad() override;
#endif

public:
#if WITH_EDITORONLY_DATA
	/* whether bIsSingleFrame property is editable */
	UPROPERTY(EditDefaultsOnly, Category = "Editor Settings")
	bool bCanEditSingleFrame;

	/* whether this action is triggered on preview */
	UPROPERTY(EditDefaultsOnly, Category = "Editor Settings")
	bool bSupportPreview;

	/* Color of Action in editor */
	UPROPERTY(EditDefaultsOnly, Category = "Editor Settings")
	FColor ActionColor;

	/** The tooltip when mouse hovered. */
	UPROPERTY(EditDefaultsOnly, Category = "Editor Settings")
	FString Description;

	UPROPERTY(VisibleAnywhere, Transient, Category = "Action Event Time")
	float ActualStartTime;

	UPROPERTY(VisibleAnywhere, Transient, Category = "Action Event Time")
	float ActualDuration;

	UPROPERTY(VisibleAnywhere, Transient, Category = "Action Event Time")
	float ActualEndTime;

	UWorld* PreviewWorld;
#endif // WITH_EDITORONLY_DATA

protected:
	UPROPERTY(EditAnywhere, Category = "Duration Type", meta = (EditCondition = "bCanEditSingleFrame"))
	bool bIsSingleFrame;

	UPROPERTY(EditAnywhere, Category = "Action Tags")
	FGameplayTagContainer ActionTags;

	UPROPERTY(EditAnywhere, Category = "Condition")
	FGameplayTagRequirements ActivationRequirements;

	UPROPERTY(EditAnywhere, Category = "Trigger", meta = (EditCondition = "bIsSingleFrame"))
	bool bGuaranteedToBeTriggered;

	UPROPERTY(EditAnywhere, Category = "Trigger", meta = (EditCondition = "bIsSingleFrame"))
	bool bIgnoreInitialSkip;

	UPROPERTY(EditDefaultsOnly, Category = "Network Replication")
	EGameplayActionNetExecutionPolicy NetExecutionPolicy;

	UPROPERTY(EditDefaultsOnly, Category = "Network Replication")
	bool bReplicateToSimulation;

private:
	bool bHasBlueprintCanActivate;

	bool bLoopAction;
};