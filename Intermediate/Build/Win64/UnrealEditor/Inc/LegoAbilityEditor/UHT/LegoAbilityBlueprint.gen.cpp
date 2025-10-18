// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityBlueprint.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityBlueprint() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
ENGINE_API UClass* Z_Construct_UClass_UBlueprint();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprint();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister();
LEGOABILITYEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineOverride();
UPackage* Z_Construct_UPackage__Script_LegoAbilityEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGATimelineOverride **********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGATimelineOverride;
class UScriptStruct* FLGATimelineOverride::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGATimelineOverride.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGATimelineOverride.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGATimelineOverride, (UObject*)Z_Construct_UPackage__Script_LegoAbilityEditor(), TEXT("LGATimelineOverride"));
	}
	return Z_Registration_Info_UScriptStruct_FLGATimelineOverride.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGATimelineOverride_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverriddenTimeline_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timeline_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInheritMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentTimeline_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionOverrides_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverriddenTimeline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Timeline;
	static void NewProp_bInheritMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInheritMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentTimeline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionOverrides_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionOverrides_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ActionOverrides;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGATimelineOverride>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_OverriddenTimeline = { "OverriddenTimeline", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineOverride, OverriddenTimeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverriddenTimeline_MetaData), NewProp_OverriddenTimeline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_Timeline = { "Timeline", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineOverride, Timeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timeline_MetaData), NewProp_Timeline_MetaData) };
void Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_bInheritMode_SetBit(void* Obj)
{
	((FLGATimelineOverride*)Obj)->bInheritMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_bInheritMode = { "bInheritMode", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FLGATimelineOverride), &Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_bInheritMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInheritMode_MetaData), NewProp_bInheritMode_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ParentTimeline = { "ParentTimeline", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineOverride, ParentTimeline), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentTimeline_MetaData), NewProp_ParentTimeline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides_ValueProp = { "ActionOverrides", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides_Key_KeyProp = { "ActionOverrides_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides = { "ActionOverrides", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGATimelineOverride, ActionOverrides), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionOverrides_MetaData), NewProp_ActionOverrides_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_OverriddenTimeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_Timeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_bInheritMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ParentTimeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewProp_ActionOverrides,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
	nullptr,
	&NewStructOps,
	"LGATimelineOverride",
	Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::PropPointers),
	sizeof(FLGATimelineOverride),
	alignof(FLGATimelineOverride),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineOverride()
{
	if (!Z_Registration_Info_UScriptStruct_FLGATimelineOverride.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGATimelineOverride.InnerSingleton, Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGATimelineOverride.InnerSingleton;
}
// ********** End ScriptStruct FLGATimelineOverride ************************************************

// ********** Begin Class ULegoAbilityBlueprint ****************************************************
void ULegoAbilityBlueprint::StaticRegisterNativesULegoAbilityBlueprint()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityBlueprint;
UClass* ULegoAbilityBlueprint::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityBlueprint;
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprint.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityBlueprint"),
			Z_Registration_Info_UClass_ULegoAbilityBlueprint.InnerSingleton,
			StaticRegisterNativesULegoAbilityBlueprint,
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
	return Z_Registration_Info_UClass_ULegoAbilityBlueprint.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister()
{
	return ULegoAbilityBlueprint::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityBlueprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "LegoAbilityBlueprint.h" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewAsset_MetaData[] = {
		{ "Comment", "/** Preview Asset Path */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
		{ "ToolTip", "Preview Asset Path" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetAsset_MetaData[] = {
		{ "Comment", "/** Target Asset Path */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
		{ "ToolTip", "Target Asset Path" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThumbnailImage_MetaData[] = {
		{ "Comment", "/** If the user has manually chosen a thumbnail image, use that. */" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
		{ "ToolTip", "If the user has manually chosen a thumbnail image, use that." },
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityTimelines_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityTimelineOverrides_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprint.h" },
	};
#endif // WITH_METADATA
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewAsset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThumbnailImage;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilityTimelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AbilityTimelines;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AbilityTimelineOverrides_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AbilityTimelineOverrides;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityBlueprint>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_PreviewAsset = { "PreviewAsset", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprint, PreviewAsset), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewAsset_MetaData), NewProp_PreviewAsset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_TargetAsset = { "TargetAsset", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprint, TargetAsset), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetAsset_MetaData), NewProp_TargetAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_ThumbnailImage = { "ThumbnailImage", nullptr, (EPropertyFlags)0x0010000800000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprint, ThumbnailImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThumbnailImage_MetaData), NewProp_ThumbnailImage_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelines_Inner = { "AbilityTimelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelines = { "AbilityTimelines", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprint, AbilityTimelines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityTimelines_MetaData), NewProp_AbilityTimelines_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelineOverrides_Inner = { "AbilityTimelineOverrides", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGATimelineOverride, METADATA_PARAMS(0, nullptr) }; // 2625819498
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelineOverrides = { "AbilityTimelineOverrides", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprint, AbilityTimelineOverrides), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityTimelineOverrides_MetaData), NewProp_AbilityTimelineOverrides_MetaData) }; // 2625819498
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbilityBlueprint_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_PreviewAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_TargetAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_ThumbnailImage,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelines,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelineOverrides_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprint_Statics::NewProp_AbilityTimelineOverrides,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprint_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbilityBlueprint_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprint,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprint_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityBlueprint_Statics::ClassParams = {
	&ULegoAbilityBlueprint::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULegoAbilityBlueprint_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprint_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprint_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityBlueprint_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityBlueprint()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprint.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityBlueprint.OuterSingleton, Z_Construct_UClass_ULegoAbilityBlueprint_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityBlueprint.OuterSingleton;
}
ULegoAbilityBlueprint::ULegoAbilityBlueprint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityBlueprint);
ULegoAbilityBlueprint::~ULegoAbilityBlueprint() {}
// ********** End Class ULegoAbilityBlueprint ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGATimelineOverride::StaticStruct, Z_Construct_UScriptStruct_FLGATimelineOverride_Statics::NewStructOps, TEXT("LGATimelineOverride"), &Z_Registration_Info_UScriptStruct_FLGATimelineOverride, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGATimelineOverride), 2625819498U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityBlueprint, ULegoAbilityBlueprint::StaticClass, TEXT("ULegoAbilityBlueprint"), &Z_Registration_Info_UClass_ULegoAbilityBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityBlueprint), 941403878U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_2322775098(TEXT("/Script/LegoAbilityEditor"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h__Script_LegoAbilityEditor_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
