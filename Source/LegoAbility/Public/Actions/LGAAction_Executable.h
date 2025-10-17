// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGAAction.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "LGAAction_Executable.generated.h"

/**
 * Ability Action execution context
 */
USTRUCT()
struct FLGAActionExecutionContext
{
	GENERATED_BODY()

public:
	FLGAActionExecutionContext() {}

	FLGAActionExecutionContext(FGameplayAbilityTargetDataHandle InTargetData)
	: TargetData(InTargetData)
	{}

	/** The polymorphic target information for the context */
	FGameplayAbilityTargetDataHandle TargetData;

	/** Gameplay event data */
	FGameplayEventData GameplayEventData;
};


USTRUCT(BlueprintType)
struct FLGAActionExecutionContextHandle
{
	GENERATED_BODY()

	FLGAActionExecutionContextHandle() {}

	virtual ~FLGAActionExecutionContextHandle()
	{
	}

	/** Constructs from an existing context, should be allocated by new */
	explicit FLGAActionExecutionContextHandle(FLGAActionExecutionContext* DataPtr)
	{
		Data = TSharedPtr<FLGAActionExecutionContext>(DataPtr);
	}

	/** Sets from an existing context, should be allocated by new */
	void operator=(FLGAActionExecutionContext* DataPtr)
	{
		Data = TSharedPtr<FLGAActionExecutionContext>(DataPtr);
	}

	void Clear()
	{
		Data.Reset();
	}

	bool IsValid() const
	{
		return Data.IsValid();
	}

	/** Returns Raw execution context, may be null */
	FLGAActionExecutionContext* Get()
	{
		return IsValid() ? Data.Get() : nullptr;
	}
	const FLGAActionExecutionContext* Get() const
	{
		return IsValid() ? Data.Get() : nullptr;
	}

private:
	TSharedPtr<FLGAActionExecutionContext> Data;
};


/**
 * Ability Action can be execute.
 */
UCLASS(Abstract, EditInlineNew)
class LEGOABILITY_API ULGAAction_Executable : public ULGAAction
{
	GENERATED_BODY()

public:
	ULGAAction_Executable();
	
	UFUNCTION(BlueprintNativeEvent)
	void ExecuteAction(FLGAActionExecutionContextHandle Context);
};