// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LGATask_PlayTimeline.h"

#ifdef LEGOABILITY_LGATask_PlayTimeline_generated_h
#error "LGATask_PlayTimeline.generated.h already included, missing '#pragma once' in LGATask_PlayTimeline.h"
#endif
#define LEGOABILITY_LGATask_PlayTimeline_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UGameplayAbility;
class ULGATask_PlayTimeline;
class ULGATimeline;

// ********** Begin Delegate FTimelineWaitSimpleDelegate *******************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_12_DELEGATE \
LEGOABILITY_API void FTimelineWaitSimpleDelegate_DelegateWrapper(const FMulticastScriptDelegate& TimelineWaitSimpleDelegate);


// ********** End Delegate FTimelineWaitSimpleDelegate *********************************************

// ********** Begin Class ULGATask_PlayTimeline ****************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPlayTimeline); \
	DECLARE_FUNCTION(execSkipSection); \
	DECLARE_FUNCTION(execSetSectionPlayRate); \
	DECLARE_FUNCTION(execSetPlayRate);


LEGOABILITY_API UClass* Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGATask_PlayTimeline(); \
	friend struct Z_Construct_UClass_ULGATask_PlayTimeline_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGATask_PlayTimeline, UAbilityTask, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGATask_PlayTimeline_NoRegister) \
	DECLARE_SERIALIZER(ULGATask_PlayTimeline)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGATask_PlayTimeline(ULGATask_PlayTimeline&&) = delete; \
	ULGATask_PlayTimeline(const ULGATask_PlayTimeline&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGATask_PlayTimeline); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGATask_PlayTimeline); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULGATask_PlayTimeline) \
	NO_API virtual ~ULGATask_PlayTimeline();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_17_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGATask_PlayTimeline;

// ********** End Class ULGATask_PlayTimeline ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LGATask_PlayTimeline_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
