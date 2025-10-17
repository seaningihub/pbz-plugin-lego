// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "LegoAbilityBlueprintGeneratedClass.generated.h"

class ULegoAbility;
class ULGATimeline;
class ULGAAction;

USTRUCT(BlueprintType)
struct FLGAActionOverride
{
	GENERATED_BODY()

	UPROPERTY()
	FName TimelineName;

	UPROPERTY()
	TMap<FGuid, ULGAAction*> Overrides;

	UPROPERTY()
	FName TimeStretchCurveName;

	UPROPERTY()
	float StartTimeSeconds;

	UPROPERTY()
	TArray<struct FLGATimelineBlendSetting> DynamicBlendSettings;

	FLGAActionOverride()
		: StartTimeSeconds(0.f)
	{

	}
};

UCLASS()
class LEGOABILITY_API ULegoAbilityBlueprintGeneratedClass : public UBlueprintGeneratedClass
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<ULGATimeline*> AbilityTimelines;

	UPROPERTY()
	TArray<FLGAActionOverride> ActionOverrides;

public:
	void InitializeAbility(ULegoAbility* LegoAbility) const;

	TArray<const ULGATimeline*> GetAllTimelines() const;
};