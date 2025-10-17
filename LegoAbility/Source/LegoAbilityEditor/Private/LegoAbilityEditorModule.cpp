// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorModule.h"
#include "AssetTypeActions_LegoAbilityBlueprint.h"
#include "IContentBrowserSingleton.h"
#include "ISettingsModule.h"
#include "LegoAbility.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorSettings.h"
#include "LegoAbilityEditorStyle.h"
#include "LegoAbilityThumbnailRenderer.h"
#include "LGATimeline.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "ToolMenus.h"
#include "Actions/LGAAction.h"
#include "Animation/AnimSequenceBase.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Compiler/LegoAbilityBlueprintCompiler.h"
#include "ContentBrowserModule.h"
#include "Editor/EditorEngine.h"
#include "Framework/Commands/UIAction.h"
#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

extern UNREALED_API UEditorEngine* GEditor;

class FLegoAbilityEditorModule : public ILegoAbilityEditorModule
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static void Menu_ClearInvalidTimelines();

private:
	void RegisterAssetTypeActions();
	void RegisterSettings();
	void UnregisterSettings();

	void RegisterMenus();

	void SetupContentBrowserContextMenuExtender();
	void RemoveContentBrowserContextMenuExtender();
	TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);
	void DeleteNotifiesFromMontages(TArray<FAssetData> AnimNotifies);
	void DeleteActionsFromAbilities(TArray<FAssetData> AbilityActions);

	static TSharedPtr<FKismetCompilerContext> GetCompilerForLegoAbilityBP(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions);

	FDelegateHandle ContentBrowserAssetExtenderDelegateHandle;
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
	FLegoAbilityBlueprintCompiler LegoAbilityBlueprintCompiler;
};

void FLegoAbilityEditorModule::StartupModule()
{
	FLegoAbilityEditorStyle::Initialize();

	// Register Lego ability blueprint compiler we do this no matter what.
	IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
	KismetCompilerModule.GetCompilers().Add(&LegoAbilityBlueprintCompiler);

	// Register menus
	UToolMenus::Get()->RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FLegoAbilityEditorModule::RegisterMenus));

	// Register asset types
	RegisterAssetTypeActions();

	// This is needed for actually pressing compile on the BP.
	FKismetCompilerContext::RegisterCompilerForBP(ULegoAbilityBlueprint::StaticClass(), &FLegoAbilityEditorModule::GetCompilerForLegoAbilityBP);

	// Register settings objects
	RegisterSettings();

	// Add asset view context menu extenders to content browser
	SetupContentBrowserContextMenuExtender();

	// Registers a custom thumbnail renderer for Lego ability blueprint
	UThumbnailManager::Get().RegisterCustomRenderer(ULegoAbilityBlueprint::StaticClass(), ULegoAbilityThumbnailRenderer::StaticClass());

	FLegoAbilityEditorCommands::Register();
	FLegoAbilityEditorTimelineCommands::Register();
}

void FLegoAbilityEditorModule::ShutdownModule()
{
	FLegoAbilityEditorStyle::Shutdown();

	IKismetCompilerInterface& KismetCompilerModule = FModuleManager::GetModuleChecked<IKismetCompilerInterface>("KismetCompiler");
	KismetCompilerModule.GetCompilers().Remove(&LegoAbilityBlueprintCompiler);

	// remove menu extension
	UToolMenus::UnregisterOwner(this);

	// Unregister all the asset type actions that we registered
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (TSharedPtr<IAssetTypeActions>& AssetTypeAction : CreatedAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(AssetTypeAction.ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();

	// Unregister settings objects
	UnregisterSettings();

	// Remove asset view context menu extenders from content browser
	RemoveContentBrowserContextMenuExtender();

	if (UObjectInitialized())
	{
		// Unregisters the custom thumbnail renderer for Lego ability blueprint
		UThumbnailManager::Get().UnregisterCustomRenderer(ULegoAbilityBlueprint::StaticClass());
	}
}

void FLegoAbilityEditorModule::Menu_ClearInvalidTimelines()
{
	const IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();

	TArray<FAssetData> OutlegoAbilityAssets;
	AssetRegistry.GetAssetsByClass(ULegoAbilityBlueprint::StaticClass()->GetClassPathName(), OutlegoAbilityAssets, true);

	for (const FAssetData& Asset : OutlegoAbilityAssets)
	{
		if (ULegoAbilityBlueprint* LegoBlueprint = Cast<ULegoAbilityBlueprint>(Asset.GetAsset()))
		{
			LegoBlueprint->ClearInvalidTimelines();
		}
	}
}

void FLegoAbilityEditorModule::RegisterAssetTypeActions()
{
	// Register asset type actions
	TSharedRef<IAssetTypeActions> AssetTypeAction = MakeShareable(new FAssetTypeActions_LegoAbilityBlueprint());
	FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(AssetTypeAction);
	CreatedAssetTypeActions.Add(AssetTypeAction);
}

void FLegoAbilityEditorModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Editor", "Plugins", "LegoAbilityEditor",
			LOCTEXT("AbilityEditorSettingsName", "LegoAbility"),
			LOCTEXT("AbilityEditorSettingsDescription", "Configure the Lego ability editor"),
			GetMutableDefault<ULegoAbilityEditorSettings>());
	}
}

void FLegoAbilityEditorModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Editor", "Plugins", "LegoAbilityEditor");
	}
}

void FLegoAbilityEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);
	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
		FToolMenuSection& Section = Menu->AddSection("LegoAbility", LOCTEXT("Lego Ability", "Lego Ability"));
		Section.AddEntry(
			FToolMenuEntry::InitMenuEntry(
			"ClearInvalidTimelines",
			LOCTEXT("ClearInvalidTimelinesEntry", "Clear Invalid Timelines"),
			LOCTEXT("ClearInvalidTimelinesToolTip", "Clear Invalid Timelines."),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "DeveloperTools.MenuIcon"),
			FUIAction(FExecuteAction::CreateStatic(&FLegoAbilityEditorModule::Menu_ClearInvalidTimelines))
		));
	}
}

void FLegoAbilityEditorModule::SetupContentBrowserContextMenuExtender()
{
	// Register Content Browser menu extender
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FContentBrowserMenuExtender_SelectedAssets>& AssetViewContextMenuExtenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
	AssetViewContextMenuExtenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FLegoAbilityEditorModule::OnExtendContentBrowserAssetSelectionMenu));
	ContentBrowserAssetExtenderDelegateHandle = AssetViewContextMenuExtenders.Last().GetHandle();
}

void FLegoAbilityEditorModule::RemoveContentBrowserContextMenuExtender()
{
	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
		TArray<FContentBrowserMenuExtender_SelectedAssets>& AssetViewContextMenuExtenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
		AssetViewContextMenuExtenders.RemoveAll([this](const FContentBrowserMenuExtender_SelectedAssets& Delegate) { return Delegate.GetHandle() == ContentBrowserAssetExtenderDelegateHandle; });
	}
}

TSharedRef<FExtender> FLegoAbilityEditorModule::OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TArray<FAssetData> AnimNotifies, AbilityActions;
	for (const FAssetData& Asset : SelectedAssets)
	{
		UObject* AssetObj  = Asset.GetAsset();
		
		if (UClass* AssetClass = Cast<UClass>(AssetObj))
		{
			if (AssetClass->IsChildOf(ULGAAction::StaticClass()))
			{
				AbilityActions.Add(Asset);
			}
		}
		
		if (UBlueprint * Blueprint = Cast<UBlueprint>(AssetObj))
		{
			if (!Blueprint->GeneratedClass)
			{
				break;
			}

			if (Blueprint->GeneratedClass->IsChildOf<UAnimNotify>() || Blueprint->GeneratedClass->IsChildOf<UAnimNotifyState>())
			{
				AnimNotifies.Add(Asset);
			}
			else if (Blueprint->GeneratedClass->IsChildOf<ULGAAction>())
			{
				AbilityActions.Add(Asset);
			}
			else
			{
				break;
			}
		}
	}

	TSharedRef<FExtender> Extender(new FExtender());
	if (AnimNotifies.Num() == SelectedAssets.Num())
	{
		Extender->AddMenuExtension("GetAssetActions", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateLambda([this, AnimNotifies](FMenuBuilder& MenuBuilder)
		{
			MenuBuilder.AddMenuEntry(
				LOCTEXT("LegoAbility_DeleteNotifiesFromMontages", "Delete Notifies From Referenced Montages"),
				LOCTEXT("LegoAbility_DeleteNotifiesFromMontagesTooltip", "Delete Notifies From Referenced Montages"),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateRaw(this, &FLegoAbilityEditorModule::DeleteNotifiesFromMontages, AnimNotifies), FCanExecuteAction()));
		}));
	}
	else if (AbilityActions.Num() == SelectedAssets.Num())
	{
		Extender->AddMenuExtension("GetAssetActions", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateLambda([this, AbilityActions](FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.AddMenuEntry(
					LOCTEXT("LegoAbility_DeleteActionsFromAbilities", "Delete Actions From Referenced Abilities"),
					LOCTEXT("LegoAbility_DeleteActionsFromAbilitiesTooltip", "Delete Actions From Referenced Abilities"),
					FSlateIcon(),
					FUIAction(FExecuteAction::CreateRaw(this, &FLegoAbilityEditorModule::DeleteActionsFromAbilities, AbilityActions), FCanExecuteAction()));
			}));
	}

	return Extender;
}

void FLegoAbilityEditorModule::DeleteNotifiesFromMontages(TArray<FAssetData> AnimNotifies)
{
	UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry")).Get();
	for (const FAssetData& AssetData : AnimNotifies)
	{
		UBlueprint* Blueprint = Cast<UBlueprint>(AssetData.GetAsset());

		TArray<FName> Referencers;
		AssetRegistry.GetReferencers(AssetData.PackageName, Referencers);

		for (FName& PackageName : Referencers)
		{
			if (UPackage* Package = LoadPackage(nullptr, *PackageName.ToString(), LOAD_EditorOnly))
			{
				if (UAnimSequenceBase* AnimSequence = Cast<UAnimSequenceBase>(Package->FindAssetInPackage()))
				{
					// close all active editors for the asset to avoid crash
					AssetEditorSubsystem->CloseAllEditorsForAsset(AnimSequence);

					for (int32 i = AnimSequence->Notifies.Num() - 1; i >= 0; i--)
					{
						FAnimNotifyEvent& Event = AnimSequence->Notifies[i];
						UObject* AnimNotify = Event.Notify;
						AnimNotify = AnimNotify ? AnimNotify : Event.NotifyStateClass;
						if (AnimNotify)
						{
							if (AnimNotify->IsA(Blueprint->GeneratedClass))
							{
								AnimSequence->Notifies.RemoveAt(i);
							}
						}
						else
						{
							AnimSequence->Notifies.RemoveAt(i);
						}
					}

					AnimSequence->RefreshCacheData();
					AnimSequence->MarkPackageDirty();
				}
			}
		}
	}
}

void FLegoAbilityEditorModule::DeleteActionsFromAbilities(TArray<FAssetData> AbilityActions)
{
	UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry")).Get();
	for (const FAssetData& AssetData : AbilityActions)
	{
		TArray<FName> Referencers;

		UClass* ActionClass = nullptr;
		if (UBlueprint* Blueprint = Cast<UBlueprint>(AssetData.GetAsset()))
		{
			ActionClass = Blueprint->GeneratedClass;

			AssetRegistry.GetReferencers(AssetData.PackageName, Referencers);
		}
		if (UClass* AssetClass = Cast<UClass>(AssetData.GetAsset()))
		{
			if (AssetClass->IsChildOf(ULGAAction::StaticClass()))
			{
				ActionClass = AssetClass;

				TArray<FAssetData> OutAssetData;
				AssetRegistry.GetAssetsByClass(FTopLevelAssetPath(ULegoAbilityBlueprint::StaticClass()), OutAssetData);

				for (FAssetData& AD : OutAssetData)
				{
					Referencers.Add(AD.PackageName);
				}
			}
		}

		if (!ActionClass)
		{
			continue;
		}

		for (FName& PackageName : Referencers)
		{
			if (UPackage* Package = LoadPackage(nullptr, *PackageName.ToString(), LOAD_EditorOnly))
			{
				if (ULegoAbilityBlueprint* AbilityBlueprint = Cast<ULegoAbilityBlueprint>(Package->FindAssetInPackage()))
				{
					// close all active editors for the asset to avoid crash
					AssetEditorSubsystem->CloseAllEditorsForAsset(AbilityBlueprint);

					bool bChanged = false;

					for (ULGATimeline* Timeline : AbilityBlueprint->AbilityTimelines)
					{
						for (int32 i = Timeline->Actions.Num() - 1; i >= 0; i--)
						{
							if (ULGAAction* Action = Timeline->Actions[i].Action; Action && Action->IsA(ActionClass))
							{
								bChanged = true;

								Timeline->Actions.RemoveAt(i);
								Timeline->RefreshCacheData();
							}
						}
					}

					for (FLGATimelineOverride& TimelineOverride : AbilityBlueprint->AbilityTimelineOverrides)
					{
						if (TimelineOverride.Timeline)
						{
							for (int32 i = TimelineOverride.Timeline->Actions.Num() - 1; i >= 0; i--)
							{
								if (ULGAAction* Action = TimelineOverride.Timeline->Actions[i].Action; Action && Action->IsA(ActionClass))
								{
									bChanged = true;

									TimelineOverride.Timeline->Actions.RemoveAt(i);
									TimelineOverride.Timeline->RefreshCacheData();
								}
							}
						}

						for (auto It = TimelineOverride.ActionOverrides.CreateIterator(); It; ++It)
						{
							if (It->Value && It->Value->IsA(ActionClass))
							{
								It.RemoveCurrent();
								bChanged = true;
							}
						}
					}

					if (bChanged)
					{
						AbilityBlueprint->MarkPackageDirty();
						AbilityBlueprint->UpdateTimelineTemplate();
					}
				}
			}
		}
	}
}

TSharedPtr<FKismetCompilerContext> FLegoAbilityEditorModule::GetCompilerForLegoAbilityBP(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions)
{
	return TSharedPtr<FKismetCompilerContext>(new FLegoAbilityBlueprintCompilerContext(BP, InMessageLog, InCompileOptions));
}

IMPLEMENT_MODULE(FLegoAbilityEditorModule, LegoAbilityEditor)

#undef LOCTEXT_NAMESPACE