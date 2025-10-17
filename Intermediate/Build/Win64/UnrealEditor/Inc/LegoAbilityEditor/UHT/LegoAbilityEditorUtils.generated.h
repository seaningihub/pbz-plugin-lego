// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbilityEditorUtils.h"

#ifdef LEGOABILITYEDITOR_LegoAbilityEditorUtils_generated_h
#error "LegoAbilityEditorUtils.generated.h already included, missing '#pragma once' in LegoAbilityEditorUtils.h"
#endif
#define LEGOABILITYEDITOR_LegoAbilityEditorUtils_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UBlueprint;
class ULegoAbilityBlueprint;
class ULGATimeline;
struct FLGAActionEvent;
struct FLGAActionEventHandle;
struct FLGAActionTrack;
struct FLGATimelineOverride;

// ********** Begin ScriptStruct FLGAActionEventHandle *********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionEventHandle_Statics; \
	LEGOABILITYEDITOR_API static class UScriptStruct* StaticStruct();


struct FLGAActionEventHandle;
// ********** End ScriptStruct FLGAActionEventHandle ***********************************************

// ********** Begin Class ULegoAbilityEditorUtils **************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetActionEventByHandle); \
	DECLARE_FUNCTION(execGetActionEventByHandle); \
	DECLARE_FUNCTION(execGetTrackActionEvents); \
	DECLARE_FUNCTION(execSetOverridenTimelines); \
	DECLARE_FUNCTION(execGetOverridenTimelines); \
	DECLARE_FUNCTION(execSetAbilityTimelines); \
	DECLARE_FUNCTION(execGetAbilityTimelineByName); \
	DECLARE_FUNCTION(execGetAbilityTimelines); \
	DECLARE_FUNCTION(execToLegoAbilityBlueprint);


LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorUtils_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULegoAbilityEditorUtils(); \
	friend struct Z_Construct_UClass_ULegoAbilityEditorUtils_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityEditorUtils_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbilityEditorUtils, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LegoAbilityEditor"), Z_Construct_UClass_ULegoAbilityEditorUtils_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbilityEditorUtils)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULegoAbilityEditorUtils(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbilityEditorUtils(ULegoAbilityEditorUtils&&) = delete; \
	ULegoAbilityEditorUtils(const ULegoAbilityEditorUtils&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULegoAbilityEditorUtils); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbilityEditorUtils); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULegoAbilityEditorUtils) \
	NO_API virtual ~ULegoAbilityEditorUtils();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_28_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbilityEditorUtils;

// ********** End Class ULegoAbilityEditorUtils ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityEditorUtils_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
