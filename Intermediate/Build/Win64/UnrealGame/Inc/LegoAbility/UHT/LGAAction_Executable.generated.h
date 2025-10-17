// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/LGAAction_Executable.h"

#ifdef LEGOABILITY_LGAAction_Executable_generated_h
#error "LGAAction_Executable.generated.h already included, missing '#pragma once' in LGAAction_Executable.h"
#endif
#define LEGOABILITY_LGAAction_Executable_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FLGAActionExecutionContextHandle;

// ********** Begin ScriptStruct FLGAActionExecutionContext ****************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics; \
	LEGOABILITY_API static class UScriptStruct* StaticStruct();


struct FLGAActionExecutionContext;
// ********** End ScriptStruct FLGAActionExecutionContext ******************************************

// ********** Begin ScriptStruct FLGAActionExecutionContextHandle **********************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics; \
	LEGOABILITY_API static class UScriptStruct* StaticStruct();


struct FLGAActionExecutionContextHandle;
// ********** End ScriptStruct FLGAActionExecutionContextHandle ************************************

// ********** Begin Class ULGAAction_Executable ****************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ExecuteAction_Implementation(FLGAActionExecutionContextHandle Context); \
	DECLARE_FUNCTION(execExecuteAction);


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_CALLBACK_WRAPPERS
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGAAction_Executable(); \
	friend struct Z_Construct_UClass_ULGAAction_Executable_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGAAction_Executable, ULGAAction, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGAAction_Executable_NoRegister) \
	DECLARE_SERIALIZER(ULGAAction_Executable)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGAAction_Executable(ULGAAction_Executable&&) = delete; \
	ULGAAction_Executable(const ULGAAction_Executable&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGAAction_Executable); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGAAction_Executable); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ULGAAction_Executable) \
	NO_API virtual ~ULGAAction_Executable();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_84_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h_87_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGAAction_Executable;

// ********** End Class ULGAAction_Executable ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
