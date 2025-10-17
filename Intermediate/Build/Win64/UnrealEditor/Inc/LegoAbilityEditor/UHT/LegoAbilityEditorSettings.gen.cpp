// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityEditorSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityEditorSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorSettings();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorSettings_NoRegister();
LEGOABILITYEDITOR_API UEnum* Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep();
TIMEMANAGEMENT_API UEnum* Z_Construct_UEnum_TimeManagement_EFrameNumberDisplayFormats();
UPackage* Z_Construct_UPackage__Script_LegoAbilityEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ELegoAbilityEditorTimeStep ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep;
static UEnum* ELegoAbilityEditorTimeStep_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep, (UObject*)Z_Construct_UPackage__Script_LegoAbilityEditor(), TEXT("ELegoAbilityEditorTimeStep"));
	}
	return Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.OuterSingleton;
}
template<> LEGOABILITYEDITOR_API UEnum* StaticEnum<ELegoAbilityEditorTimeStep>()
{
	return ELegoAbilityEditorTimeStep_StaticEnum();
}
struct Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "FifteenFPS.DisplayName", "15 FPS" },
		{ "FifteenFPS.Name", "ELegoAbilityEditorTimeStep::FifteenFPS" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "SixtyFPS.DisplayName", "60 FPS" },
		{ "SixtyFPS.Name", "ELegoAbilityEditorTimeStep::SixtyFPS" },
		{ "ThirtyFPS.DisplayName", "30 FPS" },
		{ "ThirtyFPS.Name", "ELegoAbilityEditorTimeStep::ThirtyFPS" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ELegoAbilityEditorTimeStep::FifteenFPS", (int64)ELegoAbilityEditorTimeStep::FifteenFPS },
		{ "ELegoAbilityEditorTimeStep::ThirtyFPS", (int64)ELegoAbilityEditorTimeStep::ThirtyFPS },
		{ "ELegoAbilityEditorTimeStep::SixtyFPS", (int64)ELegoAbilityEditorTimeStep::SixtyFPS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
	nullptr,
	"ELegoAbilityEditorTimeStep",
	"ELegoAbilityEditorTimeStep",
	Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep()
{
	if (!Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.InnerSingleton, Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep.InnerSingleton;
}
// ********** End Enum ELegoAbilityEditorTimeStep **************************************************

// ********** Begin Class ULegoAbilityEditorSettings ***********************************************
void ULegoAbilityEditorSettings::StaticRegisterNativesULegoAbilityEditorSettings()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityEditorSettings;
UClass* ULegoAbilityEditorSettings::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityEditorSettings;
	if (!Z_Registration_Info_UClass_ULegoAbilityEditorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityEditorSettings"),
			Z_Registration_Info_UClass_ULegoAbilityEditorSettings.InnerSingleton,
			StaticRegisterNativesULegoAbilityEditorSettings,
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
	return Z_Registration_Info_UClass_ULegoAbilityEditorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityEditorSettings_NoRegister()
{
	return ULegoAbilityEditorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityEditorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "// Settings for the Lego Ability editor\n" },
		{ "IncludePath", "LegoAbilityEditorSettings.h" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Settings for the Lego Ability editor" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FOV_MetaData[] = {
		{ "Category", "Viewport" },
		{ "ClampMax", "180.000000" },
		{ "ClampMin", "70.000000" },
		{ "Comment", "/* What to set the Field of View (FOV) to for the in-game viewport in the Ability Editor.*/" },
		{ "DisplayName", "Field of View" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "What to set the Field of View (FOV) to for the in-game viewport in the Ability Editor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMuteAudio_MetaData[] = {
		{ "Category", "Viewport" },
		{ "Comment", "/* Whether to mute the in-game audio of the viewport or not.*/" },
		{ "DisplayName", "Mute Audio" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Whether to mute the in-game audio of the viewport or not." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilityStepTimeStep_MetaData[] = {
		{ "Category", "Viewport" },
		{ "Comment", "/* At what rate to step an Ability when paused and stepping frame by frame.*/" },
		{ "DisplayName", "Ability Step Rate" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "At what rate to step an Ability when paused and stepping frame by frame." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewAllowedClasses_MetaData[] = {
		{ "Category", "Preview" },
		{ "Comment", "/* The target asset used in the Viewport.*/" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "The target asset used in the Viewport." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimelineScrubSnapValue_MetaData[] = {
		{ "Comment", "/** Snap value used to determine scrub resolution of the ability timeline */" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Snap value used to determine scrub resolution of the ability timeline" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimelineDisplayFormat_MetaData[] = {
		{ "Comment", "/** Display format for the ability timeline */" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Display format for the ability timeline" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTimelineDisplayPercentage_MetaData[] = {
		{ "Comment", "/** Whether to display percentage in the ability timeline */" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Whether to display percentage in the ability timeline" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTimelineDisplayFormatSecondary_MetaData[] = {
		{ "Comment", "/** Whether to display secondary format (times/frames) in the ability timeline */" },
		{ "ModuleRelativePath", "Private/LegoAbilityEditorSettings.h" },
		{ "ToolTip", "Whether to display secondary format (times/frames) in the ability timeline" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FOV;
	static void NewProp_bMuteAudio_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMuteAudio;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AbilityStepTimeStep_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AbilityStepTimeStep;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_PreviewAllowedClasses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PreviewAllowedClasses;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TimelineScrubSnapValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TimelineDisplayFormat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TimelineDisplayFormat;
	static void NewProp_bTimelineDisplayPercentage_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTimelineDisplayPercentage;
	static void NewProp_bTimelineDisplayFormatSecondary_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTimelineDisplayFormatSecondary;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityEditorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_FOV = { "FOV", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityEditorSettings, FOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FOV_MetaData), NewProp_FOV_MetaData) };
void Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bMuteAudio_SetBit(void* Obj)
{
	((ULegoAbilityEditorSettings*)Obj)->bMuteAudio = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bMuteAudio = { "bMuteAudio", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULegoAbilityEditorSettings), &Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bMuteAudio_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMuteAudio_MetaData), NewProp_bMuteAudio_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_AbilityStepTimeStep_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_AbilityStepTimeStep = { "AbilityStepTimeStep", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityEditorSettings, AbilityStepTimeStep), Z_Construct_UEnum_LegoAbilityEditor_ELegoAbilityEditorTimeStep, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilityStepTimeStep_MetaData), NewProp_AbilityStepTimeStep_MetaData) }; // 106055788
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_PreviewAllowedClasses_Inner = { "PreviewAllowedClasses", nullptr, (EPropertyFlags)0x0004000000004000, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_PreviewAllowedClasses = { "PreviewAllowedClasses", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityEditorSettings, PreviewAllowedClasses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewAllowedClasses_MetaData), NewProp_PreviewAllowedClasses_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineScrubSnapValue = { "TimelineScrubSnapValue", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityEditorSettings, TimelineScrubSnapValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimelineScrubSnapValue_MetaData), NewProp_TimelineScrubSnapValue_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineDisplayFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineDisplayFormat = { "TimelineDisplayFormat", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityEditorSettings, TimelineDisplayFormat), Z_Construct_UEnum_TimeManagement_EFrameNumberDisplayFormats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimelineDisplayFormat_MetaData), NewProp_TimelineDisplayFormat_MetaData) }; // 4182580297
void Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_SetBit(void* Obj)
{
	((ULegoAbilityEditorSettings*)Obj)->bTimelineDisplayPercentage = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayPercentage = { "bTimelineDisplayPercentage", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULegoAbilityEditorSettings), &Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayPercentage_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTimelineDisplayPercentage_MetaData), NewProp_bTimelineDisplayPercentage_MetaData) };
void Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayFormatSecondary_SetBit(void* Obj)
{
	((ULegoAbilityEditorSettings*)Obj)->bTimelineDisplayFormatSecondary = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayFormatSecondary = { "bTimelineDisplayFormatSecondary", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULegoAbilityEditorSettings), &Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayFormatSecondary_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTimelineDisplayFormatSecondary_MetaData), NewProp_bTimelineDisplayFormatSecondary_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_FOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bMuteAudio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_AbilityStepTimeStep_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_AbilityStepTimeStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_PreviewAllowedClasses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_PreviewAllowedClasses,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineScrubSnapValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineDisplayFormat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_TimelineDisplayFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::NewProp_bTimelineDisplayFormatSecondary,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::ClassParams = {
	&ULegoAbilityEditorSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::PropPointers),
	0,
	0x000000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityEditorSettings()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityEditorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityEditorSettings.OuterSingleton, Z_Construct_UClass_ULegoAbilityEditorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityEditorSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityEditorSettings);
ULegoAbilityEditorSettings::~ULegoAbilityEditorSettings() {}
// ********** End Class ULegoAbilityEditorSettings *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ELegoAbilityEditorTimeStep_StaticEnum, TEXT("ELegoAbilityEditorTimeStep"), &Z_Registration_Info_UEnum_ELegoAbilityEditorTimeStep, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 106055788U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityEditorSettings, ULegoAbilityEditorSettings::StaticClass, TEXT("ULegoAbilityEditorSettings"), &Z_Registration_Info_UClass_ULegoAbilityEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityEditorSettings), 1293247111U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_3881396168(TEXT("/Script/LegoAbilityEditor"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h__Script_LegoAbilityEditor_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
