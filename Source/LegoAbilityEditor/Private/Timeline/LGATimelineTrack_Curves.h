// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Timeline/LGATimelineTrack.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/SListView.h"


class FLGATimelineTrack_Curves : public FLGATimelineTrack
{
public:
	FLGATimelineTrack_Curves(const TSharedRef<FLGATimelineModelBase>& InModel);

	/** FLGATimelineTrack interface */
	virtual TSharedRef<SWidget> GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow) override;

private:
	TSharedRef<SWidget> BuildCurvesSubMenu();

	void CreateNewCurveClicked();
	void CreateTrack(const FText& ComittedText, ETextCommit::Type CommitInfo);
	void AddVariableCurve(const FName& InCurveName);
	void DeleteAllCurves();

	/** Handlers for showing curve points */
	void HandleShowCurvePoints();
	bool IsShowCurvePointsEnabled() const;

	/** Curve Picker Callbacks */
	void OnVariableCurveNamePicked(const FName& InCurveName);
	bool IsCurveMarkedForExclusion(const FName& InCurveName);
	
private:
	TSharedPtr<SWidget>	OutlinerWidget;
};
