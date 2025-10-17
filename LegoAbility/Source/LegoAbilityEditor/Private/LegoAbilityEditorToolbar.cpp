// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorToolbar.h"
#include "AssetThumbnail.h"
#include "Engine/AssetManager.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "IDocumentation.h"
#include "Misc/MessageDialog.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorModes.h"
#include "LegoAbilityEditorSettings.h"
#include "LegoAbilityEditorStyle.h"
#include "Textures/SlateIcon.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/SToolTip.h"
#include "WorkflowOrientedApp/SModeWidget.h"
#include "IContentBrowserSingleton.h"
#include "ContentBrowserModule.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"


FLegoAbilityEditorToolbar::FLegoAbilityEditorToolbar(TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
	: AbilityEditor(InAbilityEditor)
{
}

void FLegoAbilityEditorToolbar::AddAbilityEditorModesToolbar(TSharedPtr<FExtender> Extender)
{
	Extender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		AbilityEditor.Pin()->GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateSP(this, &FLegoAbilityEditorToolbar::FillAbilityEditorModesToolbar));
}


void FLegoAbilityEditorToolbar::FillAbilityEditorModesToolbar(FToolBarBuilder& ToolbarBuilder)
{
	TSharedPtr<FLegoAbilityEditor> AbilityEditorPin = AbilityEditor.Pin();
	TAttribute<FName> GetActiveMode(AbilityEditorPin.ToSharedRef(), &FLegoAbilityEditor::GetCurrentMode);
	FOnModeChangeRequested SetActiveMode = FOnModeChangeRequested::CreateSP(AbilityEditorPin.ToSharedRef(), &FLegoAbilityEditor::SetCurrentMode);

	// Left side padding
	AbilityEditorPin->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));

	AbilityEditorPin->AddToolbarWidget(
		SNew(SModeWidget, FLegoAbilityEditorModes::GetLocalizedMode(FLegoAbilityEditorModes::TimelineMode), FLegoAbilityEditorModes::TimelineMode)
		.OnGetActiveMode(GetActiveMode)
		.OnSetActiveMode(SetActiveMode)
		.ToolTip(IDocumentation::Get()->CreateToolTip(
			LOCTEXT("AbilityTimelineButtonTooltip", "Switch to timeline editing mode"),
			NULL,
			TEXT("Shared/Plugin/LegoAbility"),
			TEXT("TimelineMode")))
		.IconImage(FLegoAbilityEditorStyle::GetBrush("LegoAbilityEditor.TimelineMode.Small"))
		.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("TimelineMode")))
	);

	AbilityEditorPin->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(10.0f, 1.0f)));

	AbilityEditorPin->AddToolbarWidget(
		SNew(SModeWidget, FLegoAbilityEditorModes::GetLocalizedMode(FLegoAbilityEditorModes::GraphMode), FLegoAbilityEditorModes::GraphMode)
		.OnGetActiveMode(GetActiveMode)
		.OnSetActiveMode(SetActiveMode)
		.ToolTip(IDocumentation::Get()->CreateToolTip(
			LOCTEXT("AbilityBlueprintButtonTooltip", "Switch to blueprint editing mode"),
			NULL,
			TEXT("Shared/Plugin/LegoAbility"),
			TEXT("GraphMode")))
		.IconImage(FLegoAbilityEditorStyle::GetBrush("LegoAbilityEditor.GraphMode.Small"))
		.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("GraphMode")))
	);

	// Right side padding
	AbilityEditorPin->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(10.0f, 1.0f)));
}

void FLegoAbilityEditorToolbar::AddTimelineToolbar(TSharedPtr<FExtender> Extender)
{
	Extender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		AbilityEditor.Pin()->GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateSP(this, &FLegoAbilityEditorToolbar::FillTimelineModeToolbar));
}



TSharedRef<SWidget> FLegoAbilityEditorToolbar::CreatePreviewMeshComboButtonContents()
{
	static TWeakPtr<SNotificationItem> WeakPendingApplyMeshNotification = nullptr;

	FMenuBuilder MenuBuilder(true, nullptr);

	MenuBuilder.BeginSection(TEXT("ChoosePreviewMesh"), LOCTEXT("ChoosePreviewMesh", "Choose Preview Mesh"));
	{
		FAssetPickerConfig AssetPickerConfig;

		auto HandleAssetSelected = [&InAbilityEditor = AbilityEditor](const FAssetData& AssetData)
		{
			if (InAbilityEditor.IsValid())
			{
				InAbilityEditor.Pin()->SetPreviewAsset(AssetData);
			}

			FSlateApplication::Get().DismissAllMenus();
		};

		AssetPickerConfig.OnAssetSelected = FOnAssetSelected::CreateLambda(HandleAssetSelected);
		AssetPickerConfig.SelectionMode = ESelectionMode::Single;
		AssetPickerConfig.bAllowNullSelection = false;
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
		AssetPickerConfig.Filter.bRecursiveClasses = true;
		AssetPickerConfig.Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());

		IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
		TArray<FTopLevelAssetPath> ClassNames;
		TSet<FTopLevelAssetPath> DerivedClassNames;
		const ULegoAbilityEditorSettings* EditorSettings = GetDefault<ULegoAbilityEditorSettings>();
		for (TSoftClassPtr<AActor> PreviewClass : EditorSettings->PreviewAllowedClasses)
		{
			if (PreviewClass.IsValid())
			{
				ClassNames.Add(PreviewClass->GetClassPathName());
			}
		}
		// Add Character as the default filter, if none specific class is assigned.
		if (ClassNames.IsEmpty())
		{
			ClassNames.Add(ACharacter::StaticClass()->GetClassPathName());
		}
		AssetRegistry.GetDerivedClassNames(ClassNames, TSet<FTopLevelAssetPath>(), DerivedClassNames);
		AssetPickerConfig.OnShouldFilterAsset = FOnShouldFilterAsset::CreateLambda([InAbilityEditor=AbilityEditor, DerivedClassNames](const FAssetData& AssetData)
			{
				if (InAbilityEditor.IsValid())
				{
					const FString ParentClassFromData = AssetData.GetTagValueRef<FString>(FBlueprintTags::GeneratedClassPath);
					if (!ParentClassFromData.IsEmpty())
					{
						const FTopLevelAssetPath ClassObjectPath(FPackageName::ExportTextPathToObjectPath(ParentClassFromData));

						if (DerivedClassNames.Contains(ClassObjectPath))
						{
							return false;
						}
					}
					return true;
				}
				return true;
			});
		if (AbilityEditor.IsValid())
		{
			ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
			FAssetData PreviewAssetData;
			UAssetManager::Get().GetAssetDataForPath(Blueprint->PreviewAsset, PreviewAssetData);

			AssetPickerConfig.InitialAssetSelection = PreviewAssetData;
		}

		FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

		TSharedPtr<SBox> MenuEntry = SNew(SBox)
			.WidthOverride(300.0f)
			.HeightOverride(300.0f)
			[
				ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
			];

		MenuBuilder.AddWidget(MenuEntry.ToSharedRef(), FText::GetEmpty(), true);
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
};

void FLegoAbilityEditorToolbar::FillTimelineModeToolbar(FToolBarBuilder& ToolbarBuilder)
{
	const FLegoAbilityEditorCommands& Commands = FLegoAbilityEditorCommands::Get();
		
	ToolbarBuilder.BeginSection("Thumbnail");
	ToolbarBuilder.AddToolBarButton(Commands.m_CaptureThumbnail);
	ToolbarBuilder.EndSection();

	// Preview Asset Generic Asset Widget
	ToolbarBuilder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateSP(this, &FLegoAbilityEditorToolbar::CreatePreviewMeshComboButtonContents),
		LOCTEXT("SetPreviewMesh", "Preview Mesh"),
		LOCTEXT("SetPreviewMeshTooltip", "Set a new preview skeletal mesh for the current asset (stored per-animation or per-skeleton)"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Persona.TogglePreviewAsset", "Persona.TogglePreviewAsset.Small")
	);

	ToolbarBuilder.EndSection();
}

#undef LOCTEXT_NAMESPACE