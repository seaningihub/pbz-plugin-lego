// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorModes.h"
#include "BlueprintEditorTabs.h"
#include "SBlueprintEditorToolbar.h"
#include "Slate/SLGATimelineListTabBody.h"
#include "Slate/SLGADetailsTabBody.h"
#include "Slate/SLGAEditorViewport.h"
#include "Slate/SLGATimelineTabBody.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorStyle.h"
#include "LegoAbilityEditorToolbar.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

const FName FLegoAbilityEditorModes::LegoAbilityEditorName("LegoAbilityEditorApp");
const FName FLegoAbilityEditorModes::GraphMode("GraphName");
const FName FLegoAbilityEditorModes::TimelineMode("TimelineModel");

const FName FAbilityDetailsTabSummoner::ID(TEXT("LegoAbilityEditor_AbilityDetails"));
const FName FViewportTabSummoner::ID(TEXT("LegoAbilityEditor_Viewport"));
const FName FTimelineListTabSummoner::ID(TEXT("LegoAbilityEditor_Animation"));
const FName FTimelineTabSummoner::ID(TEXT("LegoAbilityEditor_Timeline"));
const FName FTimelineTabSummoner::CurveEditorTab(TEXT("LegoAbilityEditor_CurveEditor"));
const FName FActionDetailsTabSummoner::ID(TEXT("LegoAbilityEditor_ActionDetails"));
const FName FEditorSettingsTabSummoner::ID(TEXT("LegoAbilityEditor_Settings"));

FLegoAbilityEditorTimelineMode::FLegoAbilityEditorTimelineMode(TSharedPtr<FLegoAbilityEditor> AbilityEditor)
	: FApplicationMode(FLegoAbilityEditorModes::TimelineMode, FLegoAbilityEditorModes::GetLocalizedMode), m_AbilityEditor(AbilityEditor)
{
	TabLayout = FTabManager::NewLayout("LegoAbilityEditor_Timeline_Layout_v3")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					// Left side (AbilityDetails + TimelineList)
					FTabManager::NewSplitter()
					->SetSizeCoefficient(0.2f)
					->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.8f)
						->SetHideTabWell(true)
						->AddTab(FAbilityDetailsTabSummoner::ID, ETabState::OpenedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.2f)
						->SetHideTabWell(true)
						->AddTab(FTimelineListTabSummoner::ID, ETabState::OpenedTab)
					)
				)
				->Split
				(
					// Middle (Viewport + Timeline)
					FTabManager::NewSplitter()
					->SetSizeCoefficient(0.6f)
					->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.6f)
						->SetHideTabWell(true)
						->AddTab(FViewportTabSummoner::ID, ETabState::OpenedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.4f)
						->SetHideTabWell(true)
						->AddTab(FTimelineTabSummoner::ID, ETabState::OpenedTab)
						->AddTab(FTimelineTabSummoner::CurveEditorTab, ETabState::ClosedTab)
						->SetForegroundTab(FTimelineTabSummoner::ID)
					)
				)
				->Split
				(
					// Right side (ActionDetails + EditorSettings)
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->SetHideTabWell(false)
					->AddTab(FActionDetailsTabSummoner::ID, ETabState::OpenedTab)
					->AddTab(FEditorSettingsTabSummoner::ID, ETabState::OpenedTab)
					->SetForegroundTab(FActionDetailsTabSummoner::ID)
				)
			)
		);

	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FAbilityDetailsTabSummoner(AbilityEditor)));
	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FTimelineListTabSummoner(AbilityEditor)));
	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FViewportTabSummoner(AbilityEditor)));
	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FTimelineTabSummoner(AbilityEditor)));
	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FActionDetailsTabSummoner(AbilityEditor)));
	m_AbilityEditorTabFactories.RegisterFactory(MakeShareable(new FEditorSettingsTabSummoner(AbilityEditor)));

	ToolbarExtender = MakeShareable(new FExtender);
	m_AbilityEditor.Pin()->GetAbilityToolbarBuilder()->AddTimelineToolbar(ToolbarExtender);

	if (UToolMenu* Toolbar = AbilityEditor->RegisterModeToolbarIfUnregistered(GetModeName()))
	{
		AbilityEditor->GetToolbarBuilder()->AddCompileToolbar(Toolbar);
	}
}

void FLegoAbilityEditorTimelineMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FBlueprintEditor> AbilityEditor = m_AbilityEditor.Pin();
	AbilityEditor->RegisterToolbarTab(InTabManager.ToSharedRef());
	AbilityEditor->PushTabFactories(m_AbilityEditorTabFactories);
}

void FLegoAbilityEditorTimelineMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
	
	if (m_AbilityEditor.IsValid())
	{
		m_AbilityEditor.Pin()->OnEnteringTimelineMode();
	}
}

FLegoAbilityEditorBlueprintMode::FLegoAbilityEditorBlueprintMode(TSharedPtr<FLegoAbilityEditor> AbilityEditor)
	: FBlueprintEditorUnifiedMode(AbilityEditor, FLegoAbilityEditorModes::GraphMode, FLegoAbilityEditorModes::GetLocalizedMode, false)
{
	
}

FAbilityDetailsTabSummoner::FAbilityDetailsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FAbilityDetailsTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityAssetDetails_TabTitle", "Ability Properties");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LegoAbilityEditor.Tabs.AbilityDetails");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityAssetProperties_MenuTitle", "Ability Properties");
	ViewMenuTooltip = LOCTEXT("LegoAbilityAssetProperties_MenuToolTip", "Shows the ability asset properties");
}

TSharedRef<SWidget> FAbilityDetailsTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SLGADetailsTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

FViewportTabSummoner::FViewportTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FViewportTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityViewport_TabTitle", "Viewport");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityViewport_MenuTitle", "Viewport");
	ViewMenuTooltip = LOCTEXT("LegoAbilityViewport_MenuToolTip", "Shows the in-game Viewport");
}

TSharedRef<SWidget> FViewportTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SViewportTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

FTimelineListTabSummoner::FTimelineListTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FTimelineListTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityTimeline_TabTitle", "Timeline");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LegoAbilityEditor.Tabs.Animation");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityTimeline_MenuTitle", "Timeline");
	ViewMenuTooltip = LOCTEXT("LegoAbilityTimeline_MenuToolTip", "Shows the timeline list");
}

TSharedRef<SWidget> FTimelineListTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SLGATimelineListTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

FTimelineTabSummoner::FTimelineTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FTimelineTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityTimeline_TabTitle", "Timeline");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LegoAbilityEditor.Tabs.Timeline");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityTimeline_MenuTitle", "Ability Action Properties");
	ViewMenuTooltip = LOCTEXT("LegoAbilityTimeline_MenuToolTip", "Shows the ability timeline editor");
}

TSharedRef<SWidget> FTimelineTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SLGATimelineTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

FActionDetailsTabSummoner::FActionDetailsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FActionDetailsTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityActionDetails_TabTitle", "Properties");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LegoAbilityEditor.Tabs.ActionDetails");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityTaskAssetProperties_MenuTitle", "Ability Action Properties");
	ViewMenuTooltip = LOCTEXT("LegoAbilityTaskAssetProperties_MenuToolTip", "Shows the ability action properties");
}

TSharedRef<SWidget> FActionDetailsTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SActionDetailsTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

FEditorSettingsTabSummoner::FEditorSettingsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(FEditorSettingsTabSummoner::ID, InHostingApp)
{
	TabLabel = LOCTEXT("LegoAbilityEditorSettings_TabTitle", "Editor Settings");
	TabIcon = FSlateIcon(FLegoAbilityEditorStyle::GetStyleSetName(), "LegoAbilityEditor.Tabs.EditorSettings");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("LegoAbilityEditorSettings_MenuTitle", "Ability Editor Settings");
	ViewMenuTooltip = LOCTEXT("LegoAbilityEditorSettings_MenuToolTip", "Shows the options for customizing the Ability editor behavior.");
}

TSharedRef<SWidget> FEditorSettingsTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SLegoAbilityEditorSettingsTabBody, StaticCastSharedPtr<FLegoAbilityEditor>(HostingApp.Pin()));
}

#undef LOCTEXT_NAMESPACE
