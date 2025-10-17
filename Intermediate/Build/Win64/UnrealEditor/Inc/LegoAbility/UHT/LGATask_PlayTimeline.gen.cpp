// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LGATask_PlayTimeline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGATask_PlayTimeline() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilityTask();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATask_PlayTimeline();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UFunction* Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FTimelineWaitSimpleDelegate *******************************************
struct Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_LegoAbility, nullptr, "TimelineWaitSimpleDelegate__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FTimelineWaitSimpleDelegate_DelegateWrapper(const FMulticastScriptDelegate& TimelineWaitSimpleDelegate)
{
	TimelineWaitSimpleDelegate.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FTimelineWaitSimpleDelegate *********************************************

// ********** Begin Class ULGATask_PlayTimeline Function PlayTimeline ******************************
struct Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics
{
	struct LGATask_PlayTimeline_eventPlayTimeline_Parms
	{
		UGameplayAbility* OwningAbility;
		FName TaskInstanceName;
		ULGATimeline* InTimeline;
		float PlayRate;
		float SyncPoint;
		float StartTimeSeconds;
		FName InPreviousTimelineName;
		ULGATask_PlayTimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "TRUE" },
		{ "Category", "Ability|Tasks" },
		{ "Comment", "/** Play Timeline */" },
		{ "CPP_Default_InPreviousTimelineName", "None" },
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_StartTimeSeconds", "0.000000" },
		{ "CPP_Default_SyncPoint", "0.000000" },
		{ "DefaultToSelf", "OwningAbility" },
		{ "HidePin", "OwningAbility" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
		{ "ToolTip", "Play Timeline" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningAbility;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TaskInstanceName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InTimeline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SyncPoint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FNamePropertyParams NewProp_InPreviousTimelineName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_OwningAbility = { "OwningAbility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, OwningAbility), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_TaskInstanceName = { "TaskInstanceName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, TaskInstanceName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_InTimeline = { "InTimeline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, InTimeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_SyncPoint = { "SyncPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, SyncPoint), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, StartTimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_InPreviousTimelineName = { "InPreviousTimelineName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, InPreviousTimelineName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventPlayTimeline_Parms, ReturnValue), Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_OwningAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_TaskInstanceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_InTimeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_SyncPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_StartTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_InPreviousTimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATask_PlayTimeline, nullptr, "PlayTimeline", Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::LGATask_PlayTimeline_eventPlayTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::LGATask_PlayTimeline_eventPlayTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATask_PlayTimeline::execPlayTimeline)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_OwningAbility);
	P_GET_PROPERTY(FNameProperty,Z_Param_TaskInstanceName);
	P_GET_OBJECT(ULGATimeline,Z_Param_InTimeline);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SyncPoint);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartTimeSeconds);
	P_GET_PROPERTY(FNameProperty,Z_Param_InPreviousTimelineName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATask_PlayTimeline**)Z_Param__Result=ULGATask_PlayTimeline::PlayTimeline(Z_Param_OwningAbility,Z_Param_TaskInstanceName,Z_Param_InTimeline,Z_Param_PlayRate,Z_Param_SyncPoint,Z_Param_StartTimeSeconds,Z_Param_InPreviousTimelineName);
	P_NATIVE_END;
}
// ********** End Class ULGATask_PlayTimeline Function PlayTimeline ********************************

// ********** Begin Class ULGATask_PlayTimeline Function SetPlayRate *******************************
struct Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics
{
	struct LGATask_PlayTimeline_eventSetPlayRate_Parms
	{
		float InPlayRate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InPlayRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::NewProp_InPlayRate = { "InPlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventSetPlayRate_Parms, InPlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::NewProp_InPlayRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATask_PlayTimeline, nullptr, "SetPlayRate", Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::LGATask_PlayTimeline_eventSetPlayRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::LGATask_PlayTimeline_eventSetPlayRate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATask_PlayTimeline::execSetPlayRate)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InPlayRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPlayRate(Z_Param_InPlayRate);
	P_NATIVE_END;
}
// ********** End Class ULGATask_PlayTimeline Function SetPlayRate *********************************

// ********** Begin Class ULGATask_PlayTimeline Function SetSectionPlayRate ************************
struct Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics
{
	struct LGATask_PlayTimeline_eventSetSectionPlayRate_Parms
	{
		float InPlayRate;
		float StartTime;
		float EndTime;
		bool bSectionPlayRateClamp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InPlayRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EndTime;
	static void NewProp_bSectionPlayRateClamp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSectionPlayRateClamp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_InPlayRate = { "InPlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventSetSectionPlayRate_Parms, InPlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventSetSectionPlayRate_Parms, StartTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_EndTime = { "EndTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventSetSectionPlayRate_Parms, EndTime), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_bSectionPlayRateClamp_SetBit(void* Obj)
{
	((LGATask_PlayTimeline_eventSetSectionPlayRate_Parms*)Obj)->bSectionPlayRateClamp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_bSectionPlayRateClamp = { "bSectionPlayRateClamp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGATask_PlayTimeline_eventSetSectionPlayRate_Parms), &Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_bSectionPlayRateClamp_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_InPlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_EndTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::NewProp_bSectionPlayRateClamp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATask_PlayTimeline, nullptr, "SetSectionPlayRate", Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::LGATask_PlayTimeline_eventSetSectionPlayRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::LGATask_PlayTimeline_eventSetSectionPlayRate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATask_PlayTimeline::execSetSectionPlayRate)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InPlayRate);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_EndTime);
	P_GET_UBOOL(Z_Param_bSectionPlayRateClamp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSectionPlayRate(Z_Param_InPlayRate,Z_Param_StartTime,Z_Param_EndTime,Z_Param_bSectionPlayRateClamp);
	P_NATIVE_END;
}
// ********** End Class ULGATask_PlayTimeline Function SetSectionPlayRate **************************

// ********** Begin Class ULGATask_PlayTimeline Function SkipSection *******************************
struct Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics
{
	struct LGATask_PlayTimeline_eventSkipSection_Parms
	{
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATask_PlayTimeline_eventSkipSection_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATask_PlayTimeline, nullptr, "SkipSection", Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::LGATask_PlayTimeline_eventSkipSection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::LGATask_PlayTimeline_eventSkipSection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATask_PlayTimeline::execSkipSection)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SkipSection(Z_Param_Duration);
	P_NATIVE_END;
}
// ********** End Class ULGATask_PlayTimeline Function SkipSection *********************************

// ********** Begin Class ULGATask_PlayTimeline ****************************************************
void ULGATask_PlayTimeline::StaticRegisterNativesULGATask_PlayTimeline()
{
	UClass* Class = ULGATask_PlayTimeline::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PlayTimeline", &ULGATask_PlayTimeline::execPlayTimeline },
		{ "SetPlayRate", &ULGATask_PlayTimeline::execSetPlayRate },
		{ "SetSectionPlayRate", &ULGATask_PlayTimeline::execSetSectionPlayRate },
		{ "SkipSection", &ULGATask_PlayTimeline::execSkipSection },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGATask_PlayTimeline;
UClass* ULGATask_PlayTimeline::GetPrivateStaticClass()
{
	using TClass = ULGATask_PlayTimeline;
	if (!Z_Registration_Info_UClass_ULGATask_PlayTimeline.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGATask_PlayTimeline"),
			Z_Registration_Info_UClass_ULGATask_PlayTimeline.InnerSingleton,
			StaticRegisterNativesULGATask_PlayTimeline,
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
	return Z_Registration_Info_UClass_ULGATask_PlayTimeline.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister()
{
	return ULGATask_PlayTimeline::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGATask_PlayTimeline_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Play Timeline\n */" },
		{ "IncludePath", "LGATask_PlayTimeline.h" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
		{ "ToolTip", "Play Timeline" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCancelled_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timeline_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** The timeline need to play */" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
		{ "ToolTip", "The timeline need to play" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTime_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** The Current Time of the Timeline. */" },
		{ "ModuleRelativePath", "Public/LGATask_PlayTimeline.h" },
		{ "ToolTip", "The Current Time of the Timeline." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCancelled;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGATask_PlayTimeline_PlayTimeline, "PlayTimeline" }, // 299074589
		{ &Z_Construct_UFunction_ULGATask_PlayTimeline_SetPlayRate, "SetPlayRate" }, // 3024870334
		{ &Z_Construct_UFunction_ULGATask_PlayTimeline_SetSectionPlayRate, "SetSectionPlayRate" }, // 1340606302
		{ &Z_Construct_UFunction_ULGATask_PlayTimeline_SkipSection, "SkipSection" }, // 324262627
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGATask_PlayTimeline>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATask_PlayTimeline, OnCompleted), Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 2763707193
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_OnCancelled = { "OnCancelled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATask_PlayTimeline, OnCancelled), Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCancelled_MetaData), NewProp_OnCancelled_MetaData) }; // 2763707193
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATask_PlayTimeline, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timeline_MetaData), NewProp_Timeline_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATask_PlayTimeline, CurrentTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTime_MetaData), NewProp_CurrentTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULGATask_PlayTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_OnCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_OnCancelled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_Timeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATask_PlayTimeline_Statics::NewProp_CurrentTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATask_PlayTimeline_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULGATask_PlayTimeline_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilityTask,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATask_PlayTimeline_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGATask_PlayTimeline_Statics::ClassParams = {
	&ULGATask_PlayTimeline::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULGATask_PlayTimeline_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULGATask_PlayTimeline_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATask_PlayTimeline_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGATask_PlayTimeline_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGATask_PlayTimeline()
{
	if (!Z_Registration_Info_UClass_ULGATask_PlayTimeline.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGATask_PlayTimeline.OuterSingleton, Z_Construct_UClass_ULGATask_PlayTimeline_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGATask_PlayTimeline.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGATask_PlayTimeline);
ULGATask_PlayTimeline::~ULGATask_PlayTimeline() {}
// ********** End Class ULGATask_PlayTimeline ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGATask_PlayTimeline, ULGATask_PlayTimeline::StaticClass, TEXT("ULGATask_PlayTimeline"), &Z_Registration_Info_UClass_ULGATask_PlayTimeline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGATask_PlayTimeline), 116104441U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h__Script_LegoAbility_735481314(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
