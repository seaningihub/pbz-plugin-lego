// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityBlueprintLibrary.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Actions/LGAAction_Executable.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAbilityTargetDataHandle();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayEventData();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromActor *************
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromActor_Parms
	{
		AActor* Actor;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execute context with single actor target */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execute context with single actor target" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromActor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromActor", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromActor)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromActor(Z_Param_Actor);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromActor ***************

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromActors ************
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromActors_Parms
	{
		TArray<AActor*> Actors;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execute context with multi actor targets */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execute context with multi actor targets" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromActors_Parms, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromActors_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_Actors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromActors", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromActors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromActors)
{
	P_GET_TARRAY(AActor*,Z_Param_Actors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromActors(Z_Param_Actors);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromActors **************

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromGameplayEvent *****
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromGameplayEvent_Parms
	{
		FGameplayEventData EventData;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execute context with single actor target */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execute context with single actor target" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromGameplayEvent_Parms, EventData), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventData_MetaData), NewProp_EventData_MetaData) }; // 924940328
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromGameplayEvent_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::NewProp_EventData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromGameplayEvent", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromGameplayEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromGameplayEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromGameplayEvent)
{
	P_GET_STRUCT_REF(FGameplayEventData,Z_Param_Out_EventData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromGameplayEvent(Z_Param_Out_EventData);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromGameplayEvent *******

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromHitResult *********
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromHitResult_Parms
	{
		FHitResult HitResult;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execution context with a single hit result */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execution context with a single hit result" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitResult_MetaData), NewProp_HitResult_MetaData) }; // 267591329
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromHitResult_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromHitResult", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromHitResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromHitResult)
{
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromHitResult(Z_Param_Out_HitResult);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromHitResult ***********

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromHitResults ********
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromHitResults_Parms
	{
		TArray<FHitResult> HitResults;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execution context with multi results */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execution context with multi results" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitResults_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResults_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HitResults;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_HitResults_Inner = { "HitResults", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 267591329
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_HitResults = { "HitResults", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromHitResults_Parms, HitResults), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitResults_MetaData), NewProp_HitResults_MetaData) }; // 267591329
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromHitResults_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_HitResults_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_HitResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromHitResults", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromHitResults_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromHitResults_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromHitResults)
{
	P_GET_TARRAY_REF(FHitResult,Z_Param_Out_HitResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromHitResults(Z_Param_Out_HitResults);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromHitResults **********

// ********** Begin Class ULegoAbilityBlueprintLibrary Function ActionContextFromTargetData ********
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics
{
	struct LegoAbilityBlueprintLibrary_eventActionContextFromTargetData_Parms
	{
		FGameplayAbilityTargetDataHandle TargetData;
		FLGAActionExecutionContextHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Creates a action execute context with single target data handle */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Creates a action execute context with single target data handle" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::NewProp_TargetData = { "TargetData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromTargetData_Parms, TargetData), Z_Construct_UScriptStruct_FGameplayAbilityTargetDataHandle, METADATA_PARAMS(0, nullptr) }; // 2587778715
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventActionContextFromTargetData_Parms, ReturnValue), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::NewProp_TargetData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "ActionContextFromTargetData", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromTargetData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::LegoAbilityBlueprintLibrary_eventActionContextFromTargetData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execActionContextFromTargetData)
{
	P_GET_STRUCT(FGameplayAbilityTargetDataHandle,Z_Param_TargetData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLGAActionExecutionContextHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::ActionContextFromTargetData(Z_Param_TargetData);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function ActionContextFromTargetData **********

// ********** Begin Class ULegoAbilityBlueprintLibrary Function GetAllActorsFromActionContext ******
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics
{
	struct LegoAbilityBlueprintLibrary_eventGetAllActorsFromActionContext_Parms
	{
		FLGAActionExecutionContextHandle ContextHandle;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "Comment", "/** Returns all actors targeted */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
		{ "ToolTip", "Returns all actors targeted" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextHandle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextHandle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ContextHandle = { "ContextHandle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetAllActorsFromActionContext_Parms, ContextHandle), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextHandle_MetaData), NewProp_ContextHandle_MetaData) }; // 522655166
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetAllActorsFromActionContext_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ContextHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "GetAllActorsFromActionContext", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetAllActorsFromActionContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetAllActorsFromActionContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execGetAllActorsFromActionContext)
{
	P_GET_STRUCT_REF(FLGAActionExecutionContextHandle,Z_Param_Out_ContextHandle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=ULegoAbilityBlueprintLibrary::GetAllActorsFromActionContext(Z_Param_Out_ContextHandle);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function GetAllActorsFromActionContext ********

// ********** Begin Class ULegoAbilityBlueprintLibrary Function GetGameplayEventDataFromActionContext 
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics
{
	struct LegoAbilityBlueprintLibrary_eventGetGameplayEventDataFromActionContext_Parms
	{
		FLGAActionExecutionContextHandle ContextHandle;
		FGameplayEventData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextHandle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextHandle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::NewProp_ContextHandle = { "ContextHandle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetGameplayEventDataFromActionContext_Parms, ContextHandle), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextHandle_MetaData), NewProp_ContextHandle_MetaData) }; // 522655166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetGameplayEventDataFromActionContext_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayEventData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 924940328
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::NewProp_ContextHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "GetGameplayEventDataFromActionContext", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetGameplayEventDataFromActionContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetGameplayEventDataFromActionContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execGetGameplayEventDataFromActionContext)
{
	P_GET_STRUCT_REF(FLGAActionExecutionContextHandle,Z_Param_Out_ContextHandle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayEventData*)Z_Param__Result=ULegoAbilityBlueprintLibrary::GetGameplayEventDataFromActionContext(Z_Param_Out_ContextHandle);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function GetGameplayEventDataFromActionContext 

// ********** Begin Class ULegoAbilityBlueprintLibrary Function GetTargetDataFromActionContext *****
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics
{
	struct LegoAbilityBlueprintLibrary_eventGetTargetDataFromActionContext_Parms
	{
		FLGAActionExecutionContextHandle ContextHandle;
		FGameplayAbilityTargetDataHandle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|TargetData" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextHandle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextHandle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::NewProp_ContextHandle = { "ContextHandle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetTargetDataFromActionContext_Parms, ContextHandle), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextHandle_MetaData), NewProp_ContextHandle_MetaData) }; // 522655166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventGetTargetDataFromActionContext_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayAbilityTargetDataHandle, METADATA_PARAMS(0, nullptr) }; // 2587778715
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::NewProp_ContextHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "GetTargetDataFromActionContext", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetTargetDataFromActionContext_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::LegoAbilityBlueprintLibrary_eventGetTargetDataFromActionContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execGetTargetDataFromActionContext)
{
	P_GET_STRUCT_REF(FLGAActionExecutionContextHandle,Z_Param_Out_ContextHandle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayAbilityTargetDataHandle*)Z_Param__Result=ULegoAbilityBlueprintLibrary::GetTargetDataFromActionContext(Z_Param_Out_ContextHandle);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function GetTargetDataFromActionContext *******

// ********** Begin Class ULegoAbilityBlueprintLibrary Function SampleSocketTransformFromTimeline **
struct Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics
{
	struct LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms
	{
		AActor* Avator;
		ULGATimeline* Timeline;
		float SampleTime;
		FName SocketName;
		FTransform OutTransform;
		bool bExtractRootMotion;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability|Timeline" },
		{ "CPP_Default_bExtractRootMotion", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Avator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleTime;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransform;
	static void NewProp_bExtractRootMotion_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExtractRootMotion;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_Avator = { "Avator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms, Avator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_SampleTime = { "SampleTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms, SampleTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms, SocketName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_OutTransform = { "OutTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms, OutTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_bExtractRootMotion_SetBit(void* Obj)
{
	((LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms*)Obj)->bExtractRootMotion = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_bExtractRootMotion = { "bExtractRootMotion", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms), &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_bExtractRootMotion_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms), &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_Avator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_Timeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_SampleTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_SocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_OutTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_bExtractRootMotion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityBlueprintLibrary, nullptr, "SampleSocketTransformFromTimeline", Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::LegoAbilityBlueprintLibrary_eventSampleSocketTransformFromTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityBlueprintLibrary::execSampleSocketTransformFromTimeline)
{
	P_GET_OBJECT(AActor,Z_Param_Avator);
	P_GET_OBJECT(ULGATimeline,Z_Param_Timeline);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SampleTime);
	P_GET_PROPERTY(FNameProperty,Z_Param_SocketName);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTransform);
	P_GET_UBOOL(Z_Param_bExtractRootMotion);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=ULegoAbilityBlueprintLibrary::SampleSocketTransformFromTimeline(Z_Param_Avator,Z_Param_Timeline,Z_Param_SampleTime,Z_Param_SocketName,Z_Param_Out_OutTransform,Z_Param_bExtractRootMotion);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityBlueprintLibrary Function SampleSocketTransformFromTimeline ****

// ********** Begin Class ULegoAbilityBlueprintLibrary *********************************************
void ULegoAbilityBlueprintLibrary::StaticRegisterNativesULegoAbilityBlueprintLibrary()
{
	UClass* Class = ULegoAbilityBlueprintLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ActionContextFromActor", &ULegoAbilityBlueprintLibrary::execActionContextFromActor },
		{ "ActionContextFromActors", &ULegoAbilityBlueprintLibrary::execActionContextFromActors },
		{ "ActionContextFromGameplayEvent", &ULegoAbilityBlueprintLibrary::execActionContextFromGameplayEvent },
		{ "ActionContextFromHitResult", &ULegoAbilityBlueprintLibrary::execActionContextFromHitResult },
		{ "ActionContextFromHitResults", &ULegoAbilityBlueprintLibrary::execActionContextFromHitResults },
		{ "ActionContextFromTargetData", &ULegoAbilityBlueprintLibrary::execActionContextFromTargetData },
		{ "GetAllActorsFromActionContext", &ULegoAbilityBlueprintLibrary::execGetAllActorsFromActionContext },
		{ "GetGameplayEventDataFromActionContext", &ULegoAbilityBlueprintLibrary::execGetGameplayEventDataFromActionContext },
		{ "GetTargetDataFromActionContext", &ULegoAbilityBlueprintLibrary::execGetTargetDataFromActionContext },
		{ "SampleSocketTransformFromTimeline", &ULegoAbilityBlueprintLibrary::execSampleSocketTransformFromTimeline },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary;
UClass* ULegoAbilityBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityBlueprintLibrary;
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityBlueprintLibrary"),
			Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesULegoAbilityBlueprintLibrary,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary_NoRegister()
{
	return ULegoAbilityBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "LegoAbilityBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActor, "ActionContextFromActor" }, // 3747788666
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromActors, "ActionContextFromActors" }, // 1649389929
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromGameplayEvent, "ActionContextFromGameplayEvent" }, // 1461784695
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResult, "ActionContextFromHitResult" }, // 297027173
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromHitResults, "ActionContextFromHitResults" }, // 2917820257
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_ActionContextFromTargetData, "ActionContextFromTargetData" }, // 1013919184
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetAllActorsFromActionContext, "GetAllActorsFromActionContext" }, // 990778593
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetGameplayEventDataFromActionContext, "GetGameplayEventDataFromActionContext" }, // 876069989
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_GetTargetDataFromActionContext, "GetTargetDataFromActionContext" }, // 3117555140
		{ &Z_Construct_UFunction_ULegoAbilityBlueprintLibrary_SampleSocketTransformFromTimeline, "SampleSocketTransformFromTimeline" }, // 232109148
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::ClassParams = {
	&ULegoAbilityBlueprintLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.OuterSingleton, Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary.OuterSingleton;
}
ULegoAbilityBlueprintLibrary::ULegoAbilityBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityBlueprintLibrary);
ULegoAbilityBlueprintLibrary::~ULegoAbilityBlueprintLibrary() {}
// ********** End Class ULegoAbilityBlueprintLibrary ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityBlueprintLibrary, ULegoAbilityBlueprintLibrary::StaticClass, TEXT("ULegoAbilityBlueprintLibrary"), &Z_Registration_Info_UClass_ULegoAbilityBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityBlueprintLibrary), 4231995178U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h__Script_LegoAbility_3234520247(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
