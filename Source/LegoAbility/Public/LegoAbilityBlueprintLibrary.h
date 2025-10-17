// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Actions/LGAAction_Executable.h"
#include "LegoAbilityBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LEGOABILITY_API ULegoAbilityBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/** Returns all actors targeted */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static TArray<AActor*> GetAllActorsFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle);

	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FGameplayAbilityTargetDataHandle GetTargetDataFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle);

	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static const FGameplayEventData GetGameplayEventDataFromActionContext(const FLGAActionExecutionContextHandle& ContextHandle);

	/** Creates a action execution context with a single hit result */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromHitResult(const FHitResult& HitResult);

	/** Creates a action execution context with multi results */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromHitResults(const TArray<FHitResult>& HitResults);

	/** Creates a action execute context with single actor target */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromActor(AActor* Actor);

	/** Creates a action execute context with multi actor targets */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromActors(TArray<AActor*> Actors);

	/** Creates a action execute context with single target data handle */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromTargetData(FGameplayAbilityTargetDataHandle TargetData);

	/** Creates a action execute context with single actor target */
	UFUNCTION(BlueprintPure, Category = "Ability|TargetData")
	static FLGAActionExecutionContextHandle	ActionContextFromGameplayEvent(const FGameplayEventData& EventData);


	UFUNCTION(BlueprintCallable, Category = "Ability|Timeline")
	static bool	SampleSocketTransformFromTimeline(AActor* Avator, ULGATimeline* Timeline, float SampleTime, FName SocketName, FTransform& OutTransform, bool bExtractRootMotion = true);
};
