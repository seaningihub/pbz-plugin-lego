// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbility.h"
#include "Actions/LGAAction_Executable.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbility() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagRequirements();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAEventAction();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGAEventAction ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAEventAction;
class UScriptStruct* FLGAEventAction::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAEventAction.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAEventAction.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAEventAction, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAEventAction"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAEventAction.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAEventAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTag_MetaData[] = {
		{ "Categories", "GameplayEvent" },
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteAction_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExecuteAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAEventAction>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAEventAction_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAEventAction, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTag_MetaData), NewProp_EventTag_MetaData) }; // 133831994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGAEventAction_Statics::NewProp_ExecuteAction = { "ExecuteAction", nullptr, (EPropertyFlags)0x0012000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAEventAction, ExecuteAction), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteAction_MetaData), NewProp_ExecuteAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGAEventAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAEventAction_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAEventAction_Statics::NewProp_ExecuteAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAEventAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAEventAction_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAEventAction",
	Z_Construct_UScriptStruct_FLGAEventAction_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAEventAction_Statics::PropPointers),
	sizeof(FLGAEventAction),
	alignof(FLGAEventAction),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAEventAction_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAEventAction_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAEventAction()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAEventAction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAEventAction.InnerSingleton, Z_Construct_UScriptStruct_FLGAEventAction_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAEventAction.InnerSingleton;
}
// ********** End ScriptStruct FLGAEventAction *****************************************************

// ********** Begin Class ULegoAbility Function EndTimeline ****************************************
struct Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics
{
	struct LegoAbility_eventEndTimeline_Parms
	{
		ULGATimeline* Timeline;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventEndTimeline_Parms, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::NewProp_Timeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "EndTimeline", Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::LegoAbility_eventEndTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::LegoAbility_eventEndTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_EndTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_EndTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execEndTimeline)
{
	P_GET_OBJECT(ULGATimeline,Z_Param_Timeline);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndTimeline(Z_Param_Timeline);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function EndTimeline ******************************************

// ********** Begin Class ULegoAbility Function EndTimelineByName **********************************
struct Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics
{
	struct LegoAbility_eventEndTimelineByName_Parms
	{
		FName TimelineName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventEndTimelineByName_Parms, TimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::NewProp_TimelineName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "EndTimelineByName", Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::LegoAbility_eventEndTimelineByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::LegoAbility_eventEndTimelineByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_EndTimelineByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_EndTimelineByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execEndTimelineByName)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_TimelineName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndTimelineByName(Z_Param_TimelineName);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function EndTimelineByName ************************************

// ********** Begin Class ULegoAbility Function ExecuteAction **************************************
struct Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics
{
	struct LegoAbility_eventExecuteAction_Parms
	{
		ULGAAction_Executable* Action;
		FLGAActionExecutionContextHandle Context;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "Comment", "// Execute an executable action within this ability.\n" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Execute an executable action within this ability." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventExecuteAction_Parms, Action), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventExecuteAction_Parms, Context), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "ExecuteAction", Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::LegoAbility_eventExecuteAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::LegoAbility_eventExecuteAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_ExecuteAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_ExecuteAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execExecuteAction)
{
	P_GET_OBJECT(ULGAAction_Executable,Z_Param_Action);
	P_GET_STRUCT(FLGAActionExecutionContextHandle,Z_Param_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteAction(Z_Param_Action,Z_Param_Context);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function ExecuteAction ****************************************

// ********** Begin Class ULegoAbility Function GetActionByName ************************************
struct Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics
{
	struct LegoAbility_eventGetActionByName_Parms
	{
		FName TimelineName;
		FName ActionName;
		ULGAAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ActionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionByName_Parms, TimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_ActionName = { "ActionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionByName_Parms, ActionName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionByName_Parms, ReturnValue), Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_TimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_ActionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetActionByName", Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::LegoAbility_eventGetActionByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::LegoAbility_eventGetActionByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetActionByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetActionByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetActionByName)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_TimelineName);
	P_GET_PROPERTY(FNameProperty,Z_Param_ActionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGAAction**)Z_Param__Result=P_THIS->GetActionByName(Z_Param_TimelineName,Z_Param_ActionName);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetActionByName **************************************

// ********** Begin Class ULegoAbility Function GetActionsByTag ************************************
struct Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics
{
	struct LegoAbility_eventGetActionsByTag_Parms
	{
		TSubclassOf<ULGAAction> ActionClass;
		FGameplayTagRequirements ActionTagReqs;
		TArray<ULGAAction*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActionClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionTagReqs;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ActionClass = { "ActionClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionsByTag_Parms, ActionClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ActionTagReqs = { "ActionTagReqs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionsByTag_Parms, ActionTagReqs), Z_Construct_UScriptStruct_FGameplayTagRequirements, METADATA_PARAMS(0, nullptr) }; // 1313721778
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetActionsByTag_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ActionClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ActionTagReqs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetActionsByTag", Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::LegoAbility_eventGetActionsByTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::LegoAbility_eventGetActionsByTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetActionsByTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetActionsByTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetActionsByTag)
{
	P_GET_OBJECT(UClass,Z_Param_ActionClass);
	P_GET_STRUCT(FGameplayTagRequirements,Z_Param_ActionTagReqs);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<ULGAAction*>*)Z_Param__Result=P_THIS->GetActionsByTag(Z_Param_ActionClass,Z_Param_ActionTagReqs);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetActionsByTag **************************************

// ********** Begin Class ULegoAbility Function GetAllTimelineNames ********************************
struct Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics
{
	struct LegoAbility_eventGetAllTimelineNames_Parms
	{
		TArray<FName> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetAllTimelineNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetAllTimelineNames", Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::LegoAbility_eventGetAllTimelineNames_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::LegoAbility_eventGetAllTimelineNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetAllTimelineNames)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FName>*)Z_Param__Result=P_THIS->GetAllTimelineNames();
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetAllTimelineNames **********************************

// ********** Begin Class ULegoAbility Function GetCurveValue **************************************
struct Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics
{
	struct LegoAbility_eventGetCurveValue_Parms
	{
		FName CurveName;
		float DefaultValue;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "CPP_Default_DefaultValue", "0.000000" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_CurveName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_CurveName = { "CurveName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetCurveValue_Parms, CurveName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetCurveValue_Parms, DefaultValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetCurveValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_CurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_DefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetCurveValue", Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::LegoAbility_eventGetCurveValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::LegoAbility_eventGetCurveValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetCurveValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetCurveValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetCurveValue)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_CurveName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DefaultValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurveValue(Z_Param_CurveName,Z_Param_DefaultValue);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetCurveValue ****************************************

// ********** Begin Class ULegoAbility Function GetDisplayName *************************************
struct Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics
{
	struct LegoAbility_eventGetDisplayName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "Comment", "/** Returns the name of the Ability in a print friendly format (without class identifiers).\x09*/" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Returns the name of the Ability in a print friendly format (without class identifiers)." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetDisplayName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetDisplayName", Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::LegoAbility_eventGetDisplayName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::LegoAbility_eventGetDisplayName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetDisplayName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetDisplayName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetDisplayName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetDisplayName();
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetDisplayName ***************************************

// ********** Begin Class ULegoAbility Function GetPlayTimelineTask ********************************
struct Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics
{
	struct LegoAbility_eventGetPlayTimelineTask_Parms
	{
		ULGATask_PlayTimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** Returns the active PlayTimeline task of this Ability. */" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Returns the active PlayTimeline task of this Ability." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetPlayTimelineTask_Parms, ReturnValue), Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetPlayTimelineTask", Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::LegoAbility_eventGetPlayTimelineTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::LegoAbility_eventGetPlayTimelineTask_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetPlayTimelineTask)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATask_PlayTimeline**)Z_Param__Result=P_THIS->GetPlayTimelineTask();
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetPlayTimelineTask **********************************

// ********** Begin Class ULegoAbility Function GetTimelineByIndex *********************************
struct Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics
{
	struct LegoAbility_eventGetTimelineByIndex_Parms
	{
		int32 Index;
		ULGATimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetTimelineByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetTimelineByIndex_Parms, ReturnValue), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetTimelineByIndex", Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::LegoAbility_eventGetTimelineByIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::LegoAbility_eventGetTimelineByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetTimelineByIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATimeline**)Z_Param__Result=P_THIS->GetTimelineByIndex(Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetTimelineByIndex ***********************************

// ********** Begin Class ULegoAbility Function GetTimelineByName **********************************
struct Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics
{
	struct LegoAbility_eventGetTimelineByName_Parms
	{
		FName TimelineName;
		ULGATimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "Comment", "/** Returns the Timeline which has specified instance name of this Ability. */" },
		{ "CPP_Default_TimelineName", "NewTimeline" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Returns the Timeline which has specified instance name of this Ability." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetTimelineByName_Parms, TimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventGetTimelineByName_Parms, ReturnValue), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::NewProp_TimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "GetTimelineByName", Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::LegoAbility_eventGetTimelineByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::LegoAbility_eventGetTimelineByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_GetTimelineByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_GetTimelineByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execGetTimelineByName)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_TimelineName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATimeline**)Z_Param__Result=P_THIS->GetTimelineByName(Z_Param_TimelineName);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function GetTimelineByName ************************************

// ********** Begin Class ULegoAbility Function IsPlayingAnyTimeline *******************************
struct Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics
{
	struct LegoAbility_eventIsPlayingAnyTimeline_Parms
	{
		TArray<ULGATimeline*> InTimelines;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InTimelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InTimelines;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_InTimelines_Inner = { "InTimelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_InTimelines = { "InTimelines", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventIsPlayingAnyTimeline_Parms, InTimelines), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LegoAbility_eventIsPlayingAnyTimeline_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LegoAbility_eventIsPlayingAnyTimeline_Parms), &Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_InTimelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_InTimelines,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "IsPlayingAnyTimeline", Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::LegoAbility_eventIsPlayingAnyTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::LegoAbility_eventIsPlayingAnyTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execIsPlayingAnyTimeline)
{
	P_GET_TARRAY(ULGATimeline*,Z_Param_InTimelines);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayingAnyTimeline(Z_Param_InTimelines);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function IsPlayingAnyTimeline *********************************

// ********** Begin Class ULegoAbility Function IsPlayingTimeline **********************************
struct Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics
{
	struct LegoAbility_eventIsPlayingTimeline_Parms
	{
		ULGATimeline* Timeline;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventIsPlayingTimeline_Parms, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LegoAbility_eventIsPlayingTimeline_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LegoAbility_eventIsPlayingTimeline_Parms), &Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_Timeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "IsPlayingTimeline", Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::LegoAbility_eventIsPlayingTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::LegoAbility_eventIsPlayingTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execIsPlayingTimeline)
{
	P_GET_OBJECT(ULGATimeline,Z_Param_Timeline);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayingTimeline(Z_Param_Timeline);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function IsPlayingTimeline ************************************

// ********** Begin Class ULegoAbility Function PlayTimeline ***************************************
struct Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics
{
	struct LegoAbility_eventPlayTimeline_Parms
	{
		ULGATimeline* Timeline;
		float PlayRate;
		float SyncPoint;
		float StartTimeSeconds;
		FName PreviousTimlineName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/* Start a task to play ability timeline */" },
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_PreviousTimlineName", "None" },
		{ "CPP_Default_StartTimeSeconds", "0.000000" },
		{ "CPP_Default_SyncPoint", "0.000000" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Start a task to play ability timeline" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SyncPoint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PreviousTimlineName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimeline_Parms, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimeline_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_SyncPoint = { "SyncPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimeline_Parms, SyncPoint), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimeline_Parms, StartTimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_PreviousTimlineName = { "PreviousTimlineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimeline_Parms, PreviousTimlineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_Timeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_SyncPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_StartTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::NewProp_PreviousTimlineName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "PlayTimeline", Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::LegoAbility_eventPlayTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::LegoAbility_eventPlayTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_PlayTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_PlayTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execPlayTimeline)
{
	P_GET_OBJECT(ULGATimeline,Z_Param_Timeline);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SyncPoint);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartTimeSeconds);
	P_GET_PROPERTY(FNameProperty,Z_Param_PreviousTimlineName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayTimeline(Z_Param_Timeline,Z_Param_PlayRate,Z_Param_SyncPoint,Z_Param_StartTimeSeconds,Z_Param_PreviousTimlineName);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function PlayTimeline *****************************************

// ********** Begin Class ULegoAbility Function PlayTimelineByName *********************************
struct Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics
{
	struct LegoAbility_eventPlayTimelineByName_Parms
	{
		FName TimelineName;
		float PlayRate;
		float SyncPoint;
		float StartTimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_StartTimeSeconds", "0.000000" },
		{ "CPP_Default_SyncPoint", "0.000000" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SyncPoint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimelineByName_Parms, TimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimelineByName_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_SyncPoint = { "SyncPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimelineByName_Parms, SyncPoint), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LegoAbility_eventPlayTimelineByName_Parms, StartTimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_TimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_SyncPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::NewProp_StartTimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbility, nullptr, "PlayTimelineByName", Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::LegoAbility_eventPlayTimelineByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::LegoAbility_eventPlayTimelineByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULegoAbility_PlayTimelineByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbility_PlayTimelineByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULegoAbility::execPlayTimelineByName)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_TimelineName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SyncPoint);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartTimeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayTimelineByName(Z_Param_TimelineName,Z_Param_PlayRate,Z_Param_SyncPoint,Z_Param_StartTimeSeconds);
	P_NATIVE_END;
}
// ********** End Class ULegoAbility Function PlayTimelineByName ***********************************

// ********** Begin Class ULegoAbility *************************************************************
void ULegoAbility::StaticRegisterNativesULegoAbility()
{
	UClass* Class = ULegoAbility::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EndTimeline", &ULegoAbility::execEndTimeline },
		{ "EndTimelineByName", &ULegoAbility::execEndTimelineByName },
		{ "ExecuteAction", &ULegoAbility::execExecuteAction },
		{ "GetActionByName", &ULegoAbility::execGetActionByName },
		{ "GetActionsByTag", &ULegoAbility::execGetActionsByTag },
		{ "GetAllTimelineNames", &ULegoAbility::execGetAllTimelineNames },
		{ "GetCurveValue", &ULegoAbility::execGetCurveValue },
		{ "GetDisplayName", &ULegoAbility::execGetDisplayName },
		{ "GetPlayTimelineTask", &ULegoAbility::execGetPlayTimelineTask },
		{ "GetTimelineByIndex", &ULegoAbility::execGetTimelineByIndex },
		{ "GetTimelineByName", &ULegoAbility::execGetTimelineByName },
		{ "IsPlayingAnyTimeline", &ULegoAbility::execIsPlayingAnyTimeline },
		{ "IsPlayingTimeline", &ULegoAbility::execIsPlayingTimeline },
		{ "PlayTimeline", &ULegoAbility::execPlayTimeline },
		{ "PlayTimelineByName", &ULegoAbility::execPlayTimelineByName },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbility;
UClass* ULegoAbility::GetPrivateStaticClass()
{
	using TClass = ULegoAbility;
	if (!Z_Registration_Info_UClass_ULegoAbility.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbility"),
			Z_Registration_Info_UClass_ULegoAbility.InnerSingleton,
			StaticRegisterNativesULegoAbility,
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
	return Z_Registration_Info_UClass_ULegoAbility.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbility_NoRegister()
{
	return ULegoAbility::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "LegoAbility.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnActivate_Inner_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnActivate_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnEnd_Inner_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnEnd_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnGameplayEvent_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnInputPressed_Inner_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnInputPressed_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnInputReleased_Inner_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecuteOnInputReleased_MetaData[] = {
		{ "Category", "Actions on event" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timelines_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** Array of all Timelines in this Ability */" },
		{ "ModuleRelativePath", "Public/LegoAbility.h" },
		{ "ToolTip", "Array of all Timelines in this Ability" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExecuteOnActivate_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExecuteOnActivate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExecuteOnEnd_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExecuteOnEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExecuteOnGameplayEvent_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExecuteOnGameplayEvent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExecuteOnInputPressed_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExecuteOnInputPressed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExecuteOnInputReleased_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExecuteOnInputReleased;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Timelines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULegoAbility_EndTimeline, "EndTimeline" }, // 1183464909
		{ &Z_Construct_UFunction_ULegoAbility_EndTimelineByName, "EndTimelineByName" }, // 592345205
		{ &Z_Construct_UFunction_ULegoAbility_ExecuteAction, "ExecuteAction" }, // 737403478
		{ &Z_Construct_UFunction_ULegoAbility_GetActionByName, "GetActionByName" }, // 948021307
		{ &Z_Construct_UFunction_ULegoAbility_GetActionsByTag, "GetActionsByTag" }, // 4114268685
		{ &Z_Construct_UFunction_ULegoAbility_GetAllTimelineNames, "GetAllTimelineNames" }, // 3760949984
		{ &Z_Construct_UFunction_ULegoAbility_GetCurveValue, "GetCurveValue" }, // 1782441785
		{ &Z_Construct_UFunction_ULegoAbility_GetDisplayName, "GetDisplayName" }, // 2397661474
		{ &Z_Construct_UFunction_ULegoAbility_GetPlayTimelineTask, "GetPlayTimelineTask" }, // 1704834211
		{ &Z_Construct_UFunction_ULegoAbility_GetTimelineByIndex, "GetTimelineByIndex" }, // 1004710632
		{ &Z_Construct_UFunction_ULegoAbility_GetTimelineByName, "GetTimelineByName" }, // 117686281
		{ &Z_Construct_UFunction_ULegoAbility_IsPlayingAnyTimeline, "IsPlayingAnyTimeline" }, // 3021280789
		{ &Z_Construct_UFunction_ULegoAbility_IsPlayingTimeline, "IsPlayingTimeline" }, // 1308514672
		{ &Z_Construct_UFunction_ULegoAbility_PlayTimeline, "PlayTimeline" }, // 728274841
		{ &Z_Construct_UFunction_ULegoAbility_PlayTimelineByName, "PlayTimelineByName" }, // 2796116734
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnActivate_Inner = { "ExecuteOnActivate", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnActivate_Inner_MetaData), NewProp_ExecuteOnActivate_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnActivate = { "ExecuteOnActivate", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, ExecuteOnActivate), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnActivate_MetaData), NewProp_ExecuteOnActivate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnEnd_Inner = { "ExecuteOnEnd", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnEnd_Inner_MetaData), NewProp_ExecuteOnEnd_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnEnd = { "ExecuteOnEnd", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, ExecuteOnEnd), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnEnd_MetaData), NewProp_ExecuteOnEnd_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnGameplayEvent_Inner = { "ExecuteOnGameplayEvent", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAEventAction, METADATA_PARAMS(0, nullptr) }; // 175265421
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnGameplayEvent = { "ExecuteOnGameplayEvent", nullptr, (EPropertyFlags)0x0010008000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, ExecuteOnGameplayEvent), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnGameplayEvent_MetaData), NewProp_ExecuteOnGameplayEvent_MetaData) }; // 175265421
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputPressed_Inner = { "ExecuteOnInputPressed", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnInputPressed_Inner_MetaData), NewProp_ExecuteOnInputPressed_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputPressed = { "ExecuteOnInputPressed", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, ExecuteOnInputPressed), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnInputPressed_MetaData), NewProp_ExecuteOnInputPressed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputReleased_Inner = { "ExecuteOnInputReleased", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnInputReleased_Inner_MetaData), NewProp_ExecuteOnInputReleased_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputReleased = { "ExecuteOnInputReleased", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, ExecuteOnInputReleased), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecuteOnInputReleased_MetaData), NewProp_ExecuteOnInputReleased_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_Timelines_Inner = { "Timelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbility_Statics::NewProp_Timelines = { "Timelines", nullptr, (EPropertyFlags)0x0020480000202014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbility, Timelines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timelines_MetaData), NewProp_Timelines_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnActivate_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnActivate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnEnd_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnGameplayEvent_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnGameplayEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputPressed_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputPressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputReleased_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_ExecuteOnInputReleased,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_Timelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbility_Statics::NewProp_Timelines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbility_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbility_Statics::ClassParams = {
	&ULegoAbility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULegoAbility_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbility_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbility()
{
	if (!Z_Registration_Info_UClass_ULegoAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbility.OuterSingleton, Z_Construct_UClass_ULegoAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbility.OuterSingleton;
}
ULegoAbility::ULegoAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbility);
ULegoAbility::~ULegoAbility() {}
// ********** End Class ULegoAbility ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGAEventAction::StaticStruct, Z_Construct_UScriptStruct_FLGAEventAction_Statics::NewStructOps, TEXT("LGAEventAction"), &Z_Registration_Info_UScriptStruct_FLGAEventAction, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAEventAction), 175265421U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbility, ULegoAbility::StaticClass, TEXT("ULegoAbility"), &Z_Registration_Info_UClass_ULegoAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbility), 1715344836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_197627764(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h__Script_LegoAbility_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
