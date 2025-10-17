#pragma once

#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "Camera/CameraShakeBase.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "LegoAbilityTypes.generated.h"


USTRUCT(BlueprintType)
struct LEGOABILITY_API FGameplayEventTag
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Categories="GameplayEvent"), Category="GameplayEvent")
	FGameplayTag GameplayEventTag;

	bool IsValid() const
	{
		return GameplayEventTag.IsValid();
	}
};



// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULegoAbilityPreviewInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class LEGOABILITY_API ILegoAbilityPreviewInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void PostPreviewActorCreated();
};


USTRUCT(BlueprintType)
struct LEGOABILITY_API  FLegoCameraShakePreviewerAddParams
{
	GENERATED_USTRUCT_BODY()

	// The class of the shake.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	TSubclassOf<UCameraShakeBase> ShakeClass;

	// Optional shake source.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	TObjectPtr<const UCameraShakeSourceComponent> SourceComponent;

	// Start time of the shake, for scrubbing.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	float GlobalStartTime = 0.f;

	// Parameters to be passed to the shake's start method.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	float Scale = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	ECameraShakePlaySpace PlaySpace = ECameraShakePlaySpace::CameraLocal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	FRotator UserPlaySpaceRot = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LegoAbility")
	TOptional<float> DurationOverride;
};

DECLARE_DELEGATE_RetVal_OneParam(UCameraShakeBase*, FLegoEditorAddCameraShakeDelegate, const FLegoCameraShakePreviewerAddParams&);
DECLARE_DELEGATE_OneParam(FLegoEditorRemoveCameraShakeDelegate, UCameraShakeBase*);

