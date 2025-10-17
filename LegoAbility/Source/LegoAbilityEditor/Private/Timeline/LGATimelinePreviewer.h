// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ITransportControl.h"


class ULGATimeline;
class FLGATimelineModelBase;
class ITimeSliderController;

/**
 * A timeline previewer 
 */
class FLGATimelinePreviewer : public TSharedFromThis<FLGATimelinePreviewer>
{
public:
	FLGATimelinePreviewer(FLGATimelineModelBase* TimelineModel);

	void SetCurrentTimeline(ULGATimeline* Timeline);

	void SetPosition(float InPosition);

	float GetPosition() {return Position;};

	EPlaybackMode::Type GetPlaybackMode(){return CurrentMode;};

	bool GetLoop(){return bLoop;};

	void SetLoop(bool InLoop){ bLoop = InLoop; };

	void ToggleLoop(){SetLoop(!bLoop);};

	void AdvanceTime(float DeltaTime);

	void TogglePlay();

	void Tick(float DeltaTime);

	void Pause();

	void Reset();

	void GotoEnd();

	float GetLength();


	TSharedPtr<ITimeSliderController> CurrentTimeSliderContrller;

protected:
	ULGAAction* GetAction(const FLGAActionEvent& ActionEvent);

private:
	FLGATimelineModelBase*			TimelineModel;

	TWeakObjectPtr<ULGATimeline>	PreviewTimeline;

	float							Position;

	EPlaybackMode::Type				CurrentMode;

	bool							bLoop;

	bool							bPlaying;


	/** Array of actions currently being executed. */
	TSet<FGuid> ActiveActionEvents;
};
