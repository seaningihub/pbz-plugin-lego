// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SEditorViewport.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

class FLegoAbilityEditor;

/* The Viewport for the Ability Editor. */
class SLGAEditorViewport : public SEditorViewport
{
public:
	SLATE_BEGIN_ARGS(SLGAEditorViewport) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<class FLegoAbilityEditor> InAbilityEditor, TSharedPtr<class SViewportTabBody> InViewportTabBody);
	
protected:
	// SEditorViewport interface
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	virtual TSharedPtr<SWidget> MakeViewportToolbar() override;
	// End of SEditorViewport interface

protected:
	/* Pointer to the compound widget that owns this viewport widget */
	TWeakPtr<class SViewportTabBody> ViewportTabBody;

	/* Pointer to our Ability Editor instance. */
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
};

/* Widget that contains our Viewport. */
class SViewportTabBody : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SViewportTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);

	/* Captures the current Viewport image as a thumbnail. */
	void CaptureThumbnail() const;

	/* Returns the Viewport client. */
	TSharedPtr<FEditorViewportClient> GetEditorViewportClient() const { return EditorViewportClient; }

	/* Returns the Viewport widget. */
	TSharedPtr<SLGAEditorViewport> GetViewportWidget() const { return ViewportWidget; }

	/* Returns the Viewport Commands. */
	TSharedPtr<FUICommandList> GetCommandList() { return Commands; }

private:
	/* Pointer to our Ability Editor instance. */
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;

	/* Level viewport client.  */
	TSharedPtr<FEditorViewportClient> EditorViewportClient;

	/* Viewport widget. */
	TSharedPtr<SLGAEditorViewport> ViewportWidget;

	/* Viewport Commands. */
	TSharedPtr<FUICommandList> Commands;
};

#undef LOCTEXT_NAMESPACE