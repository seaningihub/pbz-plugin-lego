// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineModelBase.h"
#include "LGATimelineTrack.h"
#include "ScopedTransaction.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorSettings.h"
#include "LGATask_PlayTimeline.h"
#include "LGATimeline.h"
#include "Timeline/LGATimelinePreviewer.h"
#include "ITimeSlider.h"
#include "Actions/LGAAction.h"

#define LOCTEXT_NAMESPACE "FAnimModel"

const FLGATimelineModelBase::FSnapType FLGATimelineModelBase::FSnapType::CompositeSegment("CompositeSegment", LOCTEXT("CompositeSegmentSnapName", "Composite Segments"), true);

FLGATimelineModelBase::FLGATimelineModelBase(const TSharedRef<FUICommandList>& InCommandList, TSharedPtr<FLegoAbilityEditor> AbilityEditor)
	: WeakCommandList(InCommandList)
	, WeakAbilityEditor(AbilityEditor)
	, bIsSelecting(false)
{
	// Init preview
	TimelinePreviewer = MakeShared<FLGATimelinePreviewer>(this);
}


FLGATimelineModelBase::~FLGATimelineModelBase()
{

}

TSharedPtr<FLGATimelinePreviewer> FLGATimelineModelBase::GetTimelinePreviewer()
{
	return TimelinePreviewer;
}

FAnimatedRange FLGATimelineModelBase::GetViewRange() const
{
	return ViewRange;
}

FAnimatedRange FLGATimelineModelBase::GetWorkingRange() const
{
	return WorkingRange;
}

double FLGATimelineModelBase::GetFrameRate() const
{
	switch (GetDefault<ULegoAbilityEditorSettings>()->AbilityStepTimeStep)
	{
	case ELegoAbilityEditorTimeStep::FifteenFPS:
	{
		return 15;
	}
	case ELegoAbilityEditorTimeStep::ThirtyFPS:
	{
		return 30;
	}
	case ELegoAbilityEditorTimeStep::SixtyFPS:
	{
		return 60;
	}
	}

	return 30;
}

int32 FLGATimelineModelBase::GetTickResolution() const
{
	return FMath::RoundToInt((double)GetDefault<ULegoAbilityEditorSettings>()->TimelineScrubSnapValue * GetFrameRate());
}

TRange<FFrameNumber> FLGATimelineModelBase::GetPlaybackRange() const
{
	float TimelineLength = 1.f;

	if (ULGATimeline* Timeline = GetAbilityTimeline())
	{
		TimelineLength = Timeline->GetPlayLength();
	}

	const int32 Resolution = GetTickResolution();
	return TRange<FFrameNumber>(FFrameNumber(0), FFrameNumber(FMath::RoundToInt32(TimelineLength * (double)Resolution)));
}

void FLGATimelineModelBase::SetPlaybackRange(TRange<FFrameNumber> NewRange)
{
	if (ULGATimeline* Timeline = GetAbilityTimeline())
	{
		FFrameNumber Duration = NewRange.GetUpperBoundValue() - NewRange.GetLowerBoundValue();
		float PlayLength = (float)Duration.Value / GetTickResolution();
		if (PlayLength != Timeline->GetPlayLength())
		{
			FScopedTransaction Transaction(LOCTEXT("ChangeTimelineDuration", "Change Timeline Duration"));
			Timeline->Modify();
			Timeline->SetPlayLength(PlayLength);
			Timeline->PostEditChange();
			UpdateRange();
		}
	}
}

FFrameNumber FLGATimelineModelBase::GetScrubPosition() const
{
	if (TimelinePreviewer.IsValid())
	{
		float CurrentTime = TimelinePreviewer->GetPosition();
		return FFrameNumber(FMath::RoundToInt32(CurrentTime * (double)GetTickResolution()));
	}

	return FFrameNumber(0);
}

void FLGATimelineModelBase::SetScrubPosition(FFrameTime NewScrubPostion) const
{
	if (TimelinePreviewer.IsValid())
	{
		TimelinePreviewer->Pause();
		TimelinePreviewer->SetPosition(NewScrubPostion.AsDecimal() / (double)GetTickResolution());
	}
}

void FLGATimelineModelBase::HandleViewRangeChanged(TRange<double> InRange, EViewRangeInterpolation InInterpolation)
{
	SetViewRange(InRange);
}

void FLGATimelineModelBase::SetViewRange(TRange<double> InRange)
{
	ViewRange = InRange;

	if (WorkingRange.HasLowerBound() && WorkingRange.HasUpperBound())
	{
		WorkingRange = TRange<double>::Hull(WorkingRange, ViewRange);
	}
	else
	{
		WorkingRange = ViewRange;
	}
}


void FLGATimelineModelBase::ResizeTimelineToActions()
{
	if (ULGATimeline* Timeline = GetAbilityTimeline())
	{
		FScopedTransaction Transaction(LOCTEXT("ResizeTimeline", "Resize Timeline"));
		Timeline->Modify();
		Timeline->ResizeLength();
		
		UpdateRange();
	}
}

void FLGATimelineModelBase::HandleWorkingRangeChanged(TRange<double> InRange)
{
	WorkingRange = InRange;
}

bool FLGATimelineModelBase::IsTrackSelected(const TSharedRef<FLGATimelineTrack>& InTrack) const
{ 
	return SelectedTracks.Find(InTrack) != nullptr;
}

void FLGATimelineModelBase::ClearTrackSelection()
{
	SelectedTracks.Empty();
}

void FLGATimelineModelBase::SetTrackSelected(const TSharedRef<FLGATimelineTrack>& InTrack, bool bIsSelected)
{
	if (bIsSelected)
	{
		SelectedTracks.Add(InTrack);
	}
	else
	{
		SelectedTracks.Remove(InTrack);
	}
}

void FLGATimelineModelBase::SelectObjects(const TArray<UObject*>& Objects)
{
	if (!bIsSelecting)
	{
		TGuardValue<bool> GuardValue(bIsSelecting, true);
		OnSelectObjects.ExecuteIfBound(Objects);

		OnHandleObjectsSelectedDelegate.Broadcast(Objects);

		SelectedActions.Reset();
		for (UObject* Obj : Objects)
		{
			if (ULGAAction* Action = Cast<ULGAAction>(Obj))
			{
				SelectedActions.Add(Action);
			}
		}
	}
}

void FLGATimelineModelBase::ClearDetailsView()
{
	if (!bIsSelecting)
	{
		TGuardValue<bool> GuardValue(bIsSelecting, true);

		TArray<UObject*> Objects;
		OnSelectObjects.ExecuteIfBound(Objects);
		OnHandleObjectsSelectedDelegate.Broadcast(Objects);
	}
}

float FLGATimelineModelBase::CalculateSequenceLengthOfEditorObject() const
{
	if (ULGATimeline* Timeline = GetAbilityTimeline())
	{
		return Timeline->GetPlayLength();
	}

	return 0.0f;
}

void FLGATimelineModelBase::SetEditableTime(int32 TimeIndex, double Time, bool bIsDragging)
{
	EditableTimes[TimeIndex] = FMath::Clamp(Time, 0.0, (double)CalculateSequenceLengthOfEditorObject());

	OnSetEditableTime(TimeIndex, EditableTimes[TimeIndex], bIsDragging);
}

bool FLGATimelineModelBase::Snap(float& InOutTime, float InSnapMargin, bool bEnableSnapToFrame) const
{
	double DoubleTime = (double)InOutTime;
	bool bResult = Snap(DoubleTime, (double)InSnapMargin, bEnableSnapToFrame);
	InOutTime = DoubleTime;
	return bResult;
}

bool FLGATimelineModelBase::Snap(double& InOutTime, double InSnapMargin, bool bEnableSnapToFrame) const
{
	InSnapMargin = FMath::Max(InSnapMargin, (double)KINDA_SMALL_NUMBER);

	// Find the closest in-range enabled snap time
	const FSnapTime* ClosestSnapTime = nullptr;
	double ClosestDelta = DBL_MAX;
	for (const FSnapTime& SnapTime : SnapTimes)
	{
		double Delta = FMath::Abs(SnapTime.Time - InOutTime);
		if (Delta < InSnapMargin && Delta < ClosestDelta)
		{
			if (const FSnapType* SnapType = SnapTypes.Find(SnapTime.Type))
			{
				if (SnapType->bEnabled)
				{
					ClosestDelta = Delta;
					ClosestSnapTime = &SnapTime;
				}
			}
		}
	}

	if (ClosestSnapTime != nullptr)
	{
		InOutTime = ClosestSnapTime->Time;
		return true;
	}
	else if(bEnableSnapToFrame)
	{
		if (ULGATimeline* CurrentTimeline = GetAbilityTimeline())
		{
			double TimelineLength = CurrentTimeline->GetPlayLength();
			double StepDeltaTime = GetDefault<ULegoAbilityEditorSettings>()->GetAbilityTimeStepDelta();

			double SnappedTime = FMath::RoundToDouble(InOutTime / StepDeltaTime);
			if (SnappedTime >= 0 && SnappedTime <= FMath::FloorToDouble(TimelineLength / StepDeltaTime))
			{
				InOutTime = SnappedTime * StepDeltaTime;
				return true;
			}
		}
	}

	return false;
}

void FLGATimelineModelBase::BuildContextMenu(FMenuBuilder& InMenuBuilder)
{
	// Let each selected item contribute to the context menu
	TSet<FName> ExistingMenuTypes;
	for (const TSharedRef<FLGATimelineTrack>& SelectedItem : SelectedTracks)
	{
		SelectedItem->AddToContextMenu(InMenuBuilder, ExistingMenuTypes);
	}
}

#undef LOCTEXT_NAMESPACE