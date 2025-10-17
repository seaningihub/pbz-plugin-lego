// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "Templates/SharedPointer.h"
#include "UObject/NameTypes.h"

struct FSlateBrush;

/* This class is our Style Set for Lego Ability Editor. */
class FLegoAbilityEditorStyle
{
public:
	/* Initialize the Style Set. */
	static void Initialize();

	/* Shutdown the Style set. */
	static void Shutdown();

	/* Grab the Style Set (singleton). */
	static TSharedPtr<class ISlateStyle> Get();

	/* Returns the name of the Style Set. */
	static FName GetStyleSetName() { return StyleName; }

	/* Returns the given Brush according to the passed in BrushName. Returns nullptr if not found. */
	static const FSlateBrush* GetBrush(FName BrushName);

	/* Returns the given Color according to the passed in ColorName. Returns nullptr if not found. */
	static const FLinearColor& GetColor(FName ColorName);

private:
	/* Helper method to grab the Plugin's content folder. */
	static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);

	/* Our Style Set. */
	static TSharedPtr<class FSlateStyleSet> StyleSet;
	
	/* The name of our Style Set. */
	static FName StyleName;
};