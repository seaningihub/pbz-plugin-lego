// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LGATimeline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityBlueprintGeneratedClass() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintGeneratedClass();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionOverride();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGATimelineBlendSetting();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGAActionOverride ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionOverride;
class UScriptStruct* FLGAActionOverride::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionOverride.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionOverride.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionOverride, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionOverride"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionOverride.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionOverride_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimelineName_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Overrides_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeStretchCurveName_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTimeSeconds_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicBlendSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimelineName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Overrides_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Overrides_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Overrides;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TimeStretchCurveName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DynamicBlendSettings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DynamicBlendSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionOverride>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_TimelineName = { "TimelineName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionOverride, TimelineName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimelineName_MetaData), NewProp_TimelineName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides_ValueProp = { "Overrides", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_ULGAAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides_Key_KeyProp = { "Overrides_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides = { "Overrides", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionOverride, Overrides), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Overrides_MetaData), NewProp_Overrides_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_TimeStretchCurveName = { "TimeStretchCurveName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionOverride, TimeStretchCurveName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeStretchCurveName_MetaData), NewProp_TimeStretchCurveName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_StartTimeSeconds = { "StartTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionOverride, StartTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTimeSeconds_MetaData), NewProp_StartTimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_DynamicBlendSettings_Inner = { "DynamicBlendSettings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGATimelineBlendSetting, METADATA_PARAMS(0, nullptr) }; // 1504984085
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_DynamicBlendSettings = { "DynamicBlendSettings", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLGAActionOverride, DynamicBlendSettings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicBlendSettings_MetaData), NewProp_DynamicBlendSettings_MetaData) }; // 1504984085
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLGAActionOverride_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_TimelineName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_Overrides,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_TimeStretchCurveName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_StartTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_DynamicBlendSettings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewProp_DynamicBlendSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionOverride_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionOverride_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionOverride",
	Z_Construct_UScriptStruct_FLGAActionOverride_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionOverride_Statics::PropPointers),
	sizeof(FLGAActionOverride),
	alignof(FLGAActionOverride),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionOverride_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionOverride_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionOverride()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionOverride.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionOverride.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionOverride_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionOverride.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionOverride **************************************************

// ********** Begin Class ULegoAbilityBlueprintGeneratedClass **************************************
void ULegoAbilityBlueprintGeneratedClass::StaticRegisterNativesULegoAbilityBlueprintGeneratedClass()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass;
UClass* ULegoAbilityBlueprintGeneratedClass::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityBlueprintGeneratedClass;
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityBlueprintGeneratedClass"),
			Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.InnerSingleton,
			StaticRegisterNativesULegoAbilityBlueprintGeneratedClass,
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
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_NoRegister()
{
	return ULegoAbilityBlueprintGeneratedClass::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "LegoAbilityBlueprintGeneratedClass.h" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityTimelines_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionOverrides_MetaData[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintGeneratedClass.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilityTimelines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AbilityTimelines;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionOverrides_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActionOverrides;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityBlueprintGeneratedClass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_AbilityTimelines_Inner = { "AbilityTimelines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_AbilityTimelines = { "AbilityTimelines", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprintGeneratedClass, AbilityTimelines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityTimelines_MetaData), NewProp_AbilityTimelines_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_ActionOverrides_Inner = { "ActionOverrides", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLGAActionOverride, METADATA_PARAMS(0, nullptr) }; // 1338963144
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_ActionOverrides = { "ActionOverrides", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprintGeneratedClass, ActionOverrides), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionOverrides_MetaData), NewProp_ActionOverrides_MetaData) }; // 1338963144
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_AbilityTimelines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_AbilityTimelines,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_ActionOverrides_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::NewProp_ActionOverrides,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintGeneratedClass,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::ClassParams = {
	&ULegoAbilityBlueprintGeneratedClass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::PropPointers),
	0,
	0x009200A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.OuterSingleton, Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass.OuterSingleton;
}
ULegoAbilityBlueprintGeneratedClass::ULegoAbilityBlueprintGeneratedClass(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityBlueprintGeneratedClass);
ULegoAbilityBlueprintGeneratedClass::~ULegoAbilityBlueprintGeneratedClass() {}
// ********** End Class ULegoAbilityBlueprintGeneratedClass ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGAActionOverride::StaticStruct, Z_Construct_UScriptStruct_FLGAActionOverride_Statics::NewStructOps, TEXT("LGAActionOverride"), &Z_Registration_Info_UScriptStruct_FLGAActionOverride, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionOverride), 1338963144U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityBlueprintGeneratedClass, ULegoAbilityBlueprintGeneratedClass::StaticClass, TEXT("ULegoAbilityBlueprintGeneratedClass"), &Z_Registration_Info_UClass_ULegoAbilityBlueprintGeneratedClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityBlueprintGeneratedClass), 3795409813U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_78309901(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintGeneratedClass_h__Script_LegoAbility_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
