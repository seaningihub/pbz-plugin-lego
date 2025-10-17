// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class FLegoAbilityEditor;

/* Timeline Panel is a widget that displays all the Tasks in our Ability. When a Task is added or removed, the widget will update itself appropriately. */
class SLGATimelineTabBody : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);

private:
	/* Pointer to our Ability Editor instance. */
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
};
