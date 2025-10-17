// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "LGATimeline.h"
#include "ITransportControl.h"


class FLGATimelinePreviewer;
/**
 * 
 */
class LEGOABILITYEDITOR_API SLGATimelineTransportControls : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineTransportControls) {}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLGATimelinePreviewer> InTimelinePreviewer);

private:

	FReply OnClick_Forward_Step();

	FReply OnClick_Forward_End();

	FReply OnClick_Backward_Step();

	FReply OnClick_Backward_End();

	FReply OnClick_Forward();

	FReply OnClick_ToggleLoop();

	bool IsLoopStatusOn() const;

	EPlaybackMode::Type GetPlaybackMode() const;


private:
	TWeakPtr<FLGATimelinePreviewer> TimelinePreviewer;
};