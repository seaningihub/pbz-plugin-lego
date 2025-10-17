// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actions/LGAAction_Executable.h"
#include "LegoAbilityTypes.h"
#include "LGAAction_CameraShakeBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class LEGOABILITY_API ULGAAction_CameraShakeBase : public ULGAAction_Executable
{
	GENERATED_BODY()
	
	
	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	UCameraShakeBase* AddCameraShake(const FLegoCameraShakePreviewerAddParams& Params);

	UFUNCTION(BlueprintCallable, Category = "LegoAbility")
	void RemoveCameraShake(UCameraShakeBase* ShakeInstance);

	UFUNCTION(BlueprintPure, Category = "LegoAbility")
	static float GetCameraShakeDuration(const TSubclassOf<UCameraShakeBase>& ShakeClass);
};
