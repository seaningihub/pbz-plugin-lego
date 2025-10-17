// Copyright S-Game, Inc. All Rights Reserved.

#include "Actions/LGAAction_PlayMontage.h"
#include "LegoAbilitySystemComponent.h"
#include "Animation/AnimInstance.h"
#include "LegoAbility.h"
#include "GameFramework/Character.h"
#include "LegoAbilityBlueprintLibrary.h"
#include "LGATask_PlayTimeline.h"
#include "Interface/AdvancedAnimPlayerActorInterface.h"
#include "LegoAbilityLog.h"
#include "LGATimeline.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/LineBatchComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "BoneContainer.h"
#include "BonePose.h"

#if WITH_EDITOR
#include "AnimPreviewInstance.h"
#endif

void ULGAAction_PlayMontage::OnMontageBlendOut(UAnimMontage* Montage, bool bInterrupted)
{
	ULegoAbility* Ability = GetAbility();
	check(Ability);

	const bool bPlayingThisMontage = (Montage == MontageToPlay) && Ability && Ability->GetCurrentMontage() == MontageToPlay;
	if (bPlayingThisMontage)
	{
		// Reset AnimRootMotionTranslationScale
		ACharacter* Character = Cast<ACharacter>(GetAvatarActor());
		if (Character && (Character->GetLocalRole() == ROLE_Authority ||
			(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
		{
			Character->SetAnimRootMotionTranslationScale(1.f);
		}
	}

	if (bPlayingThisMontage)
	{
		if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
		{
			ASC->ClearAnimatingAbility(Ability);
		}
	}

	if (OnBlendOutAction)
	{
		FLGAActionExecutionContextHandle ContextHandle = ULegoAbilityBlueprintLibrary::ActionContextFromActor(
			GetAvatarActor());
		Ability->ExecuteAction(OnBlendOutAction, ContextHandle);
	}
}

void ULGAAction_PlayMontage::OnMontageCompleted(UAnimMontage* Montage, bool bInterrupted)
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

void ULGAAction_PlayMontage::OnAbilityEnded(UGameplayAbility* Ability)
{
	if (bStopWhenAbilityEnds && GetAbility() == Ability && !GetAbility()->IsInDynamicBlendOut())
	{
		FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

		// Check if the montage is still playing
		if (MontageInstance && MontageInstance->IsPlaying())
		{
			MontageInstance->Stop(MontageToPlay->BlendOut);

			if (ClampSpeedWhenCanceled > 0.f)
			{
				if (UCharacterMovementComponent* MoveComponent = GetAvatarActor()->GetComponentByClass<UCharacterMovementComponent>())
				{
					MoveComponent->Velocity = MoveComponent->Velocity.GetClampedToMaxSize2D(ClampSpeedWhenCanceled);
				}
			}
		}
	}
}

ULGAAction_PlayMontage::ULGAAction_PlayMontage()
	: PlayRate(1.f)
	  , bStopWhenAbilityEnds(true)
	  , bStopWhenActionEnds(false)
	  , AnimRootMotionTranslationScale(1.f)
	  , ClampSpeedWhenCanceled(0.f)
	  , bDisableSliding(false)
{
#if WITH_EDITORONLY_DATA
	bSupportPreview = true;
#endif

#if WITH_EDITOR
	UObject* Outermost = GetOutermostObject();
	if (Outermost->HasAnyFlags(RF_Standalone))
	{
		FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(
			this, &ULGAAction_PlayMontage::OnObjectPropertyChanged);
	}
#endif
}

void ULGAAction_PlayMontage::BeginDestroy()
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


void ULGAAction_PlayMontage::ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime)
{
	MontageInstanceID = INDEX_NONE;

	float TimelinePlayRate = 1.f;
	const FLGATimelineBlendSetting* TimelineBlendSetting = nullptr;
	if (ULegoAbility* Ability = GetAbility())
	{
		if (ULGATask_PlayTimeline* PlayTimelineTask = Ability->GetPlayTimelineTask())
		{
			TimelinePlayRate = PlayTimelineTask->GetPlayRate();
			TimelineBlendSetting = PlayTimelineTask->GetDynamicTimelineBlendSetting();
		}
	}

	ULegoAbility* Ability = GetAbility();
	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
	if (AnimInstance != nullptr)
	{
		float DefaultPlayRate = TimelinePlayRate * PlayRate;
		float Duration = 0.f;
		float InitPosition = GetAnimPositionFromActionPosition(BeginTime);
		if (TimelineBlendSetting)
		{
			Duration = AnimInstance->Montage_PlayWithBlendSettings(MontageToPlay, TimelineBlendSetting->MontageBlendIn, DefaultPlayRate, EMontagePlayReturnType::MontageLength, InitPosition);
		}
		else
		{
			Duration = AnimInstance->Montage_Play(MontageToPlay, DefaultPlayRate, EMontagePlayReturnType::MontageLength, InitPosition);
		}
		
		if (Duration > 0.f)
		{
			if (StartSection != NAME_None)
			{
				AnimInstance->Montage_JumpToSection(StartSection, MontageToPlay);
			}

			FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay);

			if (MontageInstance)
			{
				MontageInstanceID = MontageInstance->GetInstanceID();
				MontageInstance->SetNextPositionWithEvents(GetAnimPositionFromActionPosition(ElapsedTime));
				MontageInstance->CustomEndPredictionRate = DefaultPlayRate;

				MontageInstance->OnMontageBlendingOutStarted.BindUObject(this, &ULGAAction_PlayMontage::OnMontageBlendOut);
				MontageInstance->OnMontageEnded.BindUObject(this, &ULGAAction_PlayMontage::OnMontageCompleted);

				ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor);
				if (Character && (Character->GetLocalRole() == ROLE_Authority ||
					(Character->GetLocalRole() == ROLE_AutonomousProxy && Ability->GetNetExecutionPolicy() == EGameplayAbilityNetExecutionPolicy::LocalPredicted)))
				{
					Character->SetAnimRootMotionTranslationScale(AnimRootMotionTranslationScale);
				}

				Ability->OnGameplayAbilityEnded.RemoveAll(this);
				Ability->OnGameplayAbilityEnded.AddUObject(this, &ULGAAction_PlayMontage::OnAbilityEnded);

				if (ULegoAbilitySystemComponent* LegoASC = Cast<ULegoAbilitySystemComponent>(GetAbilitySystemComponent()))
				{
					LegoASC->ActiveMontageActions.AddUnique(this);
				}
			}


			if (ActorInfo->AvatarActor.IsValid())
			{
				if (ActorInfo->AvatarActor->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()))
				{
					IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(ActorInfo->AvatarActor.Get(), bDisableSliding);
				}
			}
		}
	}
}

void ULGAAction_PlayMontage::ActionSkip(float ElapsedTime, float TotalDuration)
{
	FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

	if (MontageInstance && MontageInstance->IsPlaying())
	{
		float NextPosition = GetAnimPositionFromActionPosition(ElapsedTime);
		MontageInstance->SetPosition(NextPosition);
		MontageInstance->SetNextPositionWithEvents(NextPosition);

		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Warning, TEXT("Play Montage [%s %d] Skip [Elapsed:%f][Total:%f][Current:%f]"), *MontageToPlay->GetName(), MontageInstanceID, ElapsedTime, TotalDuration, MontageInstance->GetPosition());
		}
	}
	else
	{
		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Error, TEXT("Play Montage [%s %d] Skip [Elapsed:%f][Total:%f]"), *MontageToPlay->GetName(), MontageInstanceID, ElapsedTime, TotalDuration);
		}
	}
}

void ULGAAction_PlayMontage::ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime)
{
	FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

	if (MontageInstance && MontageInstance->IsPlaying() && (!IsLoopAction() || !GetTimeline()->bLooping))
	{
		float NextPosition = GetAnimPositionFromActionPosition(ElapsedTime);
		MontageInstance->SetNextPositionWithEvents(NextPosition);

		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Warning, TEXT("Play Montage [%s %d] Tick [Elapsed:%f][Total:%f][Current:%f]"), *MontageToPlay->GetName(), MontageInstanceID, ElapsedTime, TotalDuration, MontageInstance->GetPosition());
		}
	}
	else
	{
		if (bDebug)
		{
			UE_LOG(LogLegoAbility, Error, TEXT("Play Montage [%s %d] Tick [Elapsed:%f][Total:%f]"), *MontageToPlay->GetName(), MontageInstanceID, ElapsedTime, TotalDuration);
		}
	}
}

void ULGAAction_PlayMontage::ActionEnd(bool bAbilityFinished, bool bActionFinished)
{
	if (bStopWhenActionEnds)
	{
		FAnimMontageInstance* MontageInstance = GetCurrentMontageInstance();

		// Check if the montage is still playing
		if (MontageInstance && MontageInstance->IsPlaying())
		{
			MontageInstance->Stop(MontageToPlay->BlendOut);
		}
	}

	if (bDisableSliding)
	{
		if (AActor* Actor = GetAvatarActor())
		{
			if (Actor->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()))
			{
				IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(Actor, false);
			}
		}
	}

	if (ForceClampSpeed > 0.f)
	{
		if (UCharacterMovementComponent* MoveComponent = GetAvatarActor()->GetComponentByClass<UCharacterMovementComponent>())
		{
			MoveComponent->Velocity = MoveComponent->Velocity.GetClampedToMaxSize2D(ForceClampSpeed);
		}
	}

	if (ULegoAbilitySystemComponent* LegoASC = Cast<ULegoAbilitySystemComponent>(GetAbilitySystemComponent()))
	{
		LegoASC->ActiveMontageActions.Remove(this);
	}
}


bool ULGAAction_PlayMontage::SampleSocketTransform(AActor* Owner, float SampleTime, FName BoneName, FTransform& OutTransform, bool bExtractRootMotion)
{
	if (ACharacter* Character = Cast<ACharacter>(Owner); MontageToPlay && SampleTime >= 0.f && Character)
	{
		float SamplePosition = SampleTime * PlayRate;
		FName SectionName = StartSection;
		int32 SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
		if (SectionIdx == INDEX_NONE)
		{
			SectionIdx = 0;
		}
		
		float SectionLength = MontageToPlay->GetSectionLength(SectionIdx) / MontageToPlay->RateScale;
		while (SamplePosition > SectionLength)
		{
			SamplePosition -= SectionLength;

			FName NextSectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;
			if (NextSectionName == NAME_None)
			{
				break;
			}
			
			SectionIdx = MontageToPlay->GetSectionIndex(NextSectionName);
			SectionLength = MontageToPlay->GetSectionLength(SectionIdx) / MontageToPlay->RateScale;
		}

		float SectionStart, SectionEnd;
		MontageToPlay->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
		float MontagePosition = SectionStart + SamplePosition;

		FAnimExtractContext ExtractionContext;
		ExtractionContext.CurrentTime = MontagePosition;
		ExtractionContext.bExtractRootMotion = bExtractRootMotion;

		FAnimTrack& AnimTrack = MontageToPlay->SlotAnimTracks[0].AnimTrack;
		USkeletalMesh* SkelMesh = Character->GetMesh()->GetSkeletalMeshAsset();
		if (!SkelMesh)
		{
			return false;
		}
		const FReferenceSkeleton& RefSkeleton = SkelMesh->GetRefSkeleton();
		FMemMark Mark(FMemStack::Get());
		FCompactPose OutPose;
		UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance();
		if (!AnimInstance)
		{
			return false;
		}
		const FBoneContainer& RequiredBones = AnimInstance->GetRequiredBones();
		if (!ensure(RequiredBones.IsValid()))
		{
			return false;
		}
		OutPose.SetBoneContainer(&RequiredBones);
		FBlendedCurve OutCurve;
		UE::Anim::FStackAttributeContainer Attributes;
		FAnimationPoseData AnimationPoseData(OutPose, OutCurve, Attributes);
		AnimTrack.GetAnimationPose(AnimationPoseData, ExtractionContext);

		int32 BoneIndex = RefSkeleton.FindBoneIndex(BoneName);
		if (BoneIndex == INDEX_NONE)
		{
			return false;
		}

		const auto& Bones = OutPose.GetBones();

		FTransform BoneTransform = Bones[BoneIndex];
		int32 ParentIndex = RefSkeleton.GetParentIndex(BoneIndex);
		while (ParentIndex != INDEX_NONE)
		{
			FTransform ParentTransform = Bones[ParentIndex];
			BoneTransform = BoneTransform * ParentTransform;

			ParentIndex = RefSkeleton.GetParentIndex(ParentIndex);
		}

		OutTransform = BoneTransform;

		return true;
	}
	return false;
}

bool ULGAAction_PlayMontage::CalculateRootmotion(float BeginTime, float EndTime, FRootMotionMovementParams& OutRootMotionMovmentParams)
{
	if (!MontageToPlay || BeginTime >= EndTime || EndTime <= 0.f)
	{
		return false;
	}

	FName SectionName = StartSection;
	do
	{
		int32 SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
		if (SectionIdx == INDEX_NONE)
		{
			SectionIdx = 0;
		}

		float SectionStart, SectionEnd;
		MontageToPlay->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
		float Length = MontageToPlay->GetSectionLength(SectionIdx);
		if (BeginTime <= Length)
		{
			if (EndTime < Length)
			{
				SectionEnd = SectionStart + EndTime;
			}

			SectionStart += FMath::Max(BeginTime, 0.f);

			OutRootMotionMovmentParams.Accumulate(MontageToPlay->ExtractRootMotionFromTrackRange(SectionStart, SectionEnd));
		}

		BeginTime -= Length;
		EndTime -= Length;

		SectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;
	} while (EndTime > 0.f && SectionName != NAME_None && MontageToPlay->GetSectionIndex(SectionName) != INDEX_NONE);

	return true;
}

float ULGAAction_PlayMontage::GetTimelinePositionFromAnimPosition(float AnimPosition)
{
	if (!MontageToPlay)
	{
		return -1.f;
	}

	ULGATimeline* Timeline = GetTimeline();
	if (!Timeline)
	{
		return -1.f;
	}

	const FLGAActionEvent* ActionEvent = Timeline->GetActionEventByAction(this);
	if (!ActionEvent)
	{
		return -1.f;
	}

	TArray<int32> SectionIndices;
	FName SectionName = StartSection;
	
	float MontagePosition = 0.f;
	float AnimPlayRate = PlayRate * MontageToPlay->RateScale;

	do
	{
		int32 SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
		if (SectionIdx == INDEX_NONE)
		{
			SectionIdx = 0;
		}

		if (SectionIndices.Contains(SectionIdx))
		{
			break;
		}

		SectionIndices.Add(SectionIdx);

		float SectionStart, SectionEnd;
		MontageToPlay->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
		if (AnimPosition >= SectionStart && AnimPosition < SectionEnd)
		{
			float ActionPosition = (MontagePosition + AnimPosition - SectionStart) / (AnimPlayRate != 0 ? AnimPlayRate : 1.f);
			return ActionEvent->GetStartTime() + ActionPosition;
		}

		MontagePosition += MontageToPlay->GetSectionLength(SectionIdx);
		SectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;
	} while (SectionName != NAME_None && MontageToPlay->GetSectionIndex(SectionName) != INDEX_NONE);

	return -1.f;
}

float ULGAAction_PlayMontage::GetAnimPositionFromActionPosition(float ActionPosition)
{
	if (!MontageToPlay)
	{
		return -1.f;
	}

	FName SectionName = StartSection;
	int32 SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
	if (SectionIdx == INDEX_NONE)
	{
		SectionIdx = 0;
	}


	float AnimPlayRate = PlayRate * MontageToPlay->RateScale;
	float MontagePosition = ActionPosition * (AnimPlayRate != 0 ? AnimPlayRate : 1.f);

	float SectionLength = MontageToPlay->GetSectionLength(SectionIdx);
	while (MontagePosition > SectionLength)
	{
		MontagePosition -= SectionLength;

		FName NextSectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;
		if (NextSectionName == NAME_None)
		{
			return -1.f;
		}

		SectionIdx = MontageToPlay->GetSectionIndex(NextSectionName);
		SectionLength = MontageToPlay->GetSectionLength(SectionIdx);
	}

	float SectionStart, SectionEnd;
	MontageToPlay->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
	MontagePosition += SectionStart;

	return MontagePosition;
}

float ULGAAction_PlayMontage::GetAnimPositionFromTimelinePosition(float TimelinePosition)
{
	if (!MontageToPlay)
	{
		return -1.f;
	}

	ULGATimeline* Timeline = GetTimeline();
	if (!Timeline)
	{
		return -1.f;
	}

	const FLGAActionEvent* ActionEvent = Timeline->GetActionEventByAction(this);
	if (!ActionEvent || TimelinePosition < ActionEvent->GetStartTime() || TimelinePosition >= ActionEvent->GetEndTime())
	{
		return -1.f;
	}


	float ActionPosition = TimelinePosition - ActionEvent->GetStartTime();

	return GetAnimPositionFromActionPosition(ActionPosition);
}

FString ULGAAction_PlayMontage::GetActionName_Implementation() const
{
	return TEXT("Play Montage");
}

#if WITH_EDITOR
float ULGAAction_PlayMontage::GetPlayLength() const
{
	float TotalLength = 0.f;
	TArray<int32> SectionIndices;
	FName SectionName = StartSection;

	do
	{
		int32 SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
		if (SectionIdx == INDEX_NONE)
		{
			SectionIdx = 0;
		}

		if (SectionIndices.Contains(SectionIdx))
		{
			break;
		}

		SectionIndices.Add(SectionIdx);
		TotalLength += MontageToPlay->RateScale != 0
			               ? MontageToPlay->GetSectionLength(SectionIdx) / MontageToPlay->RateScale
			               : MontageToPlay->GetSectionLength(SectionIdx);
		SectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;
	}
	while (SectionName != NAME_None && MontageToPlay->GetSectionIndex(SectionName) != INDEX_NONE);

	return PlayRate > 0.f ? TotalLength / PlayRate : TotalLength;
}

void ULGAAction_PlayMontage::BeginPreview(AActor* PreviewActor, float TotalDuration)
{
	if (!MontageToPlay)
	{
		return;
	}

	if (ACharacter* Character = Cast<ACharacter>(PreviewActor))
	{
		USkeletalMeshComponent* Mesh = Character->GetMesh();

		UAnimPreviewInstance* AnimInstance = NewObject<UAnimPreviewInstance>(Mesh);

		Mesh->SetAnimationMode(EAnimationMode::AnimationCustomMode);
		Mesh->AnimScriptInstance = AnimInstance;
		AnimInstance->InitializeAnimation();

		AnimInstance->SetAnimationAsset(MontageToPlay, false, 0.f);
		
		DefaultPreviewActorTransfrom = PreviewActor->GetActorTransform();

		if (UCharacterMovementComponent* Movement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent()))
		{
			PreviousMode = Movement->MovementMode;
			Movement->SetMovementMode(MOVE_None);
		}
	}
}

ULineBatchComponent* GetDebugLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground)
{
	return (InWorld ? (bDepthIsForeground ? InWorld->GetLineBatcher(UWorld::ELineBatcherType::Foreground) : ((bPersistentLines || (LifeTime > 0.f)) ? InWorld->GetLineBatcher(UWorld::ELineBatcherType::WorldPersistent) : InWorld->GetLineBatcher(UWorld::ELineBatcherType::World))) : nullptr);
}

void ULGAAction_PlayMontage::SetPosition(AActor* PreviewActor, float Position, float TotalDuration)
{
	if (!MontageToPlay)
	{
		return;
	}

	float MontagePosition = Position * PlayRate * MontageToPlay->RateScale;

	if (ACharacter* Character = Cast<ACharacter>(PreviewActor))
	{
		UAnimInstance* AnimInstance = Character->GetMesh() ? Character->GetMesh()->GetAnimInstance() : nullptr;
		if (AnimInstance)
		{
			int32 SectionIdx;
			FName SectionName = StartSection;
			FRootMotionMovementParams RootMotion;

			do
			{
				SectionIdx = MontageToPlay->GetSectionIndex(SectionName);
				if (SectionIdx == INDEX_NONE)
				{
					SectionIdx = 0;
				}

				float SectionStart, SectionEnd;
				MontageToPlay->GetSectionStartAndEndTime(SectionIdx, SectionStart, SectionEnd);
				float Length = MontageToPlay->GetSectionLength(SectionIdx);
				if (MontagePosition < Length)
				{
					RootMotion.Accumulate(MontageToPlay->ExtractRootMotionFromTrackRange(SectionStart, SectionStart + MontagePosition));
					break;
				}

				MontagePosition -= Length;
				SectionName = MontageToPlay->GetAnimCompositeSection(SectionIdx).NextSectionName;

				RootMotion.Accumulate(MontageToPlay->ExtractRootMotionFromTrackRange(SectionStart, SectionEnd));
			}
			while (SectionName != NAME_None && MontageToPlay->GetSectionIndex(SectionName) != INDEX_NONE);

			FCompositeSection& Section = MontageToPlay->GetAnimCompositeSection(SectionIdx);
			if (!AnimInstance->Montage_IsActive(MontageToPlay))
			{
				AnimInstance->Montage_PlayWithBlendIn(MontageToPlay, 0.f, 0.f);
			}

			FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay);
			if (MontageInstance)
			{
				MontageInstance->bPlaying = true;
				MontageInstance->SetWeight(1.f);
				MontageInstance->bEnableAutoBlendOut = false;
				MontageInstance->SetNextPositionWithEvents(Section.GetTime() + MontagePosition);
			}

			Character->SetActorTransform(DefaultPreviewActorTransfrom);
			FVector StartLineLocation = Character->GetMesh()->GetComponentLocation();

			FTransform CurrentRootmotion = RootMotion.GetRootMotionTransform();
			FTransform CurrentWorldRootmotion = Character->GetMesh()->ConvertLocalRootMotionToWorld(CurrentRootmotion);
			
			FTransform CurrentActorTransform = DefaultPreviewActorTransfrom;
			CurrentActorTransform.SetLocation(DefaultPreviewActorTransfrom.GetLocation() + CurrentWorldRootmotion.GetLocation());
			CurrentActorTransform.SetRotation(DefaultPreviewActorTransfrom.GetRotation() * CurrentWorldRootmotion.GetRotation());

			Character->SetActorTransform(CurrentActorTransform);
			FVector EndLineLocation = Character->GetMesh()->GetComponentLocation();


			// Debug Rootmotion
			uint32 BatchID = 983993;
			if (GEngine->GetNetMode(Character->GetWorld()) != NM_DedicatedServer)
			{
				if (ULineBatchComponent* const LineBatcher = GetDebugLineBatcher(Character->GetWorld(), true, -1.f, (0 == SDPG_Foreground)))
				{
					LineBatcher->ClearBatch(BatchID);
					if (bDebugRootMotion)
					{
						LineBatcher->DrawDirectionalArrow(StartLineLocation, EndLineLocation,
							25.f, FColor::Red, -1, 0, 3.f, BatchID);
					}
				}
			}
		}
	}
}

void ULGAAction_PlayMontage::EndPreview(AActor* PreviewActor)
{
	if (!MontageToPlay)
	{
		return;
	}

	if (ACharacter* Character = Cast<ACharacter>(PreviewActor))
	{
		UAnimInstance* AnimInstance = Character->GetMesh() ? Character->GetMesh()->GetAnimInstance() : nullptr;
		if (AnimInstance)
		{
			AnimInstance->Montage_Stop(0.f, MontageToPlay);
		}

		Character->SetActorTransform(DefaultPreviewActorTransfrom);

		if (UCharacterMovementComponent* Movement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent()))
		{
			Movement->SetMovementMode(PreviousMode);
		}
	}
}

void ULGAAction_PlayMontage::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, MontageToPlay)
		|| PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, StartSection)
		|| PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, PlayRate)
	)
	{
		if (MontageToPlay)
		{
			if (StartSection == NAME_None || MontageToPlay->IsValidSectionName(StartSection))
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

void ULGAAction_PlayMontage::OnObjectPropertyChanged(UObject* Object, FPropertyChangedEvent& PropChangedEvent)
{
	if (Object == MontageToPlay)
	{
		if (StartSection == NAME_None || MontageToPlay->IsValidSectionName(StartSection))
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


FAnimMontageInstance* ULGAAction_PlayMontage::GetCurrentMontageInstance()
{
	ULegoAbility* Ability = GetAbility();
	check(Ability);

	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	if (!ActorInfo)
	{
		return nullptr;
	}

	UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
	if (!AnimInstance)
	{
		return nullptr;
	}

	FAnimMontageInstance* MontageInstance = AnimInstance->GetMontageInstanceForID(MontageInstanceID);
	return MontageInstance;
}