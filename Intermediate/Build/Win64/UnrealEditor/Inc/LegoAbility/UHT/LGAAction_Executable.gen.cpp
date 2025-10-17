// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction_Executable.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction_Executable() {}

// ********** Begin Cross Module References ********************************************************
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContext();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FLGAActionExecutionContext ****************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext;
class UScriptStruct* FLGAActionExecutionContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionExecutionContext, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionExecutionContext"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Ability Action execution context\n */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_Executable.h" },
		{ "ToolTip", "Ability Action execution context" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionExecutionContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionExecutionContext",
	nullptr,
	0,
	sizeof(FLGAActionExecutionContext),
	alignof(FLGAActionExecutionContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContext()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionExecutionContext ******************************************

// ********** Begin ScriptStruct FLGAActionExecutionContextHandle **********************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle;
class UScriptStruct* FLGAActionExecutionContextHandle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LGAActionExecutionContextHandle"));
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_Executable.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLGAActionExecutionContextHandle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LGAActionExecutionContextHandle",
	nullptr,
	0,
	sizeof(FLGAActionExecutionContextHandle),
	alignof(FLGAActionExecutionContextHandle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle()
{
	if (!Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.InnerSingleton, Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle.InnerSingleton;
}
// ********** End ScriptStruct FLGAActionExecutionContextHandle ************************************

// ********** Begin Class ULGAAction_Executable Function ExecuteAction *****************************
struct LGAAction_Executable_eventExecuteAction_Parms
{
	FLGAActionExecutionContextHandle Context;
};
static FName NAME_ULGAAction_Executable_ExecuteAction = FName(TEXT("ExecuteAction"));
void ULGAAction_Executable::ExecuteAction(FLGAActionExecutionContextHandle Context)
{
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Executable_ExecuteAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		LGAAction_Executable_eventExecuteAction_Parms Parms;
		Parms.Context=Context;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		ExecuteAction_Implementation(Context);
	}
}
struct Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_Executable.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_Executable_eventExecuteAction_Parms, Context), Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle, METADATA_PARAMS(0, nullptr) }; // 522655166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_Executable, nullptr, "ExecuteAction", Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::PropPointers), sizeof(LGAAction_Executable_eventExecuteAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_Executable_eventExecuteAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_Executable::execExecuteAction)
{
	P_GET_STRUCT(FLGAActionExecutionContextHandle,Z_Param_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteAction_Implementation(Z_Param_Context);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_Executable Function ExecuteAction *******************************

// ********** Begin Class ULGAAction_Executable ****************************************************
void ULGAAction_Executable::StaticRegisterNativesULGAAction_Executable()
{
	UClass* Class = ULGAAction_Executable::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteAction", &ULGAAction_Executable::execExecuteAction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction_Executable;
UClass* ULGAAction_Executable::GetPrivateStaticClass()
{
	using TClass = ULGAAction_Executable;
	if (!Z_Registration_Info_UClass_ULGAAction_Executable.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction_Executable"),
			Z_Registration_Info_UClass_ULGAAction_Executable.InnerSingleton,
			StaticRegisterNativesULGAAction_Executable,
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
	return Z_Registration_Info_UClass_ULGAAction_Executable.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister()
{
	return ULGAAction_Executable::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_Executable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Ability Action can be execute.\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction_Executable.h" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_Executable.h" },
		{ "ToolTip", "Ability Action can be execute." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGAAction_Executable_ExecuteAction, "ExecuteAction" }, // 1975989825
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction_Executable>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULGAAction_Executable_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULGAAction,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Executable_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_Executable_Statics::ClassParams = {
	&ULGAAction_Executable::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001030A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Executable_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_Executable_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction_Executable()
{
	if (!Z_Registration_Info_UClass_ULGAAction_Executable.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction_Executable.OuterSingleton, Z_Construct_UClass_ULGAAction_Executable_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction_Executable.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction_Executable);
ULGAAction_Executable::~ULGAAction_Executable() {}
// ********** End Class ULGAAction_Executable ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLGAActionExecutionContext::StaticStruct, Z_Construct_UScriptStruct_FLGAActionExecutionContext_Statics::NewStructOps, TEXT("LGAActionExecutionContext"), &Z_Registration_Info_UScriptStruct_FLGAActionExecutionContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionExecutionContext), 23866920U) },
		{ FLGAActionExecutionContextHandle::StaticStruct, Z_Construct_UScriptStruct_FLGAActionExecutionContextHandle_Statics::NewStructOps, TEXT("LGAActionExecutionContextHandle"), &Z_Registration_Info_UScriptStruct_FLGAActionExecutionContextHandle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLGAActionExecutionContextHandle), 522655166U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction_Executable, ULGAAction_Executable::StaticClass, TEXT("ULGAAction_Executable"), &Z_Registration_Info_UClass_ULGAAction_Executable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction_Executable), 2526022522U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_3990497558(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_Executable_h__Script_LegoAbility_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
