// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbilityEditorSettings.h"

#ifdef LEGOABILITYEDITOR_LegoAbilityEditorSettings_generated_h
#error "LegoAbilityEditorSettings.generated.h already included, missing '#pragma once' in LegoAbilityEditorSettings.h"
#endif
#define LEGOABILITYEDITOR_LegoAbilityEditorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ULegoAbilityEditorSettings ***********************************************
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorSettings_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULegoAbilityEditorSettings(); \
	friend struct Z_Construct_UClass_ULegoAbilityEditorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbilityEditorSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LegoAbilityEditor"), Z_Construct_UClass_ULegoAbilityEditorSettings_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbilityEditorSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbilityEditorSettings(ULegoAbilityEditorSettings&&) = delete; \
	ULegoAbilityEditorSettings(const ULegoAbilityEditorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULegoAbilityEditorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbilityEditorSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULegoAbilityEditorSettings) \
	NO_API virtual ~ULegoAbilityEditorSettings();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_18_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_21_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbilityEditorSettings;

// ********** End Class ULegoAbilityEditorSettings *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityEditorSettings_h

// ********** Begin Enum ELegoAbilityEditorTimeStep ************************************************
#define FOREACH_ENUM_ELEGOABILITYEDITORTIMESTEP(op) \
	op(ELegoAbilityEditorTimeStep::FifteenFPS) \
	op(ELegoAbilityEditorTimeStep::ThirtyFPS) \
	op(ELegoAbilityEditorTimeStep::SixtyFPS) 

enum class ELegoAbilityEditorTimeStep : uint8;
template<> struct TIsUEnumClass<ELegoAbilityEditorTimeStep> { enum { Value = true }; };
template<> LEGOABILITYEDITOR_API UEnum* StaticEnum<ELegoAbilityEditorTimeStep>();
// ********** End Enum ELegoAbilityEditorTimeStep **************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
