// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "BlueprintEditorModes.h"
#include "IDocumentation.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditorModes"

class FLegoAbilityEditor;

// This is the list of IDs for Ability Editor modes
struct FLegoAbilityEditorModes
{
	// App Name
	static const FName LegoAbilityEditorName;

	// Mode constants
	static const FName GraphMode;
	static const FName TimelineMode;
	static FText GetLocalizedMode(const FName InMode)
	{
		static TMap< FName, FText > LocModes;

		if (LocModes.Num() == 0)
		{
			LocModes.Add(GraphMode, NSLOCTEXT("LegoAbilityEditorModes", "GraphMode", "Graph"));
			LocModes.Add(TimelineMode, NSLOCTEXT("LegoAbilityEditorModes", "TimelineMode", "Timeline"));
		}

		check(InMode != NAME_None);
		const FText* OutDesc = LocModes.Find(InMode);
		check(OutDesc);
		return *OutDesc;
	}
private:
	FLegoAbilityEditorModes() {}
};

// Summoner for Ability Properties
class FAbilityDetailsTabSummoner : public FWorkflowTabFactory
{
public:
	FAbilityDetailsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

	// Create a tooltip widget for the tab
	virtual TSharedPtr<SToolTip> CreateTabToolTipWidget(const FWorkflowTabSpawnInfo& Info) const override
	{
		return IDocumentation::Get()->CreateToolTip(LOCTEXT("LegoAbilityDetailsTooltip", "Details tab allows you to edit generic properties of an ability (length, etc)."), NULL, TEXT("Shared/Editors/LegoAbility"), TEXT("AbilityAssetDetail_Window"));
	}
	// FWorkflowTabFactory interface

	static const FName ID;
};

/* Tab Summoner for the Viewport. */
class FViewportTabSummoner : public FWorkflowTabFactory
{
public:
	FViewportTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

	// Create a tooltip widget for the tab
	virtual TSharedPtr<SToolTip> CreateTabToolTipWidget(const FWorkflowTabSpawnInfo& Info) const override
	{
		return IDocumentation::Get()->CreateToolTip(LOCTEXT("LegoAbilityViewportTooltip", "Viewport allows you to see how this Ability would play in-game."), NULL, TEXT("Shared/Editors/LegoAbility"), TEXT("AbilityAssetDetail_Window"));
	}
	// FWorkflowTabFactory interface

	static const FName ID;
};

/* Tab Summoner for the Timeline List. */
class FTimelineListTabSummoner : public FWorkflowTabFactory
{
public:
	FTimelineListTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

	static const FName ID;
};


/* Tab Summoner for the Timeline. */
class FTimelineTabSummoner : public FWorkflowTabFactory
{
public:
	FTimelineTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
	static const FName ID;

	static const FName CurveEditorTab;
};

// Summoner for Task Properties
class FActionDetailsTabSummoner : public FWorkflowTabFactory
{
public:
	FActionDetailsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

	// Create a tooltip widget for the tab
	virtual TSharedPtr<SToolTip> CreateTabToolTipWidget(const FWorkflowTabSpawnInfo& Info) const override
	{
		return IDocumentation::Get()->CreateToolTip(LOCTEXT("LegoAbilityActionDetailsTooltip", "Action Details tab allows you to edit properties of an ability action."), NULL, TEXT("Shared/Editors/LegoAbility"), TEXT("AbilityTaskDetail_Window"));
	}
	// FWorkflowTabFactory interface

	static const FName ID;
};

// Summoner for Editor Settings
class FEditorSettingsTabSummoner : public FWorkflowTabFactory
{
public:
	FEditorSettingsTabSummoner(TSharedPtr<class FAssetEditorToolkit> InHostingApp);

	// FWorkflowTabFactory interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;

	// Create a tooltip widget for the tab
	virtual TSharedPtr<SToolTip> CreateTabToolTipWidget(const FWorkflowTabSpawnInfo& Info) const override
	{
		return IDocumentation::Get()->CreateToolTip(LOCTEXT("LegoAbilityEditorSettingsTooltip", "The Editor Settings tab lets you easily configure your settings to fit your style."), NULL, TEXT("Shared/Editors/LegoAbility"), TEXT("AbilityTaskDetail_Window"));
	}
	// FWorkflowTabFactory interface

	static const FName ID;
};

class FLegoAbilityEditorTimelineMode : public FApplicationMode
{
public:
	FLegoAbilityEditorTimelineMode(TSharedPtr<FLegoAbilityEditor> AbilityEditor);

	// FApplicationMode interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;
	// End of FApplicationMode interface

protected:
	TWeakPtr<FLegoAbilityEditor> m_AbilityEditor;
	FWorkflowAllowedTabSet m_AbilityEditorTabFactories;
};

class FLegoAbilityEditorBlueprintMode : public FBlueprintEditorUnifiedMode
{
public:
	FLegoAbilityEditorBlueprintMode(TSharedPtr<FLegoAbilityEditor> AbilityEditor);
};

#undef LOCTEXT_NAMESPACE