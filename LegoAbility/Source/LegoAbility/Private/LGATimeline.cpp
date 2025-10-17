// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimeline.h"
#include "Actions/LGAAction.h"
#include "LGATask_PlayTimeline.h"
#include "Engine/NetDriver.h"
#include "Net/UnrealNetwork.h"
#include "LegoAbility.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "UObject/Package.h"

/////////////////////////////////////////////////////
// FAbilityActionEvent

float FLGAActionEvent::GetDuration() const
{
	if (!Action) return 0.f;
	return Action->IsSingleFrame() ? 0.f : Duration;
}

void FLGAActionEvent::SetDuration(float NewDuration)
{
	Duration = NewDuration;

#if WITH_EDITOR
	if (!Action->GetWorld() || !Action->GetWorld()->IsPlayInEditor())
	{
		Action->OnDurationChanged(NewDuration);
	}
#endif
}

float FLGAActionEvent::GetSectionDuration(int32 Index)
{
	if (Sections.IsValidIndex(Index))
	{
		return Sections[Index].Duration;
	}

	return 0.f;
}

void FLGAActionEvent::SetSectionDuration(int32 Index, float NewDuration)
{
	if (Sections.IsValidIndex(Index) && Sections.IsValidIndex(Index + 1))
	{
		float ClampedDuration = FMath::Clamp(NewDuration, 0.f, Sections[Index].Duration + Sections[Index + 1].Duration);
		float Delta = ClampedDuration - Sections[Index].Duration;
		Sections[Index].Duration = ClampedDuration;
		Sections[Index + 1].Duration -= Delta;

#if WITH_EDITOR
		if (!Action->GetWorld() || !Action->GetWorld()->IsPlayInEditor())
		{
			Action->OnSectionDurationChanged();
		}
#endif
	}
}

float FLGAActionEvent::GetSectionStartTime(int32 Index)
{
	float SectionStartTime = 0.f;
	
	for(int32 i = 0; i < Index && i < Sections.Num(); ++i)
	{
		SectionStartTime += Sections[i].Duration;
	}

	return SectionStartTime;
}

float FLGAActionEvent::GetSectionEndTime(int32 Index)
{
	float SectionEndTime = 0.f;

	for (int32 i = 0; i <= Index && i < Sections.Num(); ++i)
	{
		SectionEndTime += Sections[i].Duration;
	}

	return SectionEndTime;
}

float FLGAActionEvent::GetAbsoluteSectionStartTime(int32 Index)
{
	return GetStartTime() + GetSectionStartTime(Index);
}

float FLGAActionEvent::GetAbsoluteSectionEndTime(int32 Index)
{
	return GetStartTime() + GetSectionEndTime(Index);
}


#if WITH_EDITOR
void FLGAActionEvent::RefreshCacheData()
{
	if (Action)
	{
		Action->RefreshCacheData();
	}
}

float FLGAActionEvent::GetMinimumStateDuration()
{
	return Action ? FMath::Max(1.f / 30.f, Action->GetMinimumDuration()) : 1.f / 30.f;
}
#endif

/////////////////////////////////////////////////////
// ULegoAbilityTimeline

ULGATimeline::ULGATimeline()
	: SequenceLength(1.f), bLooping(false), bAutoPlay(false), bStopAbility(false), TimeStretchCurveName("Rate"), StartTimeSeconds(0.f)
#if WITH_EDITOR
	, PreviewWorld(nullptr)
#endif
{
}

int32 ULGATimeline::GetFunctionCallspace(UFunction* Function, FFrame* Stack)
{
	if (HasAnyFlags(RF_ClassDefaultObject) || !IsSupportedForNetworking())
	{
		return FunctionCallspace::Local;
	}
	check(GetOuter() != nullptr);
	return GetOuter()->GetFunctionCallspace(Function, Stack);
}

bool ULGATimeline::CallRemoteFunction(UFunction* Function, void* Parameters, FOutParmRec* OutParms, FFrame* Stack)
{
	check(!HasAnyFlags(RF_ClassDefaultObject));
	check(GetOuter() != nullptr);

	AActor* Owner = CastChecked<AActor>(GetOuter());

	bool bProcessed = false;

	FWorldContext* const Context = GEngine->GetWorldContextFromWorld(GetWorld());
	if (Context != nullptr)
	{
		for (FNamedNetDriver& Driver : Context->ActiveNetDrivers)
		{
			if (Driver.NetDriver != nullptr && Driver.NetDriver->ShouldReplicateFunction(Owner, Function))
			{
				Driver.NetDriver->ProcessRemoteFunction(Owner, Function, Parameters, OutParms, Stack, this);
				bProcessed = true;
			}
		}
	}

	return bProcessed;
}

bool ULGATimeline::IsSupportedForNetworking() const
{
	return true;
}

UWorld* ULGATimeline::GetWorld() const
{
	return GetOuter()->GetWorld();
}

FLGAActionEvent* ULGATimeline::GetActionEventByName(FName ActionName)
{
	for (FLGAActionEvent& ActionEvent : Actions)
	{
		if (ActionEvent.Action->GetFName() == ActionName)
		{
			return &ActionEvent;
		}
	}

	return nullptr;
}

FLGAActionEvent* ULGATimeline::GetActionEventByAction(const ULGAAction* Action)
{
	for (FLGAActionEvent& ActionEvent : Actions)
	{
		if (ActionEvent.Action == Action)
		{
			return &ActionEvent;
		}
	}

	return nullptr;
}

FLGAActionEvent* ULGATimeline::GetActionEventByClass(const UClass* Class, const float SampleTime)
{
	for (FLGAActionEvent& ActionEvent : Actions)
	{
		if (ActionEvent.Action &&  ActionEvent.Action->GetClass()->IsChildOf(Class))
		{
			if (SampleTime >= 0.f)
			{
				if (ActionEvent.StartTime <= SampleTime && ActionEvent.GetEndTime() >= SampleTime)
				{
					return &ActionEvent;
				}
			}
			else
			{
				return &ActionEvent;
			}
		}
	}

	return nullptr;
}

TArray<FLGAActionEvent*> ULGATimeline::GetActionEventsByClass(const UClass* Class, float SampleTime /*= -1.f*/)
{
	TArray<FLGAActionEvent*> Result;

	for (FLGAActionEvent& ActionEvent : Actions)
	{
		if (ActionEvent.Action && ActionEvent.Action->GetClass()->IsChildOf(Class))
		{
			if (SampleTime >= 0.f)
			{
				if (ActionEvent.StartTime <= SampleTime && ActionEvent.GetEndTime() >= SampleTime)
				{
					Result.Add(&ActionEvent);
				}
			}
			else
			{
				Result.Add(&ActionEvent);
			}
		}
	}

	return Result;
}

FLGAActionEvent* ULGATimeline::GetActionEventByGuid(const FGuid& ActionGuid)
{
	for (FLGAActionEvent& ActionEvent : Actions)
	{
		if (ActionEvent.Action && ActionEvent.Guid == ActionGuid)
		{
			return &ActionEvent;
		}
	}

	return nullptr;
}

FFloatCurve* ULGATimeline::GetCurveByName(FName CurveName)
{
	return FloatCurves.FindByPredicate([CurveName](const FFloatCurve& Item){ return Item.GetName() == CurveName; });
}

FName ULGATimeline::GetTimeStretchName()
{
	if (ULegoAbility* Ability = Cast<ULegoAbility>(GetOuter()))
	{
		FName Suffix = Ability->GetTimeStrechCurveNameSuffix();
		if (!Suffix.IsNone())
		{
			FName NameWithSuffix = FName(*FString::Format(TEXT("{0}_{1}"), {TimeStretchCurveName.ToString(), Suffix.ToString()}));
			return NameWithSuffix;
		}
	}
#if WITH_EDITORONLY_DATA
	else if(PreviewWorld && PreviewWeapon.IsValid())
	{
		FString TagName = PreviewWeapon.GetTagName().ToString();
		int32 LastDotIndex;
		if (TagName.FindLastChar('.', LastDotIndex))
		{
			FString Suffix = TagName.RightChop(LastDotIndex + 1);

			FName NameWithSuffix = FName(*FString::Format(TEXT("{0}_{1}"), {TimeStretchCurveName.ToString(), Suffix}));
			return NameWithSuffix;
		}
	}
#endif
	
	return TimeStretchCurveName;
}

FFloatCurve* ULGATimeline::GetStretchCurve()
{
	FFloatCurve* Result = GetCurveByName(GetTimeStretchName());
	if (!Result)
	{
		return GetCurveByName(TimeStretchCurveName);
	}

	return Result;
}

void ULGATimeline::RemoveCurve(FName CurveName)
{
	if (FloatCurves.RemoveAll([CurveName](const FFloatCurve& Item) { return Item.GetName() == CurveName; }))
	{
#if WITH_EDITOR
		PostEditChange();
#endif
		MarkPackageDirty();
	}
}

void ULGATimeline::AddCurve(FName Name, const TArray<float>& Times, const TArray<float>& Values)
{
	FFloatCurve* NewFloatCurve = GetCurveByName(Name);
	if(!NewFloatCurve)
	{
		NewFloatCurve = &FloatCurves.Emplace_GetRef(Name, (int32)ERawCurveTrackTypes::RCT_Float);
#if WITH_EDITOR
		PostEditChange();
#endif
		MarkPackageDirty();
	}

	if (NewFloatCurve)
	{
		for (int32 i = 0; i < Times.Num() && i < Values.Num(); ++i)
		{
			NewFloatCurve->UpdateOrAddKey(Values[i], Times[i]);
		}
	}
}

float ULGATimeline::GetScaledTimeStep(const float CurrentTime, const float InTimelineStep)
{
	if (InTimelineStep == 0.0f)
	{
		return 0.0f;
	}
	if (const FFloatCurve* StretchCurve = GetStretchCurve())
	{
		const float IntegralStep = (1.f / 120.f) * FMath::Sign(InTimelineStep);
		float IntegralDuration = 0.f;
		
		float Duration = 0.0f;
		while (FMath::Abs(IntegralDuration) <= FMath::Abs(InTimelineStep))
		{
			if (const float StretchRate = FMath::Max(StretchCurve->Evaluate(CurrentTime + IntegralDuration), 0.01f); StretchRate >= 1.0f)
			{
				IntegralDuration += IntegralStep;
				Duration += IntegralStep / StretchRate;
				if (FMath::Abs(IntegralDuration) > FMath::Abs(InTimelineStep))
				{
					Duration -= (IntegralDuration - InTimelineStep) / StretchRate;
					return Duration;
				}
			}
			else
			{
				IntegralDuration += IntegralStep * StretchRate;
				Duration += IntegralStep;
				
				if (FMath::Abs(IntegralDuration) > FMath::Abs(InTimelineStep))
				{
					Duration -= (IntegralDuration - InTimelineStep) / StretchRate;
					return Duration;
				}
			}
		}
		return Duration;
	}
	return InTimelineStep;
}

float ULGATimeline::GetOriginalStep(const float CurrentTime, const float RuntimeStep)
{
	if (RuntimeStep == 0.0f)
	{
		return 0.0f;
	}
	if (const FFloatCurve* StretchCurve = GetStretchCurve())
	{
		const float IntegralStep = (1.f / 120.f) * FMath::Sign(RuntimeStep);
		float IntegralDuration = 0.f;
		
		float RuntimeDuration = 0.f;
		while (FMath::Abs(RuntimeDuration) <= FMath::Abs(RuntimeStep))
		{
			float StretchRate = FMath::Max(StretchCurve->Evaluate(CurrentTime + IntegralDuration), 0.01f);
			if (StretchRate >= 1.0f)
			{
				IntegralDuration += IntegralStep;
				RuntimeDuration += IntegralStep / StretchRate;
				if (FMath::Abs(RuntimeDuration) > FMath::Abs(RuntimeStep))
				{
					IntegralDuration -= (RuntimeDuration - RuntimeStep) * StretchRate;
					return IntegralDuration;
				}
			}
			else
			{
				IntegralDuration += IntegralStep * StretchRate;
				RuntimeDuration += IntegralStep;
				
				if (FMath::Abs(RuntimeDuration) > FMath::Abs(RuntimeStep))
				{
					IntegralDuration -= (RuntimeDuration - RuntimeStep) * StretchRate;
					return IntegralDuration;
				}
			}
		}

		return IntegralDuration;
	}

	return RuntimeStep;
}

const FLGATimelineBlendSetting* ULGATimeline::GetDyanamicBlendSetting(FName PreviousTimlineName)
{
	for (const FLGATimelineBlendSetting& BlendSetting : DynamicBlendSettings)
	{
		if (BlendSetting.PreviousAbility.IsValid())
		{
			if (BlendSetting.GetCompareName() == PreviousTimlineName)
			{
				return &BlendSetting;
			}
		}
	}
	return nullptr;
}

#if WITH_EDITOR
void ULGATimeline::ResizeLength()
{
	float MaxEndTime = 0;
	for (FLGAActionEvent& Event : Actions)
	{
		float EndTime = Event.Action->IsSingleFrame() ? Event.GetStartTime() : Event.GetEndTime();
		if (EndTime > MaxEndTime)
		{
			MaxEndTime = EndTime;
		}
	}

	if (MaxEndTime > 0)
	{
		SequenceLength = MaxEndTime;
	}
}

void ULGATimeline::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	OnPropertyChanged.Broadcast();

	if (PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
	{
		for (FLGAActionEvent& ActionEvent : Actions)
		{
			if (ActionEvent.Action)
			{
				ActionEvent.Action->UpdateActualEventTime();
			}
		}
	}
}

void ULGATimeline::PostEditUndo()
{
	Super::PostEditUndo();

	OnTransactionApplied.Broadcast();
}

int32 ULGATimeline::GetNumberOfFrames() const
{
	static float DefaultSampleRateInterval = 1.f / DEFAULT_SAMPLERATE;
	// because of float error, add small margin at the end, so it can clamp correctly
	return (int32)(SequenceLength / DefaultSampleRateInterval + KINDA_SMALL_NUMBER) + 1;
}

ULGATimeline* ULGATimeline::GetNullTimeline()
{
	static ULGATimeline* NullTimeline = nullptr;
	if (!NullTimeline)
	{
		NullTimeline = NewObject<ULGATimeline>(GetTransientPackage(), FName(TEXT("NullAnimation")));
		NullTimeline->AddToRoot();
	}

	return NullTimeline;
}

int32 ULGATimeline::GetFrameAtTime(const float Time) const
{
	const float FrameTime = GetNumberOfFrames() > 1 ? SequenceLength / (float)(GetNumberOfFrames() - 1) : 0.0f;
	return FMath::Clamp(FMath::RoundToInt(Time / FrameTime), 0, GetNumberOfFrames() - 1);
}

float ULGATimeline::GetTimeAtFrame(const int32 Frame) const
{
	const float FrameTime = GetNumberOfFrames() > 1 ? SequenceLength / (float)(GetNumberOfFrames() - 1) : 0.0f;
	return FMath::Clamp(FrameTime * Frame, 0.0f, SequenceLength);
}

void ULGATimeline::InitializeNotifyTrack()
{
	if (AbilityActionTracks.Num() == 0)
	{
		AbilityActionTracks.Emplace(TEXT("1"), FLinearColor::White);
	}
}

EAnimEventTriggerOffsets::Type ULGATimeline::CalculateOffsetForNotify(float NotifyDisplayTime) const
{
	if (NotifyDisplayTime == 0.f)
	{
		return EAnimEventTriggerOffsets::OffsetAfter;
	}
	else if (NotifyDisplayTime == SequenceLength)
	{
		return EAnimEventTriggerOffsets::OffsetBefore;
	}
	return EAnimEventTriggerOffsets::NoOffset;
}

uint8* ULGATimeline::FindNotifyPropertyData(int32 ActionIndex, FArrayProperty*& ArrayProperty)
{
	ArrayProperty = nullptr;

	if (Actions.IsValidIndex(ActionIndex))
	{
		return FindArrayProperty(TEXT("Actions"), ArrayProperty, ActionIndex);
	}
	return nullptr;
}

uint8* ULGATimeline::FindArrayProperty(const TCHAR* PropName, FArrayProperty*& ArrayProperty, int32 ArrayIndex)
{
	// find Actions property start point
	FProperty* Property = FindFProperty<FProperty>(GetClass(), PropName);

	// found it and if it is array
	if (Property && Property->IsA(FArrayProperty::StaticClass()))
	{
		// find Property Value from UObject we got
		uint8* PropertyValue = Property->ContainerPtrToValuePtr<uint8>(this);

		// it is array, so now get ArrayHelper and find the raw ptr of the data
		ArrayProperty = CastFieldChecked<FArrayProperty>(Property);
		FScriptArrayHelper ArrayHelper(ArrayProperty, PropertyValue);

		if (ArrayProperty->Inner && ArrayIndex < ArrayHelper.Num())
		{
			//Get property data based on selected index
			return ArrayHelper.GetRawPtr(ArrayIndex);
		}
	}
	return nullptr;
}

bool CanActionUseTrack(const FLGAActionTrack& Track, const FLGAActionEvent& Action)
{
	float StartTime = Action.GetStartTime();
	for (const FLGAActionEvent* Event : Track.Actions)
	{
		if (FMath::IsNearlyEqual(Event->GetStartTime(), StartTime))
		{
			return false;
		}
	}
	return true;
}

int32 AddNewTrack(TArray<FLGAActionTrack>& Tracks)
{
	return Tracks.Emplace(*FString::FromInt(Tracks.Num() + 1), FLinearColor::White);
}

void ULGATimeline::RefreshCacheData()
{
	Actions.Sort();

	for (FLGAActionTrack& ActionTrack : AbilityActionTracks)
	{
		ActionTrack.Actions.Empty();
	}

	for (FLGAActionEvent& Action : Actions)
	{
		// Handle busted track indices
		if (!AbilityActionTracks.IsValidIndex(Action.TrackIndex))
		{
			// This really shouldn't happen (unless we are a cooked asset), but try to handle it
			ensureMsgf(GetOutermost()->bIsCookedForEditor, TEXT("AbilityActionTrack: Timeline (%s) has action (%s) with track index (%i) that does not exist"), *GetFullName(), *Action.Action->GetName(), Action.TrackIndex);

			// Don't create lots of extra tracks if we are way off supporting this track
			if (Action.TrackIndex < 0 || Action.TrackIndex > 20)
			{
				Action.TrackIndex = 0;
			}

			while (!AbilityActionTracks.IsValidIndex(Action.TrackIndex))
			{
				AddNewTrack(AbilityActionTracks);
			}
		}

		// Handle overlapping actions
		int32 TrackIndexToUse = INDEX_NONE;
		for (int32 Offset = 0; Offset < AbilityActionTracks.Num(); ++Offset)
		{
			const int32 TrackIndex = (Action.TrackIndex + Offset) % AbilityActionTracks.Num();
			if (CanActionUseTrack(AbilityActionTracks[TrackIndex], Action))
			{
				TrackIndexToUse = TrackIndex;
				break;
			}
		}

		if (TrackIndexToUse == INDEX_NONE)
		{
			TrackIndexToUse = AddNewTrack(AbilityActionTracks);
		}

		Action.TrackIndex = TrackIndexToUse;
		AbilityActionTracks[TrackIndexToUse].Actions.Add(&Action);

		Action.RefreshCacheData();
	}
}
#endif //WITH_EDITOR

TArray<FName> ULGATimeline::GetPreviousTimelineNames()
{
	TSet<FName> Names;
	for (const FLGATimelineBlendSetting& BlendSetting : DynamicBlendSettings)
	{
		if (ULegoAbilityBlueprintGeneratedClass* AbilityClass = Cast<ULegoAbilityBlueprintGeneratedClass>(BlendSetting.PreviousAbility.LoadSynchronous()))
		{
			for (const ULGATimeline* Timeline : AbilityClass->GetAllTimelines())
			{
				Names.Add(Timeline->GetFName());
			}
		}
	}

	TArray<FName> Result = Names.Array();
	Result.Sort([](const FName& A, const FName& B)
		{
			return A.ToString() < B.ToString();
		});

	return MoveTemp(Result);
}

FName FLGATimelineBlendSetting::GetCompareName() const
{
	if (!CompareName.IsNone())
	{
		return CompareName;
	}

	if (!PreviousAbility.IsValid())
	{
		return NAME_None;
	}

	CompareName = FName(FString::Printf(TEXT("%s.%s"), *PreviousAbility->GetName(), *PreviousTimelineName.ToString()));
	return CompareName;
}
