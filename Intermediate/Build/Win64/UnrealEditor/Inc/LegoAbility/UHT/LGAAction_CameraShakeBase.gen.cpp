// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction_CameraShakeBase.h"
#include "LegoAbilityTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction_CameraShakeBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULGAAction_CameraShakeBase Function AddCameraShake ***********************
struct Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics
{
	struct LGAAction_CameraShakeBase_eventAddCameraShake_Parms
	{
		FLegoCameraShakePreviewerAddParams Params;
		UCameraShakeBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_CameraShakeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Params_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Params;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::NewProp_Params = { "Params", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_CameraShakeBase_eventAddCameraShake_Parms, Params), Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Params_MetaData), NewProp_Params_MetaData) }; // 2361453237
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_CameraShakeBase_eventAddCameraShake_Parms, ReturnValue), Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::NewProp_Params,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_CameraShakeBase, nullptr, "AddCameraShake", Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::LGAAction_CameraShakeBase_eventAddCameraShake_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::LGAAction_CameraShakeBase_eventAddCameraShake_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_CameraShakeBase::execAddCameraShake)
{
	P_GET_STRUCT_REF(FLegoCameraShakePreviewerAddParams,Z_Param_Out_Params);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCameraShakeBase**)Z_Param__Result=P_THIS->AddCameraShake(Z_Param_Out_Params);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_CameraShakeBase Function AddCameraShake *************************

// ********** Begin Class ULGAAction_CameraShakeBase Function GetCameraShakeDuration ***************
struct Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics
{
	struct LGAAction_CameraShakeBase_eventGetCameraShakeDuration_Parms
	{
		const TSubclassOf<UCameraShakeBase> ShakeClass;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_CameraShakeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ShakeClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::NewProp_ShakeClass = { "ShakeClass", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_CameraShakeBase_eventGetCameraShakeDuration_Parms, ShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeClass_MetaData), NewProp_ShakeClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_CameraShakeBase_eventGetCameraShakeDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::NewProp_ShakeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_CameraShakeBase, nullptr, "GetCameraShakeDuration", Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::LGAAction_CameraShakeBase_eventGetCameraShakeDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14442401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::LGAAction_CameraShakeBase_eventGetCameraShakeDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_CameraShakeBase::execGetCameraShakeDuration)
{
	P_GET_OBJECT_REF_NO_PTR(TSubclassOf<UCameraShakeBase>,Z_Param_Out_ShakeClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=ULGAAction_CameraShakeBase::GetCameraShakeDuration(Z_Param_Out_ShakeClass);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_CameraShakeBase Function GetCameraShakeDuration *****************

// ********** Begin Class ULGAAction_CameraShakeBase Function RemoveCameraShake ********************
struct Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics
{
	struct LGAAction_CameraShakeBase_eventRemoveCameraShake_Parms
	{
		UCameraShakeBase* ShakeInstance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_CameraShakeBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShakeInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::NewProp_ShakeInstance = { "ShakeInstance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_CameraShakeBase_eventRemoveCameraShake_Parms, ShakeInstance), Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::NewProp_ShakeInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_CameraShakeBase, nullptr, "RemoveCameraShake", Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::LGAAction_CameraShakeBase_eventRemoveCameraShake_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::LGAAction_CameraShakeBase_eventRemoveCameraShake_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_CameraShakeBase::execRemoveCameraShake)
{
	P_GET_OBJECT(UCameraShakeBase,Z_Param_ShakeInstance);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveCameraShake(Z_Param_ShakeInstance);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_CameraShakeBase Function RemoveCameraShake **********************

// ********** Begin Class ULGAAction_CameraShakeBase ***********************************************
void ULGAAction_CameraShakeBase::StaticRegisterNativesULGAAction_CameraShakeBase()
{
	UClass* Class = ULGAAction_CameraShakeBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddCameraShake", &ULGAAction_CameraShakeBase::execAddCameraShake },
		{ "GetCameraShakeDuration", &ULGAAction_CameraShakeBase::execGetCameraShakeDuration },
		{ "RemoveCameraShake", &ULGAAction_CameraShakeBase::execRemoveCameraShake },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction_CameraShakeBase;
UClass* ULGAAction_CameraShakeBase::GetPrivateStaticClass()
{
	using TClass = ULGAAction_CameraShakeBase;
	if (!Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction_CameraShakeBase"),
			Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.InnerSingleton,
			StaticRegisterNativesULGAAction_CameraShakeBase,
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
	return Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase_NoRegister()
{
	return ULGAAction_CameraShakeBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction_CameraShakeBase.h" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_CameraShakeBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGAAction_CameraShakeBase_AddCameraShake, "AddCameraShake" }, // 3347120534
		{ &Z_Construct_UFunction_ULGAAction_CameraShakeBase_GetCameraShakeDuration, "GetCameraShakeDuration" }, // 189990158
		{ &Z_Construct_UFunction_ULGAAction_CameraShakeBase_RemoveCameraShake, "RemoveCameraShake" }, // 946927823
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction_CameraShakeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULGAAction_Executable,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::ClassParams = {
	&ULGAAction_CameraShakeBase::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase()
{
	if (!Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.OuterSingleton, Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction_CameraShakeBase.OuterSingleton;
}
ULGAAction_CameraShakeBase::ULGAAction_CameraShakeBase() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction_CameraShakeBase);
ULGAAction_CameraShakeBase::~ULGAAction_CameraShakeBase() {}
// ********** End Class ULGAAction_CameraShakeBase *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction_CameraShakeBase, ULGAAction_CameraShakeBase::StaticClass, TEXT("ULGAAction_CameraShakeBase"), &Z_Registration_Info_UClass_ULGAAction_CameraShakeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction_CameraShakeBase), 34273650U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h__Script_LegoAbility_3446492328(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
