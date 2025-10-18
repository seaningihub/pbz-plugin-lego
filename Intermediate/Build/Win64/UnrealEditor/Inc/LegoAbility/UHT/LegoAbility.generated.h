// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbility.h"

#ifdef LEGOABILITY_LegoAbility_generated_h
#error "LegoAbility.generated.h already included, missing '#pragma once' in LegoAbility.h"
#endif
#define LEGOABILITY_LegoAbility_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class ULGAAction;
class ULGAAction_Executable;
class ULGATask_PlayTimeline;
class ULGATimeline;
struct FGameplayTagRequirements;
struct FLGAActionExecutionContextHandle;

// ********** Begin ScriptStruct FLGAEventAction ***************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAEventAction_Statics; \
	LEGOABILITY_API static class UScriptStruct* StaticStruct();


struct FLGAEventAction;
// ********** End ScriptStruct FLGAEventAction *****************************************************

// ********** Begin Class ULegoAbility *************************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAllTimelineNames); \
	DECLARE_FUNCTION(execExecuteAction); \
	DECLARE_FUNCTION(execGetPlayTimelineTask); \
	DECLARE_FUNCTION(execGetCurveValue); \
	DECLARE_FUNCTION(execIsPlayingAnyTimeline); \
	DECLARE_FUNCTION(execIsPlayingTimeline); \
	DECLARE_FUNCTION(execEndTimelineByName); \
	DECLARE_FUNCTION(execEndTimeline); \
	DECLARE_FUNCTION(execPlayTimelineByName); \
	DECLARE_FUNCTION(execPlayTimeline); \
	DECLARE_FUNCTION(execGetActionsByTag); \
	DECLARE_FUNCTION(execGetActionByName); \
	DECLARE_FUNCTION(execGetTimelineByIndex); \
	DECLARE_FUNCTION(execGetTimelineByName); \
	DECLARE_FUNCTION(execGetDisplayName);


LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULegoAbility(); \
	friend struct Z_Construct_UClass_ULegoAbility_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULegoAbility_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbility)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULegoAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbility(ULegoAbility&&) = delete; \
	ULegoAbility(const ULegoAbility&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULegoAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbility); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULegoAbility) \
	NO_API virtual ~ULegoAbility();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_26_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbility;

// ********** End Class ULegoAbility ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbility_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
