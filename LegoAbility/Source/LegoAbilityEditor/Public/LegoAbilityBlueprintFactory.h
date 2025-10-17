// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LegoAbility.h"
#include "Engine/Blueprint.h"
#include "Factories/Factory.h"
#include "LegoAbilityBlueprintFactory.generated.h"

/* Factory for Ability Blueprints. */
UCLASS(HideCategories = Object, MinimalAPI)
class ULegoAbilityBlueprintFactory : public UFactory
{
	GENERATED_BODY()
public:
	ULegoAbilityBlueprintFactory(const FObjectInitializer& ObjectInitializer);
	virtual ~ULegoAbilityBlueprintFactory();

	// The type of blueprint that will be created
	UPROPERTY(EditAnywhere, Category = LegoAbilityBlueprintFactory)
	TEnumAsByte<EBlueprintType> BlueprintType;

	// The parent class of the created blueprint
	UPROPERTY(EditAnywhere, Category = LegoAbilityBlueprintFactory)
	TSubclassOf<ULegoAbility> ParentClass;

	//~ Begin UFactory Interface
	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	//~ End UFactory Interface	
};
