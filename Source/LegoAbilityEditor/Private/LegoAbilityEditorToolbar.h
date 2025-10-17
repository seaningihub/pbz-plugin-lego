// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Textures/SlateIcon.h"
#include "Input/Reply.h"

struct FAssetData;
class FAssetThumbnailPool;
class FExtender;
class FLegoAbilityEditor;
class FToolBarBuilder;

/* Ability Editor Toolbar */
class FLegoAbilityEditorToolbar : public TSharedFromThis<FLegoAbilityEditorToolbar>
{
public:
	FLegoAbilityEditorToolbar(TSharedPtr<FLegoAbilityEditor> InAbilityEditor);

	/** Builds the modes toolbar for the Lego Ability Editor. */
	void AddAbilityEditorModesToolbar(TSharedPtr<FExtender> Extender);

	/** Builds the timeline toolbar for the Lego Ability Editor. */
	void AddTimelineToolbar(TSharedPtr<FExtender> Extender);


private:
	bool IsAssetValid(const FAssetData& Asset) const;

	/* Helper methods for the Toolbar. */
	void FillAbilityEditorModesToolbar(FToolBarBuilder& ToolbarBuilder);

	TSharedRef<SWidget> CreatePreviewMeshComboButtonContents();
	void FillTimelineModeToolbar(FToolBarBuilder& ToolbarBuilder);

	bool ShouldShowPauseIcon() const;

	/* Returns the Icon based on our Ability status (Play/Stop). */
	FSlateIcon GetPlayIcon() const;

	/* Returns the proper Text based on our Ability status. */
	FText GetPlayText() const;

	/* Returns the proper Tooltip based on our AAbility status. */
	FText GetPlayToolTip() const;

	/* Pointer back to the Ability Editor that owns us. */
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;

};


