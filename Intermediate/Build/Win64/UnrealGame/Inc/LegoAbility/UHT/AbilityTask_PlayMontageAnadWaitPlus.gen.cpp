// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tasks/AbilityTask_PlayMontageAnadWaitPlus.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAbilityTask_PlayMontageAnadWaitPlus() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilityTask_PlayMontageAndWait();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus();
LEGOABILITY_API UClass* Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAbilityTask_PlayMontageAnadWaitPlus Function CreatePlayMontageAndWaitPlusProxy 
struct Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics
{
	struct AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms
	{
		UGameplayAbility* OwningAbility;
		FName TaskInstanceName;
		UAnimMontage* Montage;
		float PlayRate;
		FName StartSect;
		bool StopWhenAbilityEnds;
		float RootMotionTranslationScale;
		float StartTime;
		bool AllowInterruptAfterBlendOut;
		bool DisableSliding;
		UAbilityTask_PlayMontageAnadWaitPlus* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "TRUE" },
		{ "Category", "Ability|Tasks" },
		{ "CPP_Default_AllowInterruptAfterBlendOut", "false" },
		{ "CPP_Default_DisableSliding", "true" },
		{ "CPP_Default_PlayRate", "1.000000" },
		{ "CPP_Default_RootMotionTranslationScale", "1.000000" },
		{ "CPP_Default_StartSect", "None" },
		{ "CPP_Default_StartTime", "0.000000" },
		{ "CPP_Default_StopWhenAbilityEnds", "true" },
		{ "DefaultToSelf", "OwningAbility" },
		{ "DisplayName", "PlayMontageAndWaitPlus" },
		{ "HidePin", "OwningAbility" },
		{ "ModuleRelativePath", "Public/Tasks/AbilityTask_PlayMontageAnadWaitPlus.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningAbility;
	static const UECodeGen_Private::FNamePropertyParams NewProp_TaskInstanceName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StartSect;
	static void NewProp_StopWhenAbilityEnds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_StopWhenAbilityEnds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RootMotionTranslationScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartTime;
	static void NewProp_AllowInterruptAfterBlendOut_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_AllowInterruptAfterBlendOut;
	static void NewProp_DisableSliding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_DisableSliding;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_OwningAbility = { "OwningAbility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, OwningAbility), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_TaskInstanceName = { "TaskInstanceName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, TaskInstanceName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, PlayRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StartSect = { "StartSect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, StartSect), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StopWhenAbilityEnds_SetBit(void* Obj)
{
	((AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms*)Obj)->StopWhenAbilityEnds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StopWhenAbilityEnds = { "StopWhenAbilityEnds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms), &Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StopWhenAbilityEnds_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_RootMotionTranslationScale = { "RootMotionTranslationScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, RootMotionTranslationScale), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, StartTime), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_AllowInterruptAfterBlendOut_SetBit(void* Obj)
{
	((AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms*)Obj)->AllowInterruptAfterBlendOut = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_AllowInterruptAfterBlendOut = { "AllowInterruptAfterBlendOut", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms), &Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_AllowInterruptAfterBlendOut_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_DisableSliding_SetBit(void* Obj)
{
	((AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms*)Obj)->DisableSliding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_DisableSliding = { "DisableSliding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms), &Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_DisableSliding_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms, ReturnValue), Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_OwningAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_TaskInstanceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StartSect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StopWhenAbilityEnds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_RootMotionTranslationScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_AllowInterruptAfterBlendOut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_DisableSliding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus, nullptr, "CreatePlayMontageAndWaitPlusProxy", Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::AbilityTask_PlayMontageAnadWaitPlus_eventCreatePlayMontageAndWaitPlusProxy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAbilityTask_PlayMontageAnadWaitPlus::execCreatePlayMontageAndWaitPlusProxy)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_OwningAbility);
	P_GET_PROPERTY(FNameProperty,Z_Param_TaskInstanceName);
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_PROPERTY(FFloatProperty,Z_Param_PlayRate);
	P_GET_PROPERTY(FNameProperty,Z_Param_StartSect);
	P_GET_UBOOL(Z_Param_StopWhenAbilityEnds);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RootMotionTranslationScale);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartTime);
	P_GET_UBOOL(Z_Param_AllowInterruptAfterBlendOut);
	P_GET_UBOOL(Z_Param_DisableSliding);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAbilityTask_PlayMontageAnadWaitPlus**)Z_Param__Result=UAbilityTask_PlayMontageAnadWaitPlus::CreatePlayMontageAndWaitPlusProxy(Z_Param_OwningAbility,Z_Param_TaskInstanceName,Z_Param_Montage,Z_Param_PlayRate,Z_Param_StartSect,Z_Param_StopWhenAbilityEnds,Z_Param_RootMotionTranslationScale,Z_Param_StartTime,Z_Param_AllowInterruptAfterBlendOut,Z_Param_DisableSliding);
	P_NATIVE_END;
}
// ********** End Class UAbilityTask_PlayMontageAnadWaitPlus Function CreatePlayMontageAndWaitPlusProxy 

// ********** Begin Class UAbilityTask_PlayMontageAnadWaitPlus *************************************
void UAbilityTask_PlayMontageAnadWaitPlus::StaticRegisterNativesUAbilityTask_PlayMontageAnadWaitPlus()
{
	UClass* Class = UAbilityTask_PlayMontageAnadWaitPlus::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreatePlayMontageAndWaitPlusProxy", &UAbilityTask_PlayMontageAnadWaitPlus::execCreatePlayMontageAndWaitPlusProxy },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus;
UClass* UAbilityTask_PlayMontageAnadWaitPlus::GetPrivateStaticClass()
{
	using TClass = UAbilityTask_PlayMontageAnadWaitPlus;
	if (!Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AbilityTask_PlayMontageAnadWaitPlus"),
			Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.InnerSingleton,
			StaticRegisterNativesUAbilityTask_PlayMontageAnadWaitPlus,
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
	return Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.InnerSingleton;
}
UClass* Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_NoRegister()
{
	return UAbilityTask_PlayMontageAnadWaitPlus::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "Tasks/AbilityTask_PlayMontageAnadWaitPlus.h" },
		{ "ModuleRelativePath", "Public/Tasks/AbilityTask_PlayMontageAnadWaitPlus.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisableSliding_MetaData[] = {
		{ "ModuleRelativePath", "Public/Tasks/AbilityTask_PlayMontageAnadWaitPlus.h" },
	};
#endif // WITH_METADATA
	static void NewProp_DisableSliding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_DisableSliding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAbilityTask_PlayMontageAnadWaitPlus_CreatePlayMontageAndWaitPlusProxy, "CreatePlayMontageAndWaitPlusProxy" }, // 3447721263
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAbilityTask_PlayMontageAnadWaitPlus>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::NewProp_DisableSliding_SetBit(void* Obj)
{
	((UAbilityTask_PlayMontageAnadWaitPlus*)Obj)->DisableSliding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::NewProp_DisableSliding = { "DisableSliding", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAbilityTask_PlayMontageAnadWaitPlus), &Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::NewProp_DisableSliding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisableSliding_MetaData), NewProp_DisableSliding_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::NewProp_DisableSliding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilityTask_PlayMontageAndWait,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::ClassParams = {
	&UAbilityTask_PlayMontageAnadWaitPlus::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::Class_MetaDataParams), Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus()
{
	if (!Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.OuterSingleton, Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAbilityTask_PlayMontageAnadWaitPlus);
UAbilityTask_PlayMontageAnadWaitPlus::~UAbilityTask_PlayMontageAnadWaitPlus() {}
// ********** End Class UAbilityTask_PlayMontageAnadWaitPlus ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Tasks_AbilityTask_PlayMontageAnadWaitPlus_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAbilityTask_PlayMontageAnadWaitPlus, UAbilityTask_PlayMontageAnadWaitPlus::StaticClass, TEXT("UAbilityTask_PlayMontageAnadWaitPlus"), &Z_Registration_Info_UClass_UAbilityTask_PlayMontageAnadWaitPlus, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAbilityTask_PlayMontageAnadWaitPlus), 288506083U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Tasks_AbilityTask_PlayMontageAnadWaitPlus_h__Script_LegoAbility_948326700(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Tasks_AbilityTask_PlayMontageAnadWaitPlus_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Tasks_AbilityTask_PlayMontageAnadWaitPlus_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
