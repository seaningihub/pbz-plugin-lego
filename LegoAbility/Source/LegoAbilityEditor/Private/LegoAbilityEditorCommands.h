// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LegoAbilityEditorStyle.h"
#include "Framework/Commands/Commands.h"
#include "Styling/ISlateStyle.h"

class FLegoAbilityEditorCommands : public TCommands<FLegoAbilityEditorCommands>
{
public:
	FLegoAbilityEditorCommands()
		: TCommands<FLegoAbilityEditorCommands>
		(
			TEXT("LegoAbilityEditor"), // Context name for fast lookup
			NSLOCTEXT("Contexts", "LegoAbilityEditor", "Ability Editor"), // Localized context name for displaying
			NAME_None, // Context Parent
			FLegoAbilityEditorStyle::Get()->GetStyleSetName() // Icon Style Set
		)
	{
	}

	// Begin TCommand interface
	virtual void RegisterCommands() override;
	// End TCommand interface

	TSharedPtr<FUICommandInfo> m_ToggleDrawCameraComponent;
	TSharedPtr<FUICommandInfo> m_ToggleDrawArrowComponent;
	TSharedPtr<FUICommandInfo> m_CaptureThumbnail;
};

class FLegoAbilityEditorViewportCommands : public TCommands<FLegoAbilityEditorViewportCommands>
{
public:
	FLegoAbilityEditorViewportCommands()
		: TCommands<FLegoAbilityEditorViewportCommands>
		(
			TEXT("LegoAbilityEditorViewport"), // Context name for fast lookup
			NSLOCTEXT("Contexts", "LegoAbilityEditorViewport", "Ability Editor Viewport"), // Localized context name for displaying
			NAME_None, // Context Parent
			FLegoAbilityEditorStyle::Get()->GetStyleSetName() // Icon Style Set
		)
	{	
	}

	// Begin TCommand interface
	virtual void RegisterCommands() override;
	// End TCommand interface

	TSharedPtr<FUICommandInfo> m_CameraFollow;
};

class FLegoAbilityEditorTimelineCommands : public TCommands<FLegoAbilityEditorTimelineCommands>
{
public:
	FLegoAbilityEditorTimelineCommands()
		: TCommands<FLegoAbilityEditorTimelineCommands>
		(
			TEXT("LegoAbilityEditorTimeline"),
			NSLOCTEXT("Contexts", "LegoAbilityEditorTimeline", "Ability Editor Timeline"),
			NAME_None,
			FLegoAbilityEditorStyle::GetStyleSetName()
		)
	{
	}

	// Begin TCommand interface
	virtual void RegisterCommands() override;
	// End TCommand interface

	TSharedPtr<FUICommandInfo> TogglePlay;

	TSharedPtr<FUICommandInfo> AddActionTrack;
	TSharedPtr<FUICommandInfo> InsertActionTrack;
	TSharedPtr<FUICommandInfo> RemoveActionTrack;
	TSharedPtr<FUICommandInfo> DeleteAction;
	TSharedPtr<FUICommandInfo> CopyActions;
	TSharedPtr<FUICommandInfo> PasteActions;

	TSharedPtr<FUICommandInfo> AddCurve;
	TSharedPtr<FUICommandInfo> EditCurve;
	TSharedPtr<FUICommandInfo> ShowCurveKeys;
	TSharedPtr<FUICommandInfo> RemoveCurve;
	TSharedPtr<FUICommandInfo> RemoveAllCurves;
	TSharedPtr<FUICommandInfo> CopySelectedCurveNames;

	TSharedPtr<FUICommandInfo> DisplaySeconds;
	TSharedPtr<FUICommandInfo> DisplayFrames;
	TSharedPtr<FUICommandInfo> DisplayPercentage;
	TSharedPtr<FUICommandInfo> DisplaySecondaryFormat;
};
