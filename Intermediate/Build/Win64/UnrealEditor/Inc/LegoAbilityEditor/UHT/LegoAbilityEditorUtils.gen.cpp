// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityEditorUtils.h"
#include "LegoAbilityBlueprint.h"
#include "LGATimeline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityEditorUtils() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEvent();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionTrack();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorUtils();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorUtils_NoRegister();
LEGOABILITYEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEventHandle();
LEGOABILITYEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineOverride();
UPackage* Z_Construct_UPackage__Script_LegoAbilityEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGAActionEventHandle *********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionEventHandle;
class UScriptStruct* FLGAActionEventHandle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionEventHandle, (UObject*)Z_Construct_UPackage__Script_LegoAbilityEditor(), TEXT("LGAActionEventHandle"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionEventHandle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
	nullptr,
	&NewStructOps,
	"LGAActionEventHandle",
	nullptr,
	0,
	sizeof(FLGAActionEventHandle),
	alignof(FLGAActionEventHandle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEventHandle()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEventHandle.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionEventHandle ***********************************************

// ********** Begin Class ULegoAbilityEditorUtils Function GetAbilityTimelineByName ****************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics
{
	struct LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms
	{
		ULegoAbilityBlueprint* Blueprint;
		FName TimelineName;
		ULGATimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms, Blueprint), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms, TimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms, ReturnValue), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_TimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "GetAbilityTimelineByName", Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::LegoAbilityEditorUtils_eventGetAbilityTimelineByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execGetAbilityTimelineByName)
{
	P_GET_OBJECT(ULegoAbilityBlueprint,Z_Param_Blueprint);
	P_GET_PROPERTY(FNameProperty,Z_Param_TimelineName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATimeline**)Z_Param__Result=ULegoAbilityEditorUtils::GetAbilityTimelineByName(Z_Param_Blueprint,Z_Param_TimelineName);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function GetAbilityTimelineByName ******************

// ********** Begin Class ULegoAbilityEditorUtils Function GetAbilityTimelines *********************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics
{
	struct LegoAbilityEditorUtils_eventGetAbilityTimelines_Parms
	{
		ULegoAbilityBlueprint* Blueprint;
		TArray<ULGATimeline*> Timelines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timelines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetAbilityTimelines_Parms, Blueprint), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Timelines_Inner = { "Timelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Timelines = { "Timelines", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetAbilityTimelines_Parms, Timelines), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Timelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::NewProp_Timelines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "GetAbilityTimelines", Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::LegoAbilityEditorUtils_eventGetAbilityTimelines_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::LegoAbilityEditorUtils_eventGetAbilityTimelines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execGetAbilityTimelines)
{
	P_GET_OBJECT(ULegoAbilityBlueprint,Z_Param_Blueprint);
	P_GET_TARRAY_REF(ULGATimeline*,Z_Param_Out_Timelines);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::GetAbilityTimelines(Z_Param_Blueprint,Z_Param_Out_Timelines);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function GetAbilityTimelines ***********************

// ********** Begin Class ULegoAbilityEditorUtils Function GetActionEventByHandle ******************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics
{
	struct LegoAbilityEditorUtils_eventGetActionEventByHandle_Parms
	{
		FLGAActionEventHandle Handle;
		FLGAActionEvent Event;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Handle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetActionEventByHandle_Parms, Handle), Z_Construct_UScriptStruct_FLGAActionEventHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Handle_MetaData), NewProp_Handle_MetaData) }; // 3937144925
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetActionEventByHandle_Parms, Event), Z_Construct_UScriptStruct_FLGAActionEvent, METADATA_PARAMS(0, nullptr) }; // 3071200278
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::NewProp_Handle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::NewProp_Event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "GetActionEventByHandle", Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::LegoAbilityEditorUtils_eventGetActionEventByHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::LegoAbilityEditorUtils_eventGetActionEventByHandle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execGetActionEventByHandle)
{
	P_GET_STRUCT_REF(FLGAActionEventHandle,Z_Param_Out_Handle);
	P_GET_STRUCT_REF(FLGAActionEvent,Z_Param_Out_Event);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::GetActionEventByHandle(Z_Param_Out_Handle,Z_Param_Out_Event);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function GetActionEventByHandle ********************

// ********** Begin Class ULegoAbilityEditorUtils Function GetOverridenTimelines *******************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics
{
	struct LegoAbilityEditorUtils_eventGetOverridenTimelines_Parms
	{
		ULegoAbilityBlueprint* Blueprint;
		TArray<FLGATimelineOverride> Timelines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Timelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timelines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetOverridenTimelines_Parms, Blueprint), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Timelines_Inner = { "Timelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGATimelineOverride, METADATA_PARAMS(0, nullptr) }; // 2625819498
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Timelines = { "Timelines", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetOverridenTimelines_Parms, Timelines), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2625819498
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Timelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::NewProp_Timelines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "GetOverridenTimelines", Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::LegoAbilityEditorUtils_eventGetOverridenTimelines_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::LegoAbilityEditorUtils_eventGetOverridenTimelines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execGetOverridenTimelines)
{
	P_GET_OBJECT(ULegoAbilityBlueprint,Z_Param_Blueprint);
	P_GET_TARRAY_REF(FLGATimelineOverride,Z_Param_Out_Timelines);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::GetOverridenTimelines(Z_Param_Blueprint,Z_Param_Out_Timelines);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function GetOverridenTimelines *********************

// ********** Begin Class ULegoAbilityEditorUtils Function GetTrackActionEvents ********************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics
{
	struct LegoAbilityEditorUtils_eventGetTrackActionEvents_Parms
	{
		FLGAActionTrack Track;
		TArray<FLGAActionEventHandle> ActionEvents;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Track;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionEvents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActionEvents;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_Track = { "Track", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetTrackActionEvents_Parms, Track), Z_Construct_UScriptStruct_FLGAActionTrack, METADATA_PARAMS(0, nullptr) }; // 395941141
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_ActionEvents_Inner = { "ActionEvents", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAActionEventHandle, METADATA_PARAMS(0, nullptr) }; // 3937144925
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_ActionEvents = { "ActionEvents", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventGetTrackActionEvents_Parms, ActionEvents), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3937144925
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_Track,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_ActionEvents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::NewProp_ActionEvents,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "GetTrackActionEvents", Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::LegoAbilityEditorUtils_eventGetTrackActionEvents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::LegoAbilityEditorUtils_eventGetTrackActionEvents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execGetTrackActionEvents)
{
	P_GET_STRUCT(FLGAActionTrack,Z_Param_Track);
	P_GET_TARRAY_REF(FLGAActionEventHandle,Z_Param_Out_ActionEvents);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::GetTrackActionEvents(Z_Param_Track,Z_Param_Out_ActionEvents);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function GetTrackActionEvents **********************

// ********** Begin Class ULegoAbilityEditorUtils Function SetAbilityTimelines *********************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics
{
	struct LegoAbilityEditorUtils_eventSetAbilityTimelines_Parms
	{
		ULegoAbilityBlueprint* Blueprint;
		TArray<ULGATimeline*> Timelines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timelines_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timelines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetAbilityTimelines_Parms, Blueprint), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Timelines_Inner = { "Timelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Timelines = { "Timelines", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetAbilityTimelines_Parms, Timelines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timelines_MetaData), NewProp_Timelines_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Timelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::NewProp_Timelines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "SetAbilityTimelines", Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::LegoAbilityEditorUtils_eventSetAbilityTimelines_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::LegoAbilityEditorUtils_eventSetAbilityTimelines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execSetAbilityTimelines)
{
	P_GET_OBJECT(ULegoAbilityBlueprint,Z_Param_Blueprint);
	P_GET_TARRAY_REF(ULGATimeline*,Z_Param_Out_Timelines);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::SetAbilityTimelines(Z_Param_Blueprint,Z_Param_Out_Timelines);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function SetAbilityTimelines ***********************

// ********** Begin Class ULegoAbilityEditorUtils Function SetActionEventByHandle ******************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics
{
	struct LegoAbilityEditorUtils_eventSetActionEventByHandle_Parms
	{
		FLGAActionEventHandle Handle;
		FLGAActionEvent Event;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Handle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Event_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetActionEventByHandle_Parms, Handle), Z_Construct_UScriptStruct_FLGAActionEventHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Handle_MetaData), NewProp_Handle_MetaData) }; // 3937144925
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetActionEventByHandle_Parms, Event), Z_Construct_UScriptStruct_FLGAActionEvent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Event_MetaData), NewProp_Event_MetaData) }; // 3071200278
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::NewProp_Handle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::NewProp_Event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "SetActionEventByHandle", Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::LegoAbilityEditorUtils_eventSetActionEventByHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::LegoAbilityEditorUtils_eventSetActionEventByHandle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execSetActionEventByHandle)
{
	P_GET_STRUCT_REF(FLGAActionEventHandle,Z_Param_Out_Handle);
	P_GET_STRUCT_REF(FLGAActionEvent,Z_Param_Out_Event);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::SetActionEventByHandle(Z_Param_Out_Handle,Z_Param_Out_Event);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function SetActionEventByHandle ********************

// ********** Begin Class ULegoAbilityEditorUtils Function SetOverridenTimelines *******************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics
{
	struct LegoAbilityEditorUtils_eventSetOverridenTimelines_Parms
	{
		ULegoAbilityBlueprint* Blueprint;
		TArray<FLGATimelineOverride> Timelines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timelines_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Timelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timelines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetOverridenTimelines_Parms, Blueprint), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Timelines_Inner = { "Timelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGATimelineOverride, METADATA_PARAMS(0, nullptr) }; // 2625819498
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Timelines = { "Timelines", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventSetOverridenTimelines_Parms, Timelines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timelines_MetaData), NewProp_Timelines_MetaData) }; // 2625819498
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Timelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::NewProp_Timelines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "SetOverridenTimelines", Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::LegoAbilityEditorUtils_eventSetOverridenTimelines_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::LegoAbilityEditorUtils_eventSetOverridenTimelines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execSetOverridenTimelines)
{
	P_GET_OBJECT(ULegoAbilityBlueprint,Z_Param_Blueprint);
	P_GET_TARRAY_REF(FLGATimelineOverride,Z_Param_Out_Timelines);
	P_FINISH;
	P_NATIVE_BEGIN;
	ULegoAbilityEditorUtils::SetOverridenTimelines(Z_Param_Blueprint,Z_Param_Out_Timelines);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function SetOverridenTimelines *********************

// ********** Begin Class ULegoAbilityEditorUtils Function ToLegoAbilityBlueprint ******************
struct Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics
{
	struct LegoAbilityEditorUtils_eventToLegoAbilityBlueprint_Parms
	{
		UBlueprint* Blueprint;
		ULegoAbilityBlueprint* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventToLegoAbilityBlueprint_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbilityEditorUtils_eventToLegoAbilityBlueprint_Parms, ReturnValue), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityEditorUtils, nullptr, "ToLegoAbilityBlueprint", Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::LegoAbilityEditorUtils_eventToLegoAbilityBlueprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::LegoAbilityEditorUtils_eventToLegoAbilityBlueprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbilityEditorUtils::execToLegoAbilityBlueprint)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULegoAbilityBlueprint**)Z_Param__Result=ULegoAbilityEditorUtils::ToLegoAbilityBlueprint(Z_Param_Blueprint);
	P_NATIVE_END;
}
// ********** End Class ULegoAbilityEditorUtils Function ToLegoAbilityBlueprint ********************

// ********** Begin Class ULegoAbilityEditorUtils **************************************************
void ULegoAbilityEditorUtils::StaticRegisterNativesULegoAbilityEditorUtils()
{
	UClass* Class = ULegoAbilityEditorUtils::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAbilityTimelineByName", &ULegoAbilityEditorUtils::execGetAbilityTimelineByName },
		{ "GetAbilityTimelines", &ULegoAbilityEditorUtils::execGetAbilityTimelines },
		{ "GetActionEventByHandle", &ULegoAbilityEditorUtils::execGetActionEventByHandle },
		{ "GetOverridenTimelines", &ULegoAbilityEditorUtils::execGetOverridenTimelines },
		{ "GetTrackActionEvents", &ULegoAbilityEditorUtils::execGetTrackActionEvents },
		{ "SetAbilityTimelines", &ULegoAbilityEditorUtils::execSetAbilityTimelines },
		{ "SetActionEventByHandle", &ULegoAbilityEditorUtils::execSetActionEventByHandle },
		{ "SetOverridenTimelines", &ULegoAbilityEditorUtils::execSetOverridenTimelines },
		{ "ToLegoAbilityBlueprint", &ULegoAbilityEditorUtils::execToLegoAbilityBlueprint },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityEditorUtils;
UClass* ULegoAbilityEditorUtils::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityEditorUtils;
	if (!Z_Registration_Info_UClass_ULegoAbilityEditorUtils.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityEditorUtils"),
			Z_Registration_Info_UClass_ULegoAbilityEditorUtils.InnerSingleton,
			StaticRegisterNativesULegoAbilityEditorUtils,
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
	return Z_Registration_Info_UClass_ULegoAbilityEditorUtils.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityEditorUtils_NoRegister()
{
	return ULegoAbilityEditorUtils::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityEditorUtils_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "LegoAbilityEditorUtils.h" },
		{ "ModuleRelativePath", "Public/LegoAbilityEditorUtils.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelineByName, "GetAbilityTimelineByName" }, // 2563446491
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_GetAbilityTimelines, "GetAbilityTimelines" }, // 2306022725
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_GetActionEventByHandle, "GetActionEventByHandle" }, // 1409827258
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_GetOverridenTimelines, "GetOverridenTimelines" }, // 673566691
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_GetTrackActionEvents, "GetTrackActionEvents" }, // 4044706148
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_SetAbilityTimelines, "SetAbilityTimelines" }, // 1191619546
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_SetActionEventByHandle, "SetActionEventByHandle" }, // 2366111104
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_SetOverridenTimelines, "SetOverridenTimelines" }, // 1583431727
		{ &Z_Construct_UFunction_ULegoAbilityEditorUtils_ToLegoAbilityBlueprint, "ToLegoAbilityBlueprint" }, // 3515734225
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityEditorUtils>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::ClassParams = {
	&ULegoAbilityEditorUtils::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityEditorUtils()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityEditorUtils.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityEditorUtils.OuterSingleton, Z_Construct_UClass_ULegoAbilityEditorUtils_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityEditorUtils.OuterSingleton;
}
ULegoAbilityEditorUtils::ULegoAbilityEditorUtils(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityEditorUtils);
ULegoAbilityEditorUtils::~ULegoAbilityEditorUtils() {}
// ********** End Class ULegoAbilityEditorUtils ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGAActionEventHandle::StaticStruct, Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics::NewStructOps, TEXT("LGAActionEventHandle"), &Z_Registration_Info_UScriptStruct_FLGAActionEventHandle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionEventHandle), 3937144925U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityEditorUtils, ULegoAbilityEditorUtils::StaticClass, TEXT("ULegoAbilityEditorUtils"), &Z_Registration_Info_UClass_ULegoAbilityEditorUtils, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityEditorUtils), 2689832703U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_1221017370(TEXT("/Script/LegoAbilityEditor"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h__Script_LegoAbilityEditor_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
