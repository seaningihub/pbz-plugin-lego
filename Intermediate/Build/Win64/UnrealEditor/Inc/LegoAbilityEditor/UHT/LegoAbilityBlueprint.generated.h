// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbilityBlueprint.h"

#ifdef LEGOABILITYEDITOR_LegoAbilityBlueprint_generated_h
#error "LegoAbilityBlueprint.generated.h already included, missing '#pragma once' in LegoAbilityBlueprint.h"
#endif
#define LEGOABILITYEDITOR_LegoAbilityBlueprint_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FLGATimelineOverride **********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGATimelineOverride_Statics; \
	LEGOABILITYEDITOR_API static class UScriptStruct* StaticStruct();


struct FLGATimelineOverride;
// ********** End ScriptStruct FLGATimelineOverride ************************************************

// ********** Begin Class ULegoAbilityBlueprint ****************************************************
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULegoAbilityBlueprint(); \
	friend struct Z_Construct_UClass_ULegoAbilityBlueprint_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbilityBlueprint, UBlueprint, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LegoAbilityEditor"), Z_Construct_UClass_ULegoAbilityBlueprint_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbilityBlueprint)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULegoAbilityBlueprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbilityBlueprint(ULegoAbilityBlueprint&&) = delete; \
	ULegoAbilityBlueprint(const ULegoAbilityBlueprint&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULegoAbilityBlueprint); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbilityBlueprint); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULegoAbilityBlueprint) \
	NO_API virtual ~ULegoAbilityBlueprint();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_35_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_38_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbilityBlueprint;

// ********** End Class ULegoAbilityBlueprint ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprint_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
