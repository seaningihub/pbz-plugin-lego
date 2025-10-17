// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineTrackArea.h"
#include "Types/PaintArgs.h"
#include "Layout/ArrangedChildren.h"
#include "Rendering/DrawElements.h"
#include "Layout/LayoutUtils.h"
#include "Widgets/SWeakWidget.h"
#include "EditorStyleSet.h"
#include "SLGATimelineTrack.h"
#include "SLGATimelineOutliner.h"
#include "LGATimelineTrack.h"
#include "LGATimelineModelBase.h"
#include "LGATimeSliderController.h"

FLGATimelineTrackAreaSlot::FLGATimelineTrackAreaSlot(const TSharedPtr<SLGATimelineTrack>& InSlotContent)
	: TAlignmentWidgetSlotMixin<FLGATimelineTrackAreaSlot>(HAlign_Fill, VAlign_Top)
{
	TrackWidget = InSlotContent;

	AttachWidget(
		SNew(SWeakWidget)
		.Clipping(EWidgetClipping::ClipToBounds)
		.PossiblyNullContent(InSlotContent)
	);
}

float FLGATimelineTrackAreaSlot::GetVerticalOffset() const
{
	TSharedPtr<SLGATimelineTrack> PinnedTrackWidget = TrackWidget.Pin();
	return PinnedTrackWidget.IsValid() ? PinnedTrackWidget->GetPhysicalPosition() : 0.f;
}

void SLGATimelineTrackArea::Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModelBase>& InAnimModel, const TSharedRef<FLGATimeSliderController>& InTimeSliderController)
{
	WeakModel = InAnimModel;
	WeakTimeSliderController = InTimeSliderController;
}

void SLGATimelineTrackArea::SetOutliner(const TSharedPtr<SLGATimelineOutliner>& InOutliner)
{
	WeakOutliner = InOutliner;
}

void SLGATimelineTrackArea::Empty()
{
	TrackSlots.Empty();
	Children.Empty();
}

void SLGATimelineTrackArea::AddTrackSlot(const TSharedRef<FLGATimelineTrack>& InTrack, const TSharedPtr<SLGATimelineTrack>& InSlot)
{
	TrackSlots.Add(InTrack, InSlot);
	Children.AddSlot(FLGATimelineTrackAreaSlot::FSlotArguments(MakeUnique<FLGATimelineTrackAreaSlot>(InSlot)));
}

TSharedPtr<SLGATimelineTrack> SLGATimelineTrackArea::FindTrackSlot(const TSharedRef<FLGATimelineTrack>& InTrack)
{
	// Remove stale entries
	TrackSlots.Remove(TWeakPtr<FLGATimelineTrack>());

	return TrackSlots.FindRef(InTrack).Pin();
}

void SLGATimelineTrackArea::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	for (int32 ChildIndex = 0; ChildIndex < Children.Num(); ++ChildIndex)
	{
		const FLGATimelineTrackAreaSlot& CurChild = Children[ChildIndex];

		const EVisibility ChildVisibility = CurChild.GetWidget()->GetVisibility();
		if (!ArrangedChildren.Accepts(ChildVisibility))
		{
			continue;
		}

		const FMargin Padding(0, CurChild.GetVerticalOffset(), 0, 0);

		AlignmentArrangeResult XResult = AlignChild<Orient_Horizontal>(AllottedGeometry.GetLocalSize().X, CurChild, Padding, 1.0f, false);
		AlignmentArrangeResult YResult = AlignChild<Orient_Vertical>(AllottedGeometry.GetLocalSize().Y, CurChild, Padding, 1.0f, false);

		ArrangedChildren.AddWidget(ChildVisibility,
			AllottedGeometry.MakeChild(
				CurChild.GetWidget(),
				FVector2D(XResult.Offset, YResult.Offset),
				FVector2D(XResult.Size, YResult.Size)
			)
		);
	}
}

FVector2D SLGATimelineTrackArea::ComputeDesiredSize(float) const
{
	FVector2D MaxSize(0.0f, 0.0f);
	for (int32 ChildIndex = 0; ChildIndex < Children.Num(); ++ChildIndex)
	{
		const FLGATimelineTrackAreaSlot& CurChild = Children[ChildIndex];

		const EVisibility ChildVisibilty = CurChild.GetWidget()->GetVisibility();
		if (ChildVisibilty != EVisibility::Collapsed)
		{
			FVector2D ChildDesiredSize = CurChild.GetWidget()->GetDesiredSize();
			MaxSize.X = FMath::Max(MaxSize.X, ChildDesiredSize.X);
			MaxSize.Y = FMath::Max(MaxSize.Y, ChildDesiredSize.Y);
		}
	}

	return MaxSize;
}

FChildren* SLGATimelineTrackArea::GetChildren()
{
	return &Children;
}

int32 SLGATimelineTrackArea::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// paint the child widgets
	FArrangedChildren ArrangedChildren(EVisibility::Visible);
	ArrangeChildren(AllottedGeometry, ArrangedChildren);

	const FPaintArgs NewArgs = Args.WithNewParent(this);

	for (int32 ChildIndex = 0; ChildIndex < ArrangedChildren.Num(); ++ChildIndex)
	{
		FArrangedWidget& CurWidget = ArrangedChildren[ChildIndex];
		FSlateRect ChildClipRect = MyCullingRect.IntersectionWith(CurWidget.Geometry.GetLayoutBoundingRect());
		const int32 ThisWidgetLayerId = CurWidget.Widget->Paint(NewArgs, CurWidget.Geometry, ChildClipRect, OutDrawElements, LayerId + 2, InWidgetStyle, bParentEnabled);

		LayerId = FMath::Max(LayerId, ThisWidgetLayerId);
	}

	return LayerId;
}

void SLGATimelineTrackArea::UpdateHoverStates(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

}

FReply SLGATimelineTrackArea::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	TSharedPtr<FLGATimeSliderController> TimeSliderController = WeakTimeSliderController.Pin();
	if (TimeSliderController.IsValid())
	{
		WeakOutliner.Pin()->ClearSelection();
		WeakModel.Pin()->ClearDetailsView();

		TimeSliderController->OnMouseButtonDown(*this, MyGeometry, MouseEvent);
	}

	return FReply::Unhandled();
}

FReply SLGATimelineTrackArea::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	TSharedPtr<FLGATimeSliderController> TimeSliderController = WeakTimeSliderController.Pin();
	if (TimeSliderController.IsValid())
	{
		return TimeSliderController->OnMouseButtonUp(*this, MyGeometry, MouseEvent);
	}

	return FReply::Unhandled();
}

FReply SLGATimelineTrackArea::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UpdateHoverStates(MyGeometry, MouseEvent);

	TSharedPtr<FLGATimeSliderController> TimeSliderController = WeakTimeSliderController.Pin();
	if (TimeSliderController.IsValid())
	{
		FReply Reply = TimeSliderController->OnMouseMove(*this, MyGeometry, MouseEvent);

		// Handle right click scrolling on the track area
		if (Reply.IsEventHandled())
		{
			if (MouseEvent.IsMouseButtonDown(EKeys::RightMouseButton) && HasMouseCapture())
			{
				WeakOutliner.Pin()->ScrollByDelta(-MouseEvent.GetCursorDelta().Y);
			}
		}

		return Reply;
	}

	return FReply::Unhandled();
}

FReply SLGATimelineTrackArea::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	TSharedPtr<FLGATimeSliderController> TimeSliderController = WeakTimeSliderController.Pin();
	if (TimeSliderController.IsValid())
	{
		FReply Reply = TimeSliderController->OnMouseWheel(*this, MyGeometry, MouseEvent);
		if (Reply.IsEventHandled())
		{
			return Reply;
		}

		const float ScrollAmount = -MouseEvent.GetWheelDelta() * GetGlobalScrollAmount();
		WeakOutliner.Pin()->ScrollByDelta(ScrollAmount);

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

void SLGATimelineTrackArea::OnMouseLeave(const FPointerEvent& MouseEvent)
{
}

FCursorReply SLGATimelineTrackArea::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	if (CursorEvent.IsMouseButtonDown(EKeys::RightMouseButton) && HasMouseCapture())
	{
		return FCursorReply::Cursor(EMouseCursor::GrabHandClosed);
	}
	else
	{
		TSharedPtr<FLGATimeSliderController> TimeSliderController = WeakTimeSliderController.Pin();
		if (TimeSliderController.IsValid())
		{
			return TimeSliderController->OnCursorQuery(SharedThis(this), MyGeometry, CursorEvent);
		}
	}

	return FCursorReply::Unhandled();
}

void SLGATimelineTrackArea::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	CachedGeometry = AllottedGeometry;

	for (int32 Index = 0; Index < Children.Num();)
	{
		if (!StaticCastSharedRef<SWeakWidget>(Children[Index].GetWidget())->ChildWidgetIsValid())
		{
			Children.RemoveAt(Index);
		}
		else
		{
			++Index;
		}
	}
}
