// Copyright S-Game, Inc. All Rights Reserved.


#include "LegoAbilityBlueprintLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "LGATimeline.h"
#include "Actions/LGAAction_PlayMontage.h"
#include "GameFramework/Character.h"

TArray<AActor*> ULegoAbilityBlueprintLibrary::GetAllActorsFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle)
{
	TArray<AActor*>	Result;
	if (ContextHandle.IsValid())
	{
		return UAbilitySystemBlueprintLibrary::GetAllActorsFromTargetData(ContextHandle.Get()->TargetData);
	}
	return Result;
}

FGameplayAbilityTargetDataHandle ULegoAbilityBlueprintLibrary::GetTargetDataFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle)
{
	FGameplayAbilityTargetDataHandle ResultHandle;
	if (ContextHandle.IsValid())
	{
		ResultHandle = ContextHandle.Get()->TargetData;
	}
	return ResultHandle;
}

const FGameplayEventData ULegoAbilityBlueprintLibrary::GetGameplayEventDataFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle)
{
	if (ContextHandle.IsValid())
	{
		return ContextHandle.Get()->GameplayEventData;
	}
	return FGameplayEventData();
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromHitResult(const FHitResult& HitResult)
{
	// Construct TargetData
	FGameplayAbilityTargetData_SingleTargetHit* TargetData = new FGameplayAbilityTargetData_SingleTargetHit(HitResult);

	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext());
	Handle.Get()->TargetData.Add(TargetData);

	return Handle;
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromHitResults(const TArray<FHitResult>& HitResults)
{
	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext());
	
	// Add all hits
	for (const FHitResult& Hit : HitResults)
	{
		Handle.Get()->TargetData.Add(new FGameplayAbilityTargetData_SingleTargetHit(Hit));
	}

	return Handle;
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromActor(AActor* Actor)
{
	FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
	NewData->TargetActorArray.Add(Actor);

	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext());
	Handle.Get()->TargetData.Add(NewData);

	return Handle;
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromActors(TArray<AActor*> Actors)
{
	FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
	NewData->TargetActorArray.Append(Actors);

	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext());
	Handle.Get()->TargetData.Add(NewData);

	return Handle;
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromTargetData(FGameplayAbilityTargetDataHandle TargetData)
{
	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext(TargetData));

	return Handle;
}

FLGAActionExecutionContextHandle ULegoAbilityBlueprintLibrary::ActionContextFromGameplayEvent(const FGameplayEventData& EventData)
{
	// Construct context
	FLGAActionExecutionContextHandle Handle = FLGAActionExecutionContextHandle(new FLGAActionExecutionContext());
	Handle.Get()->GameplayEventData = EventData;

	return Handle;
}

bool ULegoAbilityBlueprintLibrary::SampleSocketTransformFromTimeline(AActor* Avator, ULGATimeline* Timeline, float SampleTime, FName SocketName, FTransform& OutTransform, bool bExtractRootMotion)
{
	ACharacter* Character = Cast<ACharacter>(Avator);
	if (!Timeline || !Character)
	{
		return false;
	}

	if (FLGAActionEvent* Event = Timeline->GetActionEventByClass(ULGAAction_PlayMontage::StaticClass(), SampleTime))
	{
		if (ULGAAction_PlayMontage* MontageAction = Cast<ULGAAction_PlayMontage>(Event->Action))
		{
			bool Result = MontageAction->SampleSocketTransform(Avator, SampleTime - Event->StartTime, SocketName, OutTransform, bExtractRootMotion);
			if (Result)
			{
				OutTransform *= Character->GetMesh()->GetComponentTransform();
			}
		}
	}

	return false;
}
