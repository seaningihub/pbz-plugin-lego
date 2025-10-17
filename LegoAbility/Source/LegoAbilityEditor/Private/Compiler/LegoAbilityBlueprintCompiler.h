// Copyright Recursoft LLC 2019-2021. All Rights Reserved.

#pragma once

#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompilerModule.h"
#include "KismetCompiler.h"

class ULGATimeline;

class FLegoAbilityBlueprintCompiler : public IBlueprintCompiler
{
public:
	/** IBlueprintCompiler interface */
	virtual bool CanCompile(const UBlueprint* Blueprint) override;
	virtual void Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions, FCompilerResultsLog& Results) override;
	virtual bool GetBlueprintTypesForClass(UClass* ParentClass, UClass*& OutBlueprintClass, UClass*& OutBlueprintGeneratedClass) const override;
	/** ~IBlueprintCompiler interface */
};

class FLegoAbilityBlueprintCompilerContext : public FKismetCompilerContext
{
public:
	FLegoAbilityBlueprintCompilerContext(UBlueprint* InBlueprint, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions);
	virtual void CreateClassVariablesFromBlueprint() override;

protected:
	// FKismetCompilerContext interface
	virtual void SpawnNewClass(const FString& NewClassName) override;
	virtual void OnNewClassSet(UBlueprintGeneratedClass* ClassToUse) override;
	virtual void CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& InOutOldCDO) override;
	virtual void SaveSubObjectsFromCleanAndSanitizeClass(FSubobjectCollection& SubObjectsToSave, UBlueprintGeneratedClass* ClassToClean) override;
	virtual void FinishCompilingClass(UClass* Class) override;
	virtual bool ValidateGeneratedClass(UBlueprintGeneratedClass* Class) override;
	virtual void OnPostCDOCompiled(const UObject::FPostCDOCompiledContext& Context) override;
	// ~FKismetCompilerContext interface

	class ULegoAbilityBlueprintGeneratedClass* NewLegoAbilityBlueprintClass;
};