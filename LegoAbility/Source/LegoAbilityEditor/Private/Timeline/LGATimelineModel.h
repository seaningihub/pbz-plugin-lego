// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGATimelineModelBase.h"
#include "SLGATimelineTimingPanel.h"
#include "Timeline/LGATimelineTrack_Curves.h"

enum class EFrameNumberDisplayFormats : uint8;

class FLGATimelineModel : public FLGATimelineModelBase
{
public:
	FLGATimelineModel(const TSharedRef<FUICommandList>& InCommandList, TSharedPtr<FLegoAbilityEditor> AbilityEditor, ULGATimeline* InTimeline);

	/** FAnimModel interface */
	virtual void RefreshTracks() override;
	virtual void Initialize() override;
	virtual void UpdateRange(bool ResetWorkingRange = false) override;

	/** Timing panel display options */
	bool IsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType) const;
	void ToggleTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType);

	/** Action track timing options */
	bool IsActionsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType) const;
	void ToggleActionsTimingElementDisplayEnabled(ELGATimingElementType::Type ElementType);

	/** 
	 * Clamps the sequence to the specified length 
	 * @return		Whether clamping was/is necessary
	 */
	virtual bool ClampToEndTime(float NewEndTime);

	/** Switch timeline */
	void SetAbilityTimeline(ULGATimeline* InTimeline);
	virtual ULGATimeline* GetAbilityTimeline() const override { return Timeline.Get(); }

protected:
	/** Refresh notify tracks */
	void RefreshNotifyTracks();

	/** Refresh curve tracks*/
	void RefreshCurveTracks();

private:
	/** UI handlers */
	void SetDisplayFormat(EFrameNumberDisplayFormats InFormat);
	bool IsDisplayFormatChecked(EFrameNumberDisplayFormats InFormat) const;
	void ToggleDisplayPercentage();
	bool IsDisplayPercentageChecked() const;
	void ToggleDisplaySecondary();
	bool IsDisplaySecondaryChecked() const;
	void SaveSettings();

private:
	/** The ability timeline */
	TWeakObjectPtr<ULGATimeline> Timeline;

	/** Timing panel track */
	TSharedPtr<class FLGATimelineTrack_TimingPanel> TimingPanel;

	/** Root track for notifies */
	TSharedPtr<class FLGATimelineTrack_Actions> ActionRoot;

	/** Root track for curves */
	TSharedPtr<FLGATimelineTrack_Curves> CurveRoot;

	/** Legacy notify panel track */
	TSharedPtr<class FLGATimelineTrack_ActionsPanel> ActionPanel;

	/** Display flags for timing panel */
	bool TimingElementNodeDisplayFlags[ELGATimingElementType::Max];

	/** Display flags for actions track */
	bool ActionsTimingElementNodeDisplayFlags[ELGATimingElementType::Max];
};