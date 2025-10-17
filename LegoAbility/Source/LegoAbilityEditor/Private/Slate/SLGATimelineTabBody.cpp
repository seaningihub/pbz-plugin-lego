// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineTabBody.h"
#include "Timeline/LGATimelineModel.h"
#include "Timeline/SLGATimeline.h"
#include "LegoAbilityEditor.h"
#include "LGATimeline.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

void SLGATimelineTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	AbilityEditor = InAbilityEditor;
	ChildSlot
	[
		SNew(SLGATimeline, InAbilityEditor->GetAnimModel().ToSharedRef())
		.Visibility_Lambda([this]()->EVisibility
		{
			return AbilityEditor.Pin()->GetAnimModel()->GetAbilityTimeline() == ULGATimeline::GetNullTimeline() ? EVisibility::Collapsed : EVisibility::Visible;
		})
	];
}

#undef LOCTEXT_NAMESPACE