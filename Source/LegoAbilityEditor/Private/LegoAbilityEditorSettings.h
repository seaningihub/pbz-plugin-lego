// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LegoAbilityEditorSettings.generated.h"

enum class EFrameNumberDisplayFormats : uint8;

UENUM()
enum class ELegoAbilityEditorTimeStep : uint8
{
	FifteenFPS UMETA(DisplayName = "15 FPS"),
	ThirtyFPS UMETA(DisplayName = "30 FPS"),
	SixtyFPS UMETA(DisplayName = "60 FPS"),
};

// Settings for the Lego Ability editor
UCLASS(config = EditorPerProjectUserSettings)
class ULegoAbilityEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	ULegoAbilityEditorSettings();

	/* What to set the Field of View (FOV) to for the in-game viewport in the Ability Editor.*/
	UPROPERTY(config, EditAnywhere, Category = Viewport, meta = (DisplayName = "Field of View", ClampMin = 70.0f, ClampMax = 180.0f))
	float FOV;

	/* Whether to mute the in-game audio of the viewport or not.*/
	UPROPERTY(config, EditAnywhere, Category = Viewport, meta = (DisplayName = "Mute Audio"))
	bool bMuteAudio;

	/* At what rate to step an Ability when paused and stepping frame by frame.*/
	UPROPERTY(config, EditAnywhere, Category = Viewport, meta = (DisplayName = "Ability Step Rate"))
	ELegoAbilityEditorTimeStep AbilityStepTimeStep;

	/* The target asset used in the Viewport.*/
	UPROPERTY(config, EditAnywhere, Category = Preview)
	TArray<TSoftClassPtr<AActor>> PreviewAllowedClasses;

	/** Snap value used to determine scrub resolution of the ability timeline */
	UPROPERTY(config)
	int32 TimelineScrubSnapValue;

	/** Display format for the ability timeline */
	UPROPERTY(config)
	EFrameNumberDisplayFormats TimelineDisplayFormat;

	/** Whether to display percentage in the ability timeline */
	UPROPERTY(config)
	bool bTimelineDisplayPercentage;

	/** Whether to display secondary format (times/frames) in the ability timeline */
	UPROPERTY(config)
	bool bTimelineDisplayFormatSecondary;

	/* Returns the delta time value based on the rate selected by the user. */
	float GetAbilityTimeStepDelta() const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
