// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface/AdvancedAnimPlayerActorInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAdvancedAnimPlayerActorInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
LEGOABILITY_API UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface();
LEGOABILITY_API UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UAdvancedAnimPlayerActorInterface Function SetDisableSliding *********
struct AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms
{
	bool DisableSliding;
};
void IAdvancedAnimPlayerActorInterface::SetDisableSliding(bool DisableSliding)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetDisableSliding instead.");
}
static FName NAME_UAdvancedAnimPlayerActorInterface_SetDisableSliding = FName(TEXT("SetDisableSliding"));
void IAdvancedAnimPlayerActorInterface::Execute_SetDisableSliding(UObject* O, bool DisableSliding)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UAdvancedAnimPlayerActorInterface::StaticClass()));
	AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UAdvancedAnimPlayerActorInterface_SetDisableSliding);
	if (Func)
	{
		Parms.DisableSliding=DisableSliding;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IAdvancedAnimPlayerActorInterface*)(O->GetNativeInterfaceAddress(UAdvancedAnimPlayerActorInterface::StaticClass())))
	{
		I->SetDisableSliding_Implementation(DisableSliding);
	}
}
struct Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Interface/AdvancedAnimPlayerActorInterface.h" },
	};
#endif // WITH_METADATA
	static void NewProp_DisableSliding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_DisableSliding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::NewProp_DisableSliding_SetBit(void* Obj)
{
	((AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms*)Obj)->DisableSliding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::NewProp_DisableSliding = { "DisableSliding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms), &Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::NewProp_DisableSliding_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::NewProp_DisableSliding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAdvancedAnimPlayerActorInterface, nullptr, "SetDisableSliding", Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::PropPointers), sizeof(AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(AdvancedAnimPlayerActorInterface_eventSetDisableSliding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IAdvancedAnimPlayerActorInterface::execSetDisableSliding)
{
	P_GET_UBOOL(Z_Param_DisableSliding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDisableSliding_Implementation(Z_Param_DisableSliding);
	P_NATIVE_END;
}
// ********** End Interface UAdvancedAnimPlayerActorInterface Function SetDisableSliding ***********

// ********** Begin Interface UAdvancedAnimPlayerActorInterface ************************************
void UAdvancedAnimPlayerActorInterface::StaticRegisterNativesUAdvancedAnimPlayerActorInterface()
{
	UClass* Class = UAdvancedAnimPlayerActorInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetDisableSliding", &IAdvancedAnimPlayerActorInterface::execSetDisableSliding },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface;
UClass* UAdvancedAnimPlayerActorInterface::GetPrivateStaticClass()
{
	using TClass = UAdvancedAnimPlayerActorInterface;
	if (!Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AdvancedAnimPlayerActorInterface"),
			Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.InnerSingleton,
			StaticRegisterNativesUAdvancedAnimPlayerActorInterface,
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
	return Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_NoRegister()
{
	return UAdvancedAnimPlayerActorInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interface/AdvancedAnimPlayerActorInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAdvancedAnimPlayerActorInterface_SetDisableSliding, "SetDisableSliding" }, // 1284205077
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IAdvancedAnimPlayerActorInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::ClassParams = {
	&UAdvancedAnimPlayerActorInterface::StaticClass,
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
	0x000040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface()
{
	if (!Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.OuterSingleton, Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface.OuterSingleton;
}
UAdvancedAnimPlayerActorInterface::UAdvancedAnimPlayerActorInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAdvancedAnimPlayerActorInterface);
// ********** End Interface UAdvancedAnimPlayerActorInterface **************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAdvancedAnimPlayerActorInterface, UAdvancedAnimPlayerActorInterface::StaticClass, TEXT("UAdvancedAnimPlayerActorInterface"), &Z_Registration_Info_UClass_UAdvancedAnimPlayerActorInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAdvancedAnimPlayerActorInterface), 2411279907U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h__Script_LegoAbility_4088074105(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
