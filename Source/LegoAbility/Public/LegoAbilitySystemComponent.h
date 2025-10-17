// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LegoAbilitySystemComponent.generated.h"

class ULegoAbility;
class ULGAAction_PlayMontage;

/**
 * 
 */
UCLASS()
class LEGOABILITY_API ULegoAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
	
public:
	TWeakObjectPtr<ULegoAbility> CurrentPreActiveAbility;
	
	TArray<ULGAAction_PlayMontage*> ActiveMontageActions;
};
