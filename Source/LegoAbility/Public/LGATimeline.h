// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimTypes.h"
#include "Animation/AnimCurveTypes.h"
#include "Animation/AnimMontage.h"
#include "LegoAbilityTypes.h"
#include "GameplayEffectTypes.h"
#include "LGATimeline.generated.h"

#define LOCTEXT_NAMESPACE "LegoAbility"

class ULGAAction;

USTRUCT(BlueprintType)
struct LEGOABILITY_API FLGAActionEventSection
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float Duration;

	UPROPERTY()
	FColor Color;

public:
	FLGAActionEventSection()
		: Duration(0)
		, Color(1.f, 1.f, 1.f)
	{}

	FLGAActionEventSection(float InDuration, FColor InColor)
		: Duration(InDuration)
		, Color(InColor)
	{}
};

/**
 * Triggers an ability action. Each FAbilityActionEvent contains an ULegoAbilityAction object
 */
USTRUCT(BlueprintType)
struct LEGOABILITY_API FLGAActionEvent
{
	GENERATED_USTRUCT_BODY()

	/** The start time of this action. */
	UPROPERTY(BlueprintReadWrite, Category = "LegoAbility")
	float StartTime;

	/** The duration of this action. */
	UPROPERTY(BlueprintReadWrite, Category = "LegoAbility")
	float Duration;

	/** An offset from the DisplayTime to the actual time we will trigger the action, as we cannot always trigger it exactly at the time the user wants */
	UPROPERTY()
	float TriggerTimeOffset;

	/** An offset similar to TriggerTimeOffset but used for the end scrub handle of a action's duration */
	UPROPERTY()
	float EndTriggerTimeOffset;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = AbilityActionEvent)
	ULGAAction* Action;

	UPROPERTY()
	FGuid Guid;

	/** 'Track' that the action exists on, used for visual placement in editor and sorting priority in runtime */
	UPROPERTY()
	int32 TrackIndex;

	UPROPERTY()
	TArray<FLGAActionEventSection> Sections;

public:
	FLGAActionEvent() :
		StartTime(0.f),
		Duration(0.f),
		TriggerTimeOffset(0.f),
		EndTriggerTimeOffset(0.f),
		Action(nullptr),
		TrackIndex(0)
	{
	}

	/** Updates trigger offset based on a combination of predicted offset and current offset */
	void RefreshTriggerOffset(EAnimEventTriggerOffsets::Type PredictedOffsetType) {}

	/** Updates end trigger offset based on a combination of predicted offset and current offset */
	void RefreshEndTriggerOffset(EAnimEventTriggerOffsets::Type PredictedOffsetType) {}

	/** Set the actual trigger time for this action. */
	void SetStartTime(float NewTime) { StartTime = NewTime; }

	/** Returns the actual trigger time for this action. */
	float GetStartTime() const { return StartTime; }

	/** Returns the actual end time for this action. */
	float GetEndTime() const { return StartTime + Duration; }

	float GetDuration() const;

	void SetDuration(float NewDuration);

	float GetSectionDuration(int32 Index);
	void SetSectionDuration(int32 Index, float NewDuration);
	float GetSectionStartTime(int32 Index);
	float GetSectionEndTime(int32 Index);
	float GetAbsoluteSectionStartTime(int32 Index);
	float GetAbsoluteSectionEndTime(int32 Index);

#if WITH_EDITOR
	void RefreshCacheData();
	float GetMinimumStateDuration();
#endif

	/** This can be used with the Sort() function on a TArray of FAnimNotifyEvents to sort the notifies array by time, earliest first. */
	bool operator<(const FLGAActionEvent& Other) const
	{
		float ATime = GetStartTime();
		float BTime = Other.GetStartTime();

		// When we've got the same time sort on the track index. Explicitly
		// using SMALL_NUMBER here incase the underlying default changes as
		// notifies can have an offset of KINDA_SMALL_NUMBER to be consider
		// distinct
		return FMath::IsNearlyEqual(ATime, BTime, SMALL_NUMBER) ? TrackIndex < Other.TrackIndex : ATime < BTime;
	}
};

/**
 * Track of actions
 */
USTRUCT(BlueprintType)
struct LEGOABILITY_API FLGAActionTrack
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName TrackName;

	UPROPERTY()
	FLinearColor TrackColor;

	TArray<FLGAActionEvent*> Actions;

	FLGAActionTrack() : TrackName(TEXT("")), TrackColor(FLinearColor::White) {}
	FLGAActionTrack(FName InTrackName, FLinearColor InTrackColor) : TrackName(InTrackName), TrackColor(InTrackColor) {}
};

class ULegoAbility;
USTRUCT(BlueprintType)
struct LEGOABILITY_API FLGATimelineBlendSetting
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	TSoftClassPtr<ULegoAbility> PreviousAbility;

	UPROPERTY(EditAnywhere, meta = (GetOptions = "GetPreviousTimelineNames"), Category = "LegoAbility")
	FName PreviousTimelineName;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	float StartTimeSeconds;

	UPROPERTY(EditAnywhere, Category = "LegoAbility")
	FMontageBlendSettings MontageBlendIn;

	FName GetCompareName() const;

	FLGATimelineBlendSetting() : StartTimeSeconds(0.f) {}

private:
	mutable FName CompareName;
};

/**
 * Timeline of ability
 */
UCLASS(Blueprintable)
class LEGOABILITY_API ULGATimeline : public UObject
{
	GENERATED_BODY()

public:
	ULGATimeline();
	virtual int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack) override;
	virtual bool CallRemoteFunction(UFunction* Function, void* Parameters, FOutParmRec* OutParms, FFrame* Stack) override;
	virtual bool IsSupportedForNetworking() const override;
	virtual UWorld* GetWorld() const override;

	/** Returns the Length, in seconds, of the Timeline. */
	float GetPlayLength() const { return SequenceLength; }
	void SetPlayLength(float InPlayLength) { SequenceLength = InPlayLength; }

	/** Find FAbilityActionEvent by name, return null if not found. */
	FLGAActionEvent* GetActionEventByName(FName ActionName);

	/** Find FAbilityActionEvent by action, return null if not found. */
	FLGAActionEvent* GetActionEventByAction(const ULGAAction* Action);

	FLGAActionEvent* GetActionEventByClass(const UClass* Class, float SampleTime = -1.f);

	TArray<FLGAActionEvent*> GetActionEventsByClass(const UClass* Class, float SampleTime = -1.f);

	FLGAActionEvent* GetActionEventByGuid(const FGuid& ActionGuid);

	/** Find floatcurve by name, return null if not found */
	FFloatCurve* GetCurveByName(FName CurveName);

	FName GetTimeStretchName();
	FFloatCurve* GetStretchCurve();

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void RemoveCurve(FName Name);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void AddCurve(FName Name, const TArray<float>& Times, const TArray<float>& Values);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	float GetScaledTimeStep(float CurrentTime, float InTimelineStep);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	float GetOriginalStep(float CurrentTime, float RuntimeStep);

	const FLGATimelineBlendSetting* GetDyanamicBlendSetting(FName PreviousTimlineName);

#if WITH_EDITORONLY_DATA
	// if you change Actions array, this will need to be rebuilt
	UPROPERTY(BlueprintReadWrite, Category = "LegoAbility")
	TArray<FLGAActionTrack> AbilityActionTracks;
#endif // WITH_EDITORONLY_DATA

#if WITH_EDITOR
	void ResizeLength();

	/** Called when a property on this object has been modified externally */
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	/** Called after applying a transaction to the object. */
	virtual void PostEditUndo() override;

	/** Delegate called when a property has been modified externally */
	DECLARE_EVENT(ULGATimeline, FOnPropertyChanged)
	FOnPropertyChanged OnPropertyChanged;

	/** Delegate called when a undo/redo transaction happens */
	DECLARE_EVENT(ULGATimeline, FOnTransactionApplied)
	FOnTransactionApplied OnTransactionApplied;

	/** Return Number of Frames **/
	int32 GetNumberOfFrames() const;

	/** Get a placeholder timeline */
	static ULGATimeline* GetNullTimeline();

	/** Get the frame number for the provided time */
	int32 GetFrameAtTime(const float Time) const;

	/** Get the time at the given frame */
	float GetTimeAtFrame(const int32 Frame) const;

	// @todo document
	void InitializeNotifyTrack();

	/** Calculates what (if any) offset should be applied to the trigger time of a action given its display time */
	EAnimEventTriggerOffsets::Type CalculateOffsetForNotify(float NotifyDisplayTime) const;

	// Get a pointer to the data for a given Action
	uint8* FindNotifyPropertyData(int32 ActionIndex, FArrayProperty*& ArrayProperty);

	// Get a pointer to the data for a given array property item
	uint8* FindArrayProperty(const TCHAR* PropName, FArrayProperty*& ArrayProperty, int32 ArrayIndex);

	// update cache data (action tracks)
	void RefreshCacheData();
#endif // WITH_EDITOR

	UPROPERTY(EditAnywhere, Category = Tags )
	FGameplayTagContainer TimelineTags;

	/** Ability actions */
	UPROPERTY(BlueprintReadWrite, Category = "LegoAbility")
	TArray<FLGAActionEvent> Actions;

	UPROPERTY()
	TArray<FFloatCurve>	FloatCurves;

	/** Length (in seconds) of this Timeline if played back with a speed of 1.0. */
	UPROPERTY(Category = Timeline, BlueprintReadOnly)
	float SequenceLength;

	/** Whether the timeline should loop when it reaches the end */
	UPROPERTY(Category = Timeline, BlueprintReadOnly)
	bool bLooping;

	/** Whether the timeline should be auto played when ability is activated */
	UPROPERTY(Category = Timeline, BlueprintReadOnly)
	bool bAutoPlay;

	/** Whether the timeline should end ability when it reaches the end */
	UPROPERTY(Category = Timeline, BlueprintReadOnly)
	bool bStopAbility;

	UPROPERTY(Category = Timeline, EditAnywhere, BlueprintReadOnly)
	FName TimeStretchCurveName;

	UPROPERTY(Category = Timeline, EditAnywhere, BlueprintReadOnly)
	float StartTimeSeconds;

	UPROPERTY(Category = Timeline, EditAnywhere, meta = (TitleProperty = "{PreviousAbility}"))
	TArray<FLGATimelineBlendSetting> DynamicBlendSettings;
	
#if WITH_EDITORONLY_DATA
	UWorld* PreviewWorld;
	
	float PreviewPosition;

	UPROPERTY(Category = Preview, EditAnywhere, meta = (Categories = "Weapon.Type"))
	FGameplayTag PreviewWeapon;

	FLegoEditorAddCameraShakeDelegate AddCameraShake;
	FLegoEditorRemoveCameraShakeDelegate RemoveCameraShake;
#endif

	UFUNCTION()
	TArray<FName> GetPreviousTimelineNames();
};

#undef LOCTEXT_NAMESPACE