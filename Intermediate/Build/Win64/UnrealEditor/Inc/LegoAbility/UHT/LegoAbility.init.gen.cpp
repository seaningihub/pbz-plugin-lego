// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLegoAbility_init() {}
	LEGOABILITY_API UFunction* Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LegoAbility;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LegoAbility()
	{
		if (!Z_Registration_Info_UPackage__Script_LegoAbility.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_LegoAbility_TimelineWaitSimpleDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/LegoAbility",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xAAEA68AC,
				0xE3031418,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LegoAbility.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_LegoAbility.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LegoAbility(Z_Construct_UPackage__Script_LegoAbility, TEXT("/Script/LegoAbility"), Z_Registration_Info_UPackage__Script_LegoAbility, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xAAEA68AC, 0xE3031418));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
