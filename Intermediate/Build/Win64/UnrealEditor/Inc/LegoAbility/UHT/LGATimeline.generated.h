// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LGATimeline.h"

#ifdef LEGOABILITY_LGATimeline_generated_h
#error "LGATimeline.generated.h already included, missing '#pragma once' in LGATimeline.h"
#endif
#define LEGOABILITY_LGATimeline_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FLGAActionEventSection ********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionEventSection_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLGAActionEventSection;
// ********** End ScriptStruct FLGAActionEventSection **********************************************

// ********** Begin ScriptStruct FLGAActionEvent ***************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_47_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionEvent_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLGAActionEvent;
// ********** End ScriptStruct FLGAActionEvent *****************************************************

// ********** Begin ScriptStruct FLGAActionTrack ***************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_140_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionTrack_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLGAActionTrack;
// ********** End ScriptStruct FLGAActionTrack *****************************************************

// ********** Begin ScriptStruct FLGATimelineBlendSetting ******************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_158_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGATimelineBlendSetting_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLGATimelineBlendSetting;
// ********** End ScriptStruct FLGATimelineBlendSetting ********************************************

// ********** Begin Class ULGATimeline *************************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPreviousTimelineNames); \
	DECLARE_FUNCTION(execGetOriginalStep); \
	DECLARE_FUNCTION(execGetScaledTimeStep); \
	DECLARE_FUNCTION(execAddCurve); \
	DECLARE_FUNCTION(execRemoveCurve);


LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGATimeline(); \
	friend struct Z_Construct_UClass_ULGATimeline_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGATimeline, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGATimeline_NoRegister) \
	DECLARE_SERIALIZER(ULGATimeline)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGATimeline(ULGATimeline&&) = delete; \
	ULGATimeline(const ULGATimeline&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGATimeline); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGATimeline); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULGATimeline) \
	NO_API virtual ~ULGATimeline();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_183_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h_186_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGATimeline;

// ********** End Class ULGATimeline ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATimeline_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
