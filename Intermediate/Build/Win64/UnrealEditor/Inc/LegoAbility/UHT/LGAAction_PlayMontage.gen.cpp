// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction_PlayMontage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction_PlayMontage() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULGAAction_PlayMontage Function OnAbilityEnded ***************************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics
{
	struct LGAAction_PlayMontage_eventOnAbilityEnded_Parms
	{
		UGameplayAbility* Ability;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ability;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::NewProp_Ability = { "Ability", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_eventOnAbilityEnded_Parms, Ability), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::NewProp_Ability,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage, nullptr, "OnAbilityEnded", Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::LGAAction_PlayMontage_eventOnAbilityEnded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::LGAAction_PlayMontage_eventOnAbilityEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage::execOnAbilityEnded)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_Ability);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAbilityEnded(Z_Param_Ability);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage Function OnAbilityEnded *****************************

// ********** Begin Class ULGAAction_PlayMontage Function OnMontageBlendOut ************************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics
{
	struct LGAAction_PlayMontage_eventOnMontageBlendOut_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_eventOnMontageBlendOut_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((LGAAction_PlayMontage_eventOnMontageBlendOut_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_PlayMontage_eventOnMontageBlendOut_Parms), &Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage, nullptr, "OnMontageBlendOut", Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::LGAAction_PlayMontage_eventOnMontageBlendOut_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::LGAAction_PlayMontage_eventOnMontageBlendOut_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage::execOnMontageBlendOut)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMontageBlendOut(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage Function OnMontageBlendOut **************************

// ********** Begin Class ULGAAction_PlayMontage Function OnMontageCompleted ***********************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics
{
	struct LGAAction_PlayMontage_eventOnMontageCompleted_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_eventOnMontageCompleted_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((LGAAction_PlayMontage_eventOnMontageCompleted_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_PlayMontage_eventOnMontageCompleted_Parms), &Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage, nullptr, "OnMontageCompleted", Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::LGAAction_PlayMontage_eventOnMontageCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::LGAAction_PlayMontage_eventOnMontageCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage::execOnMontageCompleted)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMontageCompleted(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage Function OnMontageCompleted *************************

// ********** Begin Class ULGAAction_PlayMontage ***************************************************
void ULGAAction_PlayMontage::StaticRegisterNativesULGAAction_PlayMontage()
{
	UClass* Class = ULGAAction_PlayMontage::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnAbilityEnded", &ULGAAction_PlayMontage::execOnAbilityEnded },
		{ "OnMontageBlendOut", &ULGAAction_PlayMontage::execOnMontageBlendOut },
		{ "OnMontageCompleted", &ULGAAction_PlayMontage::execOnMontageCompleted },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction_PlayMontage;
UClass* ULGAAction_PlayMontage::GetPrivateStaticClass()
{
	using TClass = ULGAAction_PlayMontage;
	if (!Z_Registration_Info_UClass_ULGAAction_PlayMontage.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction_PlayMontage"),
			Z_Registration_Info_UClass_ULGAAction_PlayMontage.InnerSingleton,
			StaticRegisterNativesULGAAction_PlayMontage,
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
	return Z_Registration_Info_UClass_ULGAAction_PlayMontage.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_PlayMontage_NoRegister()
{
	return ULGAAction_PlayMontage::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_PlayMontage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Ability Action to simply play a montage.\n */" },
		{ "DisplayName", "Play Montage" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction_PlayMontage.h" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
		{ "ToolTip", "Ability Action to simply play a montage." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TaskInstanceName_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MontageToPlay_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartSection_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopWhenAbilityEnds_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopWhenActionEnds_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimRootMotionTranslationScale_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClampSpeedWhenCanceled_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForceClampSpeed_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableSliding_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBlendOutAction_MetaData[] = {
		{ "Category", "Trigger Actions" },
		{ "Comment", "// Actions On Event\n" },
		{ "DisplayName", "On Blend Out" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
		{ "ToolTip", "Actions On Event" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompletedAction_MetaData[] = {
		{ "Category", "Trigger Actions" },
		{ "DisplayName", "On Complete" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebug_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugRootMotion_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TaskInstanceName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MontageToPlay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StartSection;
	static void NewProp_bStopWhenAbilityEnds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopWhenAbilityEnds;
	static void NewProp_bStopWhenActionEnds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopWhenActionEnds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AnimRootMotionTranslationScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClampSpeedWhenCanceled;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ForceClampSpeed;
	static void NewProp_bDisableSliding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableSliding;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OnBlendOutAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OnCompletedAction;
	static void NewProp_bDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebug;
	static void NewProp_bDebugRootMotion_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugRootMotion;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_OnAbilityEnded, "OnAbilityEnded" }, // 814721753
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageBlendOut, "OnMontageBlendOut" }, // 77628502
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_OnMontageCompleted, "OnMontageCompleted" }, // 3474440403
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction_PlayMontage>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_TaskInstanceName = { "TaskInstanceName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, TaskInstanceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TaskInstanceName_MetaData), NewProp_TaskInstanceName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_MontageToPlay = { "MontageToPlay", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, MontageToPlay), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MontageToPlay_MetaData), NewProp_MontageToPlay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_StartSection = { "StartSection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, StartSection), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartSection_MetaData), NewProp_StartSection_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenAbilityEnds_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage*)Obj)->bStopWhenAbilityEnds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenAbilityEnds = { "bStopWhenAbilityEnds", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage), &Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenAbilityEnds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopWhenAbilityEnds_MetaData), NewProp_bStopWhenAbilityEnds_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenActionEnds_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage*)Obj)->bStopWhenActionEnds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenActionEnds = { "bStopWhenActionEnds", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage), &Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenActionEnds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopWhenActionEnds_MetaData), NewProp_bStopWhenActionEnds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_AnimRootMotionTranslationScale = { "AnimRootMotionTranslationScale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, AnimRootMotionTranslationScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimRootMotionTranslationScale_MetaData), NewProp_AnimRootMotionTranslationScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_ClampSpeedWhenCanceled = { "ClampSpeedWhenCanceled", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, ClampSpeedWhenCanceled), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClampSpeedWhenCanceled_MetaData), NewProp_ClampSpeedWhenCanceled_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_ForceClampSpeed = { "ForceClampSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, ForceClampSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForceClampSpeed_MetaData), NewProp_ForceClampSpeed_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDisableSliding_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage*)Obj)->bDisableSliding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDisableSliding = { "bDisableSliding", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage), &Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDisableSliding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableSliding_MetaData), NewProp_bDisableSliding_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_OnBlendOutAction = { "OnBlendOutAction", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, OnBlendOutAction), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBlendOutAction_MetaData), NewProp_OnBlendOutAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_OnCompletedAction = { "OnCompletedAction", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage, OnCompletedAction), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompletedAction_MetaData), NewProp_OnCompletedAction_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebug_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage*)Obj)->bDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage), &Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebug_MetaData), NewProp_bDebug_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebugRootMotion_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage*)Obj)->bDebugRootMotion = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebugRootMotion = { "bDebugRootMotion", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage), &Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebugRootMotion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugRootMotion_MetaData), NewProp_bDebugRootMotion_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULGAAction_PlayMontage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_TaskInstanceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_MontageToPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_StartSection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenAbilityEnds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bStopWhenActionEnds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_AnimRootMotionTranslationScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_ClampSpeedWhenCanceled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_ForceClampSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDisableSliding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_OnBlendOutAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_OnCompletedAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Statics::NewProp_bDebugRootMotion,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULGAAction_PlayMontage_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULGAAction,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_PlayMontage_Statics::ClassParams = {
	&ULGAAction_PlayMontage::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULGAAction_PlayMontage_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Statics::PropPointers),
	0,
	0x009020A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_PlayMontage_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction_PlayMontage()
{
	if (!Z_Registration_Info_UClass_ULGAAction_PlayMontage.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction_PlayMontage.OuterSingleton, Z_Construct_UClass_ULGAAction_PlayMontage_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction_PlayMontage.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction_PlayMontage);
ULGAAction_PlayMontage::~ULGAAction_PlayMontage() {}
// ********** End Class ULGAAction_PlayMontage *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction_PlayMontage, ULGAAction_PlayMontage::StaticClass, TEXT("ULGAAction_PlayMontage"), &Z_Registration_Info_UClass_ULGAAction_PlayMontage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction_PlayMontage), 3360706483U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h__Script_LegoAbility_2308349196(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
