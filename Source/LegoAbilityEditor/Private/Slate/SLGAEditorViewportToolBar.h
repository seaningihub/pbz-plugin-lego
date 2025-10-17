// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SViewportToolBar.h"

class FLegoAbilityEditor;
class SViewportTabBody;

/* Viewport widget for our Ability Viewport. */
class SLGAEditorViewportToolBar : public SViewportToolBar
{
public:
	SLATE_BEGIN_ARGS(SLGAEditorViewportToolBar) {}
	SLATE_ARGUMENT(TSharedPtr<FLegoAbilityEditor>, AbilityEditor)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<SViewportTabBody> InViewport, TSharedPtr<class SEditorViewport> InRealViewport);

private:
	/* Creates the basic view option menu.*/
	TSharedRef<SWidget> GenerateViewMenu();
	
	/* Creates the Viewport Type (Perspective, etc) menu. */
	TSharedRef<SWidget> GenerateViewportTypeMenu();

	/* Camera Labels and Icons*/
	FText GetCameraMenuLabel() const;
	const FSlateBrush* GetCameraMenuLabelIcon() const;

	/* Callback for Transform bar visibility. */
	EVisibility GetTransformToolBarVisibility() const;

	/* Pointer to our Viewport Tab widget. */
	TWeakPtr<SViewportTabBody> Viewport;

	/* Pointer to our Ability Editor instance. */
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
};