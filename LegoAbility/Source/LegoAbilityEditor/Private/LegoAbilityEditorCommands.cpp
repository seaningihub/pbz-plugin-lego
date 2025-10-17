// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorCommands.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditorCommands"

void FLegoAbilityEditorCommands::RegisterCommands()
{
	UI_COMMAND(m_ToggleDrawArrowComponent, "Show Arrow Component", "Draws the Arrow Component (if it exists) on the Preview Actor.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(m_ToggleDrawCameraComponent, "Show Camera Component", "Draws the Camera Component (if it exists) on the Preview Actor.", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(m_CaptureThumbnail, "Capture Thumbnail", "Captures the current viewport image and uses it as the thumbnail for this Ability.", EUserInterfaceActionType::Button, FInputChord());
}

void FLegoAbilityEditorViewportCommands::RegisterCommands()
{
	UI_COMMAND(m_CameraFollow, "Follow", "Sets the camera to follow the preview actor.", EUserInterfaceActionType::ToggleButton, FInputChord());
}

void FLegoAbilityEditorTimelineCommands::RegisterCommands()
{
	UI_COMMAND(TogglePlay, "Play/Pause", "Play or pause the current timeline", EUserInterfaceActionType::ToggleButton, FInputChord(EKeys::SpaceBar));

	UI_COMMAND(AddActionTrack, "Add Action Track", "Add a new action track", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(InsertActionTrack, "Insert Action Track", "Insert a new action track above here", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(RemoveActionTrack, "Remove Action Track", "Remove this action track", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(DeleteAction, "Delete", "Deletes the selected actions.", EUserInterfaceActionType::Button, FInputChord(EKeys::Platform_Delete));
	UI_COMMAND(CopyActions, "Copy", "Copy ability action events.", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::C));
	UI_COMMAND(PasteActions, "Paste", "Paste ability action event here.", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::V));
	
	UI_COMMAND(AddCurve, "Add Curve...", "Add a new variable float curve", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(EditCurve, "Edit Curve", "Edit this curve in the curve editor tab", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ShowCurveKeys, "Show Curve Keys", "Show keys for all curves in the timeline", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(RemoveCurve, "Remove Curve", "Remove this curve", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(RemoveAllCurves, "Remove All Curves", "Remove all the curves in this animation", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(CopySelectedCurveNames, "Copy Selected Curve Names", "Copy the name of the selected curves to the clipboard", EUserInterfaceActionType::Button, FInputChord());
	
	UI_COMMAND(DisplaySeconds, "Seconds", "Display the time in seconds", EUserInterfaceActionType::RadioButton, FInputChord());
	UI_COMMAND(DisplayFrames, "Frames", "Display the time in frames", EUserInterfaceActionType::RadioButton, FInputChord());
	UI_COMMAND(DisplayPercentage, "Percentage", "Display the percentage along with the time with the scrubber", EUserInterfaceActionType::Check, FInputChord());
	UI_COMMAND(DisplaySecondaryFormat, "Secondary", "Display the time or frame count as a secondary format along with the scrubber", EUserInterfaceActionType::Check, FInputChord());
}

#undef LOCTEXT_NAMESPACE