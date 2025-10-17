// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorSettings.h"
#include "FrameNumberDisplayFormat.h"

ULegoAbilityEditorSettings::ULegoAbilityEditorSettings()
	: FOV(70.0f)
	, bMuteAudio(false)
	, AbilityStepTimeStep(ELegoAbilityEditorTimeStep::ThirtyFPS)
	, TimelineScrubSnapValue(1000)
	, TimelineDisplayFormat(EFrameNumberDisplayFormats::Seconds)
	, bTimelineDisplayPercentage(true)
	, bTimelineDisplayFormatSecondary(true)
{
}

float ULegoAbilityEditorSettings::GetAbilityTimeStepDelta() const
{
	switch (AbilityStepTimeStep)
	{
		case ELegoAbilityEditorTimeStep::FifteenFPS:
		{
			return 1.0f / 15.0f;
		}
		case ELegoAbilityEditorTimeStep::ThirtyFPS:
		{
			return 1.0f / 30.0f;
		}
		case ELegoAbilityEditorTimeStep::SixtyFPS:
		{
			return 1.0f / 60.0f;
		}
	}

	return 0.0f;
}

#if WITH_EDITOR
void ULegoAbilityEditorSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	SaveConfig();
}
#endif