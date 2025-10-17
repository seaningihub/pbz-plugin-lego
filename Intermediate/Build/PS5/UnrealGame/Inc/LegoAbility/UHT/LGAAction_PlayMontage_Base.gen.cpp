// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction_PlayMontage_Base.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction_PlayMontage_Base() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimSequenceBase_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_Executable_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULGAAction_PlayMontage_Base Function GetAnimInstance *********************
struct LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms
{
	AActor* PreviewActor;
	UAnimInstance* ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_ULGAAction_PlayMontage_Base_GetAnimInstance = FName(TEXT("GetAnimInstance"));
UAnimInstance* ULGAAction_PlayMontage_Base::GetAnimInstance(AActor* PreviewActor)
{
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_PlayMontage_Base_GetAnimInstance);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms Parms;
		Parms.PreviewActor=PreviewActor;
	ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return GetAnimInstance_Implementation(PreviewActor);
	}
}
struct Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms, ReturnValue), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage_Base, nullptr, "GetAnimInstance", Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::PropPointers), sizeof(LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_PlayMontage_Base_eventGetAnimInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage_Base::execGetAnimInstance)
{
	P_GET_OBJECT(AActor,Z_Param_PreviewActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAnimInstance**)Z_Param__Result=P_THIS->GetAnimInstance_Implementation(Z_Param_PreviewActor);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage_Base Function GetAnimInstance ***********************

// ********** Begin Class ULGAAction_PlayMontage_Base Function OnAbilityEnded **********************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics
{
	struct LGAAction_PlayMontage_Base_eventOnAbilityEnded_Parms
	{
		UGameplayAbility* Ability;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ability;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::NewProp_Ability = { "Ability", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_Base_eventOnAbilityEnded_Parms, Ability), Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::NewProp_Ability,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage_Base, nullptr, "OnAbilityEnded", Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::LGAAction_PlayMontage_Base_eventOnAbilityEnded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::LGAAction_PlayMontage_Base_eventOnAbilityEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage_Base::execOnAbilityEnded)
{
	P_GET_OBJECT(UGameplayAbility,Z_Param_Ability);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAbilityEnded(Z_Param_Ability);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage_Base Function OnAbilityEnded ************************

// ********** Begin Class ULGAAction_PlayMontage_Base Function OnMontageBlendOut *******************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics
{
	struct LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms), &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage_Base, nullptr, "OnMontageBlendOut", Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::LGAAction_PlayMontage_Base_eventOnMontageBlendOut_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage_Base::execOnMontageBlendOut)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMontageBlendOut(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage_Base Function OnMontageBlendOut *********************

// ********** Begin Class ULGAAction_PlayMontage_Base Function OnMontageCompleted ******************
struct Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics
{
	struct LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms), &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction_PlayMontage_Base, nullptr, "OnMontageCompleted", Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::LGAAction_PlayMontage_Base_eventOnMontageCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction_PlayMontage_Base::execOnMontageCompleted)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMontageCompleted(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// ********** End Class ULGAAction_PlayMontage_Base Function OnMontageCompleted ********************

// ********** Begin Class ULGAAction_PlayMontage_Base **********************************************
void ULGAAction_PlayMontage_Base::StaticRegisterNativesULGAAction_PlayMontage_Base()
{
	UClass* Class = ULGAAction_PlayMontage_Base::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAnimInstance", &ULGAAction_PlayMontage_Base::execGetAnimInstance },
		{ "OnAbilityEnded", &ULGAAction_PlayMontage_Base::execOnAbilityEnded },
		{ "OnMontageBlendOut", &ULGAAction_PlayMontage_Base::execOnMontageBlendOut },
		{ "OnMontageCompleted", &ULGAAction_PlayMontage_Base::execOnMontageCompleted },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base;
UClass* ULGAAction_PlayMontage_Base::GetPrivateStaticClass()
{
	using TClass = ULGAAction_PlayMontage_Base;
	if (!Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction_PlayMontage_Base"),
			Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.InnerSingleton,
			StaticRegisterNativesULGAAction_PlayMontage_Base,
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
	return Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base_NoRegister()
{
	return ULGAAction_PlayMontage_Base::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Ability Action to simply play a montage.\n */" },
		{ "DisplayName", "Play Montage Base" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction_PlayMontage_Base.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
		{ "ToolTip", "Ability Action to simply play a montage." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TaskInstanceName_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Animation_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartSection_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopWhenAbilityEnds_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopWhenActionEnds_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBlendOutAction_MetaData[] = {
		{ "Category", "Trigger Actions" },
		{ "Comment", "// Actions On Event\n" },
		{ "DisplayName", "On Blend Out" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
		{ "ToolTip", "Actions On Event" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompletedAction_MetaData[] = {
		{ "Category", "Trigger Actions" },
		{ "DisplayName", "On Complete" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebug_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMontage_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/LGAAction_PlayMontage_Base.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TaskInstanceName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Animation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StartSection;
	static void NewProp_bStopWhenAbilityEnds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopWhenAbilityEnds;
	static void NewProp_bStopWhenActionEnds_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopWhenActionEnds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OnBlendOutAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OnCompletedAction;
	static void NewProp_bDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebug;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_GetAnimInstance, "GetAnimInstance" }, // 1131833190
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnAbilityEnded, "OnAbilityEnded" }, // 3923693679
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageBlendOut, "OnMontageBlendOut" }, // 144536555
		{ &Z_Construct_UFunction_ULGAAction_PlayMontage_Base_OnMontageCompleted, "OnMontageCompleted" }, // 805833684
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction_PlayMontage_Base>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_TaskInstanceName = { "TaskInstanceName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, TaskInstanceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TaskInstanceName_MetaData), NewProp_TaskInstanceName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_Animation = { "Animation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, Animation), Z_Construct_UClass_UAnimSequenceBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Animation_MetaData), NewProp_Animation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_StartSection = { "StartSection", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, StartSection), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartSection_MetaData), NewProp_StartSection_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenAbilityEnds_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage_Base*)Obj)->bStopWhenAbilityEnds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenAbilityEnds = { "bStopWhenAbilityEnds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage_Base), &Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenAbilityEnds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopWhenAbilityEnds_MetaData), NewProp_bStopWhenAbilityEnds_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenActionEnds_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage_Base*)Obj)->bStopWhenActionEnds = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenActionEnds = { "bStopWhenActionEnds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage_Base), &Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenActionEnds_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopWhenActionEnds_MetaData), NewProp_bStopWhenActionEnds_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_OnBlendOutAction = { "OnBlendOutAction", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, OnBlendOutAction), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBlendOutAction_MetaData), NewProp_OnBlendOutAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_OnCompletedAction = { "OnCompletedAction", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, OnCompletedAction), Z_Construct_UClass_ULGAAction_Executable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompletedAction_MetaData), NewProp_OnCompletedAction_MetaData) };
void Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bDebug_SetBit(void* Obj)
{
	((ULGAAction_PlayMontage_Base*)Obj)->bDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction_PlayMontage_Base), &Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebug_MetaData), NewProp_bDebug_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_DynamicMontage = { "DynamicMontage", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction_PlayMontage_Base, DynamicMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMontage_MetaData), NewProp_DynamicMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_TaskInstanceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_Animation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_StartSection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenAbilityEnds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bStopWhenActionEnds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_OnBlendOutAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_OnCompletedAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_bDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::NewProp_DynamicMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULGAAction,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::ClassParams = {
	&ULGAAction_PlayMontage_Base::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::PropPointers),
	0,
	0x009020A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base()
{
	if (!Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.OuterSingleton, Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction_PlayMontage_Base);
ULGAAction_PlayMontage_Base::~ULGAAction_PlayMontage_Base() {}
// ********** End Class ULGAAction_PlayMontage_Base ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction_PlayMontage_Base, ULGAAction_PlayMontage_Base::StaticClass, TEXT("ULGAAction_PlayMontage_Base"), &Z_Registration_Info_UClass_ULGAAction_PlayMontage_Base, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction_PlayMontage_Base), 583762677U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h__Script_LegoAbility_426016179(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
