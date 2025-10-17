// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LGATimeline.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LegoAbilityEditorUtils.generated.h"

struct FLGATimelineOverride;
class ULGATimeline;
class ULegoAbilityBlueprint;

USTRUCT(BlueprintType)
struct FLGAActionEventHandle
{
	GENERATED_BODY()

	FLGAActionEvent* Event;

	FLGAActionEventHandle();
	FLGAActionEventHandle(FLGAActionEvent* Event);
};

/**
 *
 */
UCLASS()
class LEGOABILITYEDITOR_API ULegoAbilityEditorUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static ULegoAbilityBlueprint* ToLegoAbilityBlueprint(UBlueprint* Blueprint);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void GetAbilityTimelines(ULegoAbilityBlueprint* Blueprint, TArray<ULGATimeline*>& Timelines);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static ULGATimeline* GetAbilityTimelineByName(ULegoAbilityBlueprint* Blueprint, FName TimelineName);

	UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void SetAbilityTimelines(ULegoAbilityBlueprint* Blueprint, const TArray<ULGATimeline*>& Timelines);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void GetOverridenTimelines(ULegoAbilityBlueprint* Blueprint, TArray<FLGATimelineOverride>& Timelines);

	UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void SetOverridenTimelines(ULegoAbilityBlueprint* Blueprint, const TArray<FLGATimelineOverride>& Timelines);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void GetTrackActionEvents(FLGAActionTrack Track, TArray<FLGAActionEventHandle>& ActionEvents);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void GetActionEventByHandle(const FLGAActionEventHandle& Handle, FLGAActionEvent& Event);

	UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext), Category = "LegoAbility")
	static void SetActionEventByHandle(const FLGAActionEventHandle& Handle, const FLGAActionEvent& Event);
};
