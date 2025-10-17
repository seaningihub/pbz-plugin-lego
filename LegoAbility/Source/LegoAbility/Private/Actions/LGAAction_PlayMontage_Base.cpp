// Copyright S-Game, Inc. All Rights Reserved.

#include "Actions/LGAAction_PlayMontage_Base.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimInstance.h"
#include "LegoAbility.h"
#include "GameFramework/Character.h"
#include "LegoAbilityBlueprintLibrary.h"
#include "LGATask_PlayTimeline.h"
#include "LegoAbilityLog.h"
#include "LGATimeline.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Animation/AnimMontage.h"

UAnimMontage* ULGAAction_PlayMontage_Base::GetMontageToPlay() const
{
	if (!Animation)
	{
		return nullptr;
	}

	if (UAnimMontage* AnimMontage = Cast<UAnimMontage>(Animation))
	{
		return AnimMontage;
	}
	else if(DynamicMontage && DynamicMontage->GetFirstAnimReference() == Animation)
	{
		return DynamicMontage;
	}

	DynamicMontage = UAnimMontage::CreateSlotAnimationAsDynamicMontage(Animation, FAnimSlotGroup::DefaultSlotName);
	return DynamicMontage;
}

UAnimInstance* ULGAAction_PlayMontage_Base::GetAnimInstance_Implementation(AActor* PreviewActor)
{
	ULegoAbility* Ability = GetAbility();
	check(Ability);

	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	if (!ActorInfo)
	{
		return nullptr;
	}

	UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
	return AnimInstance;
}

void ULGAAction_PlayMontage_Base::OnMontageBlendOut(UAnimMontage* Montage, bool bInterrupted)
{
	ULegoAbility* Ability = GetAbility();
	check(Ability);

	if (OnBlendOutAction)
	{
		FLGAActionExecutionContextHandle ContextHandle = ULegoAbilityBlueprintLibrary::ActionContextFromActor(
			GetAvatarActor());
		Ability->ExecuteAction(OnBlendOutAction, ContextHandle);
	}
}

void ULGAAction_PlayMontage_Base::OnMontageCompleted(UAnimMontage* Montage, bool bInterrupted)
{
	ULegoAbility* Ability = GetAbility();
	check(Ability);

	if (OnCompletedAction)
	{
		FLGAActionExecutionContextHandle ContextHandle = ULegoAbilityBlueprintLibrary::ActionContextFromActor(
			GetAvatarActor());
		Ability->ExecuteAction(OnCompletedAction, ContextHandle);
	}
}

void ULGAAction_PlayMontage_Base::OnAbilityEnded(UGameplayAbility* Ability)
{
	if (bStopWhenAbilityEnds && GetAbility() == Ability)
	{
		FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

		// Check if the montage is still playing
		if (MontageInstance && MontageInstance->IsPlaying())
		{
			MontageInstance->Stop(GetMontageToPlay()->BlendOut);
		}
	}
}

ULGAAction_PlayMontage_Base::ULGAAction_PlayMontage_Base()
	: PlayRate(1.f)
	  , bStopWhenAbilityEnds(true)
	  , bStopWhenActionEnds(false)
{
#if WITH_EDITORONLY_DATA
	bSupportPreview = true;
#endif

#if WITH_EDITOR
	UObject* Outermost = GetOutermostObject();
	if (Outermost->HasAnyFlags(RF_Standalone))
	{
		FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(
			this, &ULGAAction_PlayMontage_Base::OnObjectPropertyChanged);
	}
#endif
}

void ULGAAction_PlayMontage_Base::BeginDestroy()
{
#if WITH_EDITOR
	UObject* Outermost = GetOutermostObject();
	if (Outermost->HasAnyFlags(RF_Standalone))
	{
		FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
	}
#endif

	Super::BeginDestroy();
}


void ULGAAction_PlayMontage_Base::ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime)
{
	MontageInstanceID = INDEX_NONE;

	float TimelinePlayRate = 1.f;
	if (ULegoAbility* Ability = GetAbility())
	{
		if (ULGATask_PlayTimeline* PlayTimelineTask = Ability->GetPlayTimelineTask())
		{
			TimelinePlayRate = PlayTimelineTask->GetPlayRate();
		}
	}

	ULegoAbility* Ability = GetAbility();
	if (UAnimInstance* AnimInstance = GetAnimInstance(GetAvatarActor()))
	{
		float DefaultPlayRate = TimelinePlayRate * PlayRate;
		float Duration = AnimInstance->Montage_Play(GetMontageToPlay(), DefaultPlayRate, EMontagePlayReturnType::MontageLength, BeginTime);
		if (Duration > 0.f)
		{
			if (StartSection != NAME_None)
			{
				AnimInstance->Montage_JumpToSection(StartSection, GetMontageToPlay());
			}

			FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(GetMontageToPlay());

			if (MontageInstance)
			{
				MontageInstanceID = MontageInstance->GetInstanceID();
				MontageInstance->SetNextPositionWithEvents(ElapsedTime);
				MontageInstance->CustomEndPredictionRate = DefaultPlayRate;

				MontageInstance->OnMontageBlendingOutStarted.BindUObject(this, &ULGAAction_PlayMontage_Base::OnMontageBlendOut);
				MontageInstance->OnMontageEnded.BindUObject(this, &ULGAAction_PlayMontage_Base::OnMontageCompleted);

				Ability->OnGameplayAbilityEnded.RemoveAll(this);
				Ability->OnGameplayAbilityEnded.AddUObject(this, &ULGAAction_PlayMontage_Base::OnAbilityEnded);
			}
		}
	}
}

void ULGAAction_PlayMontage_Base::ActionSkip(float ElapsedTime, float TotalDuration)
{
	FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

	if (MontageInstance && MontageInstance->IsPlaying())
	{
		float NextPosition = ElapsedTime * PlayRate;
		MontageInstance->SetPosition(FMath::Min(NextPosition, TotalDuration));
		MontageInstance->SetNextPositionWithEvents(FMath::Min(NextPosition, TotalDuration));

		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Warning, TEXT("Play Montage Base [%s %d] Skip [Elapsed:%f][Total:%f][Current:%f]"), *GetMontageToPlay()->GetName(), MontageInstanceID, ElapsedTime, TotalDuration, MontageInstance->GetPosition());
		}
	}
	else
	{
		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Error, TEXT("Play Montage Base [%s %d] Skip [Elapsed:%f][Total:%f]"), *GetMontageToPlay()->GetName(), MontageInstanceID, ElapsedTime, TotalDuration);
		}
	}
}

void ULGAAction_PlayMontage_Base::ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime)
{
	FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

	if (MontageInstance && MontageInstance->IsPlaying() && (!IsLoopAction() || !GetTimeline()->bLooping))
	{
		float NextPosition = ElapsedTime * PlayRate;
		MontageInstance->SetNextPositionWithEvents(NextPosition);

		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Warning, TEXT("Play Montage Base [%s %d] Tick [Elapsed:%f][Total:%f][Current:%f]"), *GetMontageToPlay()->GetName(), MontageInstanceID, ElapsedTime, TotalDuration, MontageInstance->GetPosition());
		}
	}
	else
	{
		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Error, TEXT("Play Montage Base [%s %d] Tick [Elapsed:%f][Total:%f]"), *GetMontageToPlay()->GetName(), MontageInstanceID, ElapsedTime, TotalDuration);
		}
	}
}

void ULGAAction_PlayMontage_Base::ActionEnd(bool bAbilityFinished, bool bActionFinished)
{
	if (bStopWhenActionEnds)
	{
		FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

		// Check if the montage is still playing
		if (MontageInstance && MontageInstance->IsPlaying())
		{
			MontageInstance->Stop(GetMontageToPlay()->BlendOut);
		}
	}
}

FString ULGAAction_PlayMontage_Base::GetActionName_Implementation() const
{
	return TEXT("Play Montage");
}

#if WITH_EDITOR
float ULGAAction_PlayMontage_Base::GetPlayLength() const
{
	float TotalLength = 0.f;
	TArray<int32> SectionIndices;
	FName SectionName = StartSection;

	UAnimMontage* Montage = GetMontageToPlay();
	do
	{
		int32 SectionIdx = Montage->GetSectionIndex(SectionName);
		if (SectionIdx == INDEX_NONE)
		{
			SectionIdx = 0;
		}

		if (SectionIndices.Contains(SectionIdx))
		{
			break;
		}

		SectionIndices.Add(SectionIdx);
		TotalLength += Montage->RateScale != 0
			               ? Montage->GetSectionLength(SectionIdx) / Montage->RateScale
			               : Montage->GetSectionLength(SectionIdx);
		SectionName = Montage->GetAnimCompositeSection(SectionIdx).NextSectionName;
	}
	while (SectionName != NAME_None && Montage->GetSectionIndex(SectionName) != INDEX_NONE);

	return PlayRate > 0.f ? TotalLength / PlayRate : TotalLength;
}

void ULGAAction_PlayMontage_Base::BeginPreview(AActor* PreviewActor, float TotalDuration)
{
	if (!GetMontageToPlay())
	{
		return;
	}

	UAnimInstance* AnimInstance = GetAnimInstance(PreviewActor);
	if (AnimInstance)
	{
		AnimInstance->Montage_Play(GetMontageToPlay());
		AnimInstance->Montage_Pause(GetMontageToPlay());
	}

}


void ULGAAction_PlayMontage_Base::SetPosition(AActor* PreviewActor, float Position, float TotalDuration)
{
	if (!GetMontageToPlay())
	{
		return;
	}

	Position *= PlayRate;

	{
		UAnimInstance* AnimInstance = GetAnimInstance(PreviewActor);
		if (AnimInstance)
		{
			int32 SectionIdx;
			FName SectionName = StartSection;
			UAnimMontage* Montage = GetMontageToPlay();

			do
			{
				SectionIdx = Montage->GetSectionIndex(SectionName);
				if (SectionIdx == INDEX_NONE)
				{
					SectionIdx = 0;
				}

				float SectionStart, SectionEnd;
				Montage->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
				float Length = Montage->GetSectionLength(SectionIdx);
				if (Position < Length)
				{
					break;
				}

				Position -= Length;
				SectionName = Montage->GetAnimCompositeSection(SectionIdx).NextSectionName;
			}
			while (SectionName != NAME_None && Montage->GetSectionIndex(SectionName) != INDEX_NONE);

			FCompositeSection& Section = Montage->GetAnimCompositeSection(SectionIdx);
			if (!AnimInstance->Montage_IsActive(Montage))
			{
				AnimInstance->Montage_Play(Montage);
				AnimInstance->Montage_Pause(Montage);
			}
			AnimInstance->Montage_SetPosition(Montage, Section.GetTime() + Position);

		}
	}
}

void ULGAAction_PlayMontage_Base::EndPreview(AActor* PreviewActor)
{
	if (!GetMontageToPlay())
	{
		return;
	}


	UAnimInstance* AnimInstance = GetAnimInstance(PreviewActor);
	if (AnimInstance)
	{
		AnimInstance->Montage_Stop(0.f, GetMontageToPlay());
	}
	
}

void ULGAAction_PlayMontage_Base::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, Animation)
		|| PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, StartSection)
		|| PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, PlayRate)
	)
	{
		if (GetMontageToPlay())
		{
			if (StartSection == NAME_None || GetMontageToPlay()->IsValidSectionName(StartSection))
			{
				SetActionNodeDuration(GetPlayLength());
			}
			else
			{
				StartSection = NAME_None;
			}
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void ULGAAction_PlayMontage_Base::OnObjectPropertyChanged(UObject* Object, FPropertyChangedEvent& PropChangedEvent)
{
	if (Object == Animation)
	{
		if (StartSection == NAME_None || GetMontageToPlay()->IsValidSectionName(StartSection))
		{
			SetActionNodeDuration(GetPlayLength());
		}
		else
		{
			StartSection = NAME_None;
		}
	}
}

#endif


FAnimMontageInstance* ULGAAction_PlayMontage_Base::GetCurrentMontageInstance()
{
	UAnimInstance* AnimInstance = GetAnimInstance(GetAvatarActor());
	if (!AnimInstance)
	{
		return nullptr;
	}

	FAnimMontageInstance* MontageInstance = AnimInstance->GetMontageInstanceForID(MontageInstanceID);
	return MontageInstance;
}