#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AdvancedAnimPlayerActorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UAdvancedAnimPlayerActorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class LEGOABILITY_API IAdvancedAnimPlayerActorInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "LegoAbility")
	void SetDisableSliding(bool DisableSliding);
};
