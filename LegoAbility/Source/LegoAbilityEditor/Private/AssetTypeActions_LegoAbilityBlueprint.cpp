// Copyright S-Game, Inc. All Rights Reserved.

#include "AssetTypeActions_LegoAbilityBlueprint.h"
#include "Misc/MessageDialog.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityBlueprintFactory.h"
#include "ThumbnailRendering/SceneThumbnailInfo.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FText FAssetTypeActions_LegoAbilityBlueprint::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_LegoAbilityBlueprint", "Lego Ability Blueprint");
}

FColor FAssetTypeActions_LegoAbilityBlueprint::GetTypeColor() const
{
	return FColor::Emerald;
}

void FAssetTypeActions_LegoAbilityBlueprint::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Object : InObjects)
	{
		if (UBlueprint* Blueprint = Cast<UBlueprint>(Object))
		{
			bool bLetOpen = true;
			if (!Blueprint->ParentClass)
			{
				bLetOpen = EAppReturnType::Yes == FMessageDialog::Open(
					EAppMsgType::YesNo,
					LOCTEXT("FailedToLoadAbilityBlueprintWithContinue",
						"Lego Ability Blueprint could not be loaded because it derives from an invalid class. Check to make sure the parent class for this blueprint hasn't been removed! Do you want to continue (it can crash the editor)?"
					));
			}

			if (bLetOpen)
			{
				TArray<UBlueprint*> Blueprints = { Blueprint };
				TSharedRef<FLegoAbilityEditor> Editor(new FLegoAbilityEditor());
				Editor->InitLegoAbilityEditor(Mode, EditWithinLevelEditor, Blueprints);
			}
		}
	}
}

UClass* FAssetTypeActions_LegoAbilityBlueprint::GetSupportedClass() const
{
	return ULegoAbilityBlueprint::StaticClass();
}

UFactory* FAssetTypeActions_LegoAbilityBlueprint::GetFactoryForBlueprintType(UBlueprint* InBlueprint) const
{
	ULegoAbilityBlueprintFactory* LegoAbilityBlueprintFactory = NewObject<ULegoAbilityBlueprintFactory>();
	LegoAbilityBlueprintFactory->ParentClass = TSubclassOf<ULegoAbility>(*InBlueprint->GeneratedClass);
	return LegoAbilityBlueprintFactory;
}

#undef LOCTEXT_NAMESPACE