// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/LGAAction.h"

#ifdef LEGOABILITY_LGAAction_generated_h
#error "LGAAction.generated.h already included, missing '#pragma once' in LGAAction.h"
#endif
#define LEGOABILITY_LGAAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UAbilitySystemComponent;
class ULegoAbility;
class ULGATimeline;
struct FGameplayTagContainer;
struct FLGAActionEvent;

// ********** Begin Class ULGAAction ***************************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FString GetActionName_Implementation() const; \
	DECLARE_FUNCTION(execGetActionTags); \
	DECLARE_FUNCTION(execHasAuthority); \
	DECLARE_FUNCTION(execIsLocallyControlled); \
	DECLARE_FUNCTION(execIsSimulatedAction); \
	DECLARE_FUNCTION(execGetActionEvent); \
	DECLARE_FUNCTION(execGetTimeline); \
	DECLARE_FUNCTION(execGetAbility); \
	DECLARE_FUNCTION(execGetAbilitySystemComponent); \
	DECLARE_FUNCTION(execGetAvatarActor); \
	DECLARE_FUNCTION(execGetActionName); \
	DECLARE_FUNCTION(execIsLoopAction);


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_CALLBACK_WRAPPERS
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGAAction(); \
	friend struct Z_Construct_UClass_ULGAAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGAAction, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGAAction_NoRegister) \
	DECLARE_SERIALIZER(ULGAAction)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGAAction(ULGAAction&&) = delete; \
	ULGAAction(const ULGAAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGAAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGAAction); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ULGAAction)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_26_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGAAction;

// ********** End Class ULGAAction *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h

// ********** Begin Enum EGameplayActionNetExecutionPolicy *****************************************
#define FOREACH_ENUM_EGAMEPLAYACTIONNETEXECUTIONPOLICY(op) \
	op(EGameplayActionNetExecutionPolicy::Always) \
	op(EGameplayActionNetExecutionPolicy::LocalOnly) \
	op(EGameplayActionNetExecutionPolicy::ServerOnly) 

enum class EGameplayActionNetExecutionPolicy : uint8;
template<> struct TIsUEnumClass<EGameplayActionNetExecutionPolicy> { enum { Value = true }; };
template<> LEGOABILITY_API UEnum* StaticEnum<EGameplayActionNetExecutionPolicy>();
// ********** End Enum EGameplayActionNetExecutionPolicy *******************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
