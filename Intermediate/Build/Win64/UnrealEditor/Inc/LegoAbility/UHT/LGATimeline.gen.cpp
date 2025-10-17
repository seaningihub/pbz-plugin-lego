// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LGATimeline.h"
#include "Animation/AnimCurveTypes.h"
#include "Animation/AnimMontage.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGATimeline() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FFloatCurve();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FMontageBlendSettings();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEvent();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEventSection();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionTrack();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineBlendSetting();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGAActionEventSection ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionEventSection;
class UScriptStruct* FLGAActionEventSection::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEventSection.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionEventSection.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionEventSection, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionEventSection"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEventSection.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionEventSection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionEventSection>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEventSection, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEventSection, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionEventSection",
	Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::PropPointers),
	sizeof(FLGAActionEventSection),
	alignof(FLGAActionEventSection),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEventSection()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEventSection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionEventSection.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEventSection.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionEventSection **********************************************

// ********** Begin ScriptStruct FLGAActionEvent ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionEvent;
class UScriptStruct* FLGAActionEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionEvent, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEvent.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Triggers an ability action. Each FAbilityActionEvent contains an ULegoAbilityAction object\n */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Triggers an ability action. Each FAbilityActionEvent contains an ULegoAbilityAction object" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTime_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** The start time of this action. */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "The start time of this action." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** The duration of this action. */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "The duration of this action." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerTimeOffset_MetaData[] = {
		{ "Comment", "/** An offset from the DisplayTime to the actual time we will trigger the action, as we cannot always trigger it exactly at the time the user wants */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "An offset from the DisplayTime to the actual time we will trigger the action, as we cannot always trigger it exactly at the time the user wants" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndTriggerTimeOffset_MetaData[] = {
		{ "Comment", "/** An offset similar to TriggerTimeOffset but used for the end scrub handle of a action's duration */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "An offset similar to TriggerTimeOffset but used for the end scrub handle of a action's duration" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[] = {
		{ "Category", "AbilityActionEvent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackIndex_MetaData[] = {
		{ "Comment", "/** 'Track' that the action exists on, used for visual placement in editor and sorting priority in runtime */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "'Track' that the action exists on, used for visual placement in editor and sorting priority in runtime" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sections_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TriggerTimeOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EndTriggerTimeOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Guid;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TrackIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sections_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Sections;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, StartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTime_MetaData), NewProp_StartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_TriggerTimeOffset = { "TriggerTimeOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, TriggerTimeOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerTimeOffset_MetaData), NewProp_TriggerTimeOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_EndTriggerTimeOffset = { "EndTriggerTimeOffset", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, EndTriggerTimeOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndTriggerTimeOffset_MetaData), NewProp_EndTriggerTimeOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x001200000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, Action), Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Action_MetaData), NewProp_Action_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Guid_MetaData), NewProp_Guid_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_TrackIndex = { "TrackIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, TrackIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackIndex_MetaData), NewProp_TrackIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Sections_Inner = { "Sections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAActionEventSection, METADATA_PARAMS(0, nullptr) }; // 2307969658
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Sections = { "Sections", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionEvent, Sections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sections_MetaData), NewProp_Sections_MetaData) }; // 2307969658
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGAActionEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_TriggerTimeOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_EndTriggerTimeOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Guid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_TrackIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Sections_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewProp_Sections,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionEvent",
	Z_Construct_UScriptStruct_FLGAActionEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEvent_Statics::PropPointers),
	sizeof(FLGAActionEvent),
	alignof(FLGAActionEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionEvent.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionEvent_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionEvent.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionEvent *****************************************************

// ********** Begin ScriptStruct FLGAActionTrack ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionTrack;
class UScriptStruct* FLGAActionTrack::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionTrack.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionTrack.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionTrack, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionTrack"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionTrack.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionTrack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Track of actions\n */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Track of actions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackName_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackColor_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TrackName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrackColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionTrack>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLGAActionTrack_Statics::NewProp_TrackName = { "TrackName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionTrack, TrackName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackName_MetaData), NewProp_TrackName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionTrack_Statics::NewProp_TrackColor = { "TrackColor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionTrack, TrackColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackColor_MetaData), NewProp_TrackColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGAActionTrack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionTrack_Statics::NewProp_TrackName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionTrack_Statics::NewProp_TrackColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionTrack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionTrack_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionTrack",
	Z_Construct_UScriptStruct_FLGAActionTrack_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionTrack_Statics::PropPointers),
	sizeof(FLGAActionTrack),
	alignof(FLGAActionTrack),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionTrack_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionTrack_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionTrack()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionTrack.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionTrack.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionTrack_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionTrack.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionTrack *****************************************************

// ********** Begin ScriptStruct FLGATimelineBlendSetting ******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting;
class UScriptStruct* FLGATimelineBlendSetting::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGATimelineBlendSetting, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGATimelineBlendSetting"));
	}
	return Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousAbility_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousTimelineName_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "GetOptions", "GetPreviousTimelineNames" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTimeSeconds_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MontageBlendIn_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_PreviousAbility;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PreviousTimelineName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MontageBlendIn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGATimelineBlendSetting>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_PreviousAbility = { "PreviousAbility", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineBlendSetting, PreviousAbility), Z_Construct_UClass_ULegoAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousAbility_MetaData), NewProp_PreviousAbility_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_PreviousTimelineName = { "PreviousTimelineName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineBlendSetting, PreviousTimelineName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousTimelineName_MetaData), NewProp_PreviousTimelineName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineBlendSetting, StartTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTimeSeconds_MetaData), NewProp_StartTimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_MontageBlendIn = { "MontageBlendIn", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineBlendSetting, MontageBlendIn), Z_Construct_UScriptStruct_FMontageBlendSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MontageBlendIn_MetaData), NewProp_MontageBlendIn_MetaData) }; // 201096038
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_PreviousAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_PreviousTimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_StartTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewProp_MontageBlendIn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGATimelineBlendSetting",
	Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::PropPointers),
	sizeof(FLGATimelineBlendSetting),
	alignof(FLGATimelineBlendSetting),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineBlendSetting()
{
	if (!Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.InnerSingleton, Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting.InnerSingleton;
}
// ********** End ScriptStruct FLGATimelineBlendSetting ********************************************

// ********** Begin Class ULGATimeline Function AddCurve *******************************************
struct Z_Construct_UFunction_ULGATimeline_AddCurve_Statics
{
	struct LGATimeline_eventAddCurve_Parms
	{
		FName Name;
		TArray<float> Times;
		TArray<float> Values;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Times_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Values_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Times_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Times;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Values_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Values;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventAddCurve_Parms, Name), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Times_Inner = { "Times", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Times = { "Times", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventAddCurve_Parms, Times), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Times_MetaData), NewProp_Times_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Values_Inner = { "Values", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Values = { "Values", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventAddCurve_Parms, Values), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Values_MetaData), NewProp_Values_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Times_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Times,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Values_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::NewProp_Values,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATimeline, nullptr, "AddCurve", Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::LGATimeline_eventAddCurve_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::LGATimeline_eventAddCurve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATimeline_AddCurve()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATimeline_AddCurve_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATimeline::execAddCurve)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Name);
	P_GET_TARRAY_REF(float,Z_Param_Out_Times);
	P_GET_TARRAY_REF(float,Z_Param_Out_Values);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddCurve(Z_Param_Name,Z_Param_Out_Times,Z_Param_Out_Values);
	P_NATIVE_END;
}
// ********** End Class ULGATimeline Function AddCurve *********************************************

// ********** Begin Class ULGATimeline Function GetOriginalStep ************************************
struct Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics
{
	struct LGATimeline_eventGetOriginalStep_Parms
	{
		float CurrentTime;
		float RuntimeStep;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RuntimeStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetOriginalStep_Parms, CurrentTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_RuntimeStep = { "RuntimeStep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetOriginalStep_Parms, RuntimeStep), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetOriginalStep_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_CurrentTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_RuntimeStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATimeline, nullptr, "GetOriginalStep", Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::LGATimeline_eventGetOriginalStep_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::LGATimeline_eventGetOriginalStep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATimeline_GetOriginalStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATimeline_GetOriginalStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATimeline::execGetOriginalStep)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurrentTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RuntimeStep);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetOriginalStep(Z_Param_CurrentTime,Z_Param_RuntimeStep);
	P_NATIVE_END;
}
// ********** End Class ULGATimeline Function GetOriginalStep **************************************

// ********** Begin Class ULGATimeline Function GetPreviousTimelineNames ***************************
struct Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics
{
	struct LGATimeline_eventGetPreviousTimelineNames_Parms
	{
		TArray<FName> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetPreviousTimelineNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATimeline, nullptr, "GetPreviousTimelineNames", Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::LGATimeline_eventGetPreviousTimelineNames_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::LGATimeline_eventGetPreviousTimelineNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATimeline::execGetPreviousTimelineNames)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FName>*)Z_Param__Result=P_THIS->GetPreviousTimelineNames();
	P_NATIVE_END;
}
// ********** End Class ULGATimeline Function GetPreviousTimelineNames *****************************

// ********** Begin Class ULGATimeline Function GetScaledTimeStep **********************************
struct Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics
{
	struct LGATimeline_eventGetScaledTimeStep_Parms
	{
		float CurrentTime;
		float InTimelineStep;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InTimelineStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_CurrentTime = { "CurrentTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetScaledTimeStep_Parms, CurrentTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_InTimelineStep = { "InTimelineStep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetScaledTimeStep_Parms, InTimelineStep), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventGetScaledTimeStep_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_CurrentTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_InTimelineStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATimeline, nullptr, "GetScaledTimeStep", Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::LGATimeline_eventGetScaledTimeStep_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::LGATimeline_eventGetScaledTimeStep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATimeline::execGetScaledTimeStep)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurrentTime);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InTimelineStep);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetScaledTimeStep(Z_Param_CurrentTime,Z_Param_InTimelineStep);
	P_NATIVE_END;
}
// ********** End Class ULGATimeline Function GetScaledTimeStep ************************************

// ********** Begin Class ULGATimeline Function RemoveCurve ****************************************
struct Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics
{
	struct LGATimeline_eventRemoveCurve_Parms
	{
		FName Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGATimeline_eventRemoveCurve_Parms, Name), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGATimeline, nullptr, "RemoveCurve", Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::LGATimeline_eventRemoveCurve_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::LGATimeline_eventRemoveCurve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGATimeline_RemoveCurve()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGATimeline_RemoveCurve_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGATimeline::execRemoveCurve)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveCurve(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class ULGATimeline Function RemoveCurve ******************************************

// ********** Begin Class ULGATimeline *************************************************************
void ULGATimeline::StaticRegisterNativesULGATimeline()
{
	UClass* Class = ULGATimeline::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddCurve", &ULGATimeline::execAddCurve },
		{ "GetOriginalStep", &ULGATimeline::execGetOriginalStep },
		{ "GetPreviousTimelineNames", &ULGATimeline::execGetPreviousTimelineNames },
		{ "GetScaledTimeStep", &ULGATimeline::execGetScaledTimeStep },
		{ "RemoveCurve", &ULGATimeline::execRemoveCurve },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGATimeline;
UClass* ULGATimeline::GetPrivateStaticClass()
{
	using TClass = ULGATimeline;
	if (!Z_Registration_Info_UClass_ULGATimeline.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGATimeline"),
			Z_Registration_Info_UClass_ULGATimeline.InnerSingleton,
			StaticRegisterNativesULGATimeline,
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
	return Z_Registration_Info_UClass_ULGATimeline.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGATimeline_NoRegister()
{
	return ULGATimeline::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGATimeline_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Timeline of ability\n */" },
		{ "IncludePath", "LGATimeline.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Timeline of ability" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityActionTracks_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "// if you change Actions array, this will need to be rebuilt\n" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "if you change Actions array, this will need to be rebuilt" },
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimelineTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "/** Ability actions */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Ability actions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloatCurves_MetaData[] = {
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceLength_MetaData[] = {
		{ "Category", "Timeline" },
		{ "Comment", "/** Length (in seconds) of this Timeline if played back with a speed of 1.0. */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Length (in seconds) of this Timeline if played back with a speed of 1.0." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLooping_MetaData[] = {
		{ "Category", "Timeline" },
		{ "Comment", "/** Whether the timeline should loop when it reaches the end */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Whether the timeline should loop when it reaches the end" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoPlay_MetaData[] = {
		{ "Category", "Timeline" },
		{ "Comment", "/** Whether the timeline should be auto played when ability is activated */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Whether the timeline should be auto played when ability is activated" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopAbility_MetaData[] = {
		{ "Category", "Timeline" },
		{ "Comment", "/** Whether the timeline should end ability when it reaches the end */" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "ToolTip", "Whether the timeline should end ability when it reaches the end" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeStretchCurveName_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTimeSeconds_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicBlendSettings_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
		{ "TitleProperty", "{PreviousAbility}" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewWeapon_MetaData[] = {
		{ "Categories", "Weapon.Type" },
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Public/LGATimeline.h" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AbilityActionTracks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AbilityActionTracks;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TimelineTags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FloatCurves_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FloatCurves;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SequenceLength;
	static void NewProp_bLooping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLooping;
	static void NewProp_bAutoPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoPlay;
	static void NewProp_bStopAbility_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopAbility;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimeStretchCurveName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DynamicBlendSettings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DynamicBlendSettings;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewWeapon;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGATimeline_AddCurve, "AddCurve" }, // 3812697410
		{ &Z_Construct_UFunction_ULGATimeline_GetOriginalStep, "GetOriginalStep" }, // 2866605518
		{ &Z_Construct_UFunction_ULGATimeline_GetPreviousTimelineNames, "GetPreviousTimelineNames" }, // 1624895133
		{ &Z_Construct_UFunction_ULGATimeline_GetScaledTimeStep, "GetScaledTimeStep" }, // 3377378436
		{ &Z_Construct_UFunction_ULGATimeline_RemoveCurve, "RemoveCurve" }, // 1483869888
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGATimeline>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_AbilityActionTracks_Inner = { "AbilityActionTracks", nullptr, (EPropertyFlags)0x0000000800000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAActionTrack, METADATA_PARAMS(0, nullptr) }; // 395941141
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_AbilityActionTracks = { "AbilityActionTracks", nullptr, (EPropertyFlags)0x0010000800000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, AbilityActionTracks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityActionTracks_MetaData), NewProp_AbilityActionTracks_MetaData) }; // 395941141
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_TimelineTags = { "TimelineTags", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, TimelineTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimelineTags_MetaData), NewProp_TimelineTags_MetaData) }; // 2104890724
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAActionEvent, METADATA_PARAMS(0, nullptr) }; // 3071200278
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0010008000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) }; // 3071200278
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_FloatCurves_Inner = { "FloatCurves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFloatCurve, METADATA_PARAMS(0, nullptr) }; // 375295307
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_FloatCurves = { "FloatCurves", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, FloatCurves), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloatCurves_MetaData), NewProp_FloatCurves_MetaData) }; // 375295307
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_SequenceLength = { "SequenceLength", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, SequenceLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceLength_MetaData), NewProp_SequenceLength_MetaData) };
void Z_Construct_UClass_ULGATimeline_Statics::NewProp_bLooping_SetBit(void* Obj)
{
	((ULGATimeline*)Obj)->bLooping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_bLooping = { "bLooping", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGATimeline), &Z_Construct_UClass_ULGATimeline_Statics::NewProp_bLooping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLooping_MetaData), NewProp_bLooping_MetaData) };
void Z_Construct_UClass_ULGATimeline_Statics::NewProp_bAutoPlay_SetBit(void* Obj)
{
	((ULGATimeline*)Obj)->bAutoPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_bAutoPlay = { "bAutoPlay", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGATimeline), &Z_Construct_UClass_ULGATimeline_Statics::NewProp_bAutoPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoPlay_MetaData), NewProp_bAutoPlay_MetaData) };
void Z_Construct_UClass_ULGATimeline_Statics::NewProp_bStopAbility_SetBit(void* Obj)
{
	((ULGATimeline*)Obj)->bStopAbility = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_bStopAbility = { "bStopAbility", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGATimeline), &Z_Construct_UClass_ULGATimeline_Statics::NewProp_bStopAbility_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopAbility_MetaData), NewProp_bStopAbility_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_TimeStretchCurveName = { "TimeStretchCurveName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, TimeStretchCurveName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeStretchCurveName_MetaData), NewProp_TimeStretchCurveName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, StartTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTimeSeconds_MetaData), NewProp_StartTimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_DynamicBlendSettings_Inner = { "DynamicBlendSettings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGATimelineBlendSetting, METADATA_PARAMS(0, nullptr) }; // 1504984085
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_DynamicBlendSettings = { "DynamicBlendSettings", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, DynamicBlendSettings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicBlendSettings_MetaData), NewProp_DynamicBlendSettings_MetaData) }; // 1504984085
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGATimeline_Statics::NewProp_PreviewWeapon = { "PreviewWeapon", nullptr, (EPropertyFlags)0x0010000800000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGATimeline, PreviewWeapon), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewWeapon_MetaData), NewProp_PreviewWeapon_MetaData) }; // 133831994
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULGATimeline_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_AbilityActionTracks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_AbilityActionTracks,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_TimelineTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_FloatCurves_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_FloatCurves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_SequenceLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_bLooping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_bAutoPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_bStopAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_TimeStretchCurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_StartTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_DynamicBlendSettings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_DynamicBlendSettings,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGATimeline_Statics::NewProp_PreviewWeapon,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATimeline_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULGATimeline_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATimeline_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGATimeline_Statics::ClassParams = {
	&ULGATimeline::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULGATimeline_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULGATimeline_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGATimeline_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGATimeline_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGATimeline()
{
	if (!Z_Registration_Info_UClass_ULGATimeline.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGATimeline.OuterSingleton, Z_Construct_UClass_ULGATimeline_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGATimeline.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGATimeline);
ULGATimeline::~ULGATimeline() {}
// ********** End Class ULGATimeline ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGAActionEventSection::StaticStruct, Z_Construct_UScriptStruct_FLGAActionEventSection_Statics::NewStructOps, TEXT("LGAActionEventSection"), &Z_Registration_Info_UScriptStruct_FLGAActionEventSection, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionEventSection), 2307969658U) },
		{ FLGAActionEvent::StaticStruct, Z_Construct_UScriptStruct_FLGAActionEvent_Statics::NewStructOps, TEXT("LGAActionEvent"), &Z_Registration_Info_UScriptStruct_FLGAActionEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionEvent), 3071200278U) },
		{ FLGAActionTrack::StaticStruct, Z_Construct_UScriptStruct_FLGAActionTrack_Statics::NewStructOps, TEXT("LGAActionTrack"), &Z_Registration_Info_UScriptStruct_FLGAActionTrack, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionTrack), 395941141U) },
		{ FLGATimelineBlendSetting::StaticStruct, Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics::NewStructOps, TEXT("LGATimelineBlendSetting"), &Z_Registration_Info_UScriptStruct_FLGATimelineBlendSetting, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGATimelineBlendSetting), 1504984085U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGATimeline, ULGATimeline::StaticClass, TEXT("ULGATimeline"), &Z_Registration_Info_UClass_ULGATimeline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGATimeline), 3814933510U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_926778539(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h__Script_LegoAbility_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
