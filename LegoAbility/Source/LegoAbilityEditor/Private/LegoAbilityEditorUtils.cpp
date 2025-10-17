// Copyright S-Game, Inc. All Rights Reserved.


#include "LegoAbilityEditorUtils.h"

#include "LegoAbilityBlueprint.h"

FLGAActionEventHandle::FLGAActionEventHandle() : Event(nullptr)
{
}

FLGAActionEventHandle::FLGAActionEventHandle(FLGAActionEvent* Event) : Event(Event)
{
}

ULegoAbilityBlueprint* ULegoAbilityEditorUtils::ToLegoAbilityBlueprint(UBlueprint* Blueprint)
{
	return Cast<ULegoAbilityBlueprint>(Blueprint);
}

void ULegoAbilityEditorUtils::GetAbilityTimelines(ULegoAbilityBlueprint* Blueprint, TArray<ULGATimeline*>& Timelines)
{
	Timelines = Blueprint->AbilityTimelines;
}

ULGATimeline* ULegoAbilityEditorUtils::GetAbilityTimelineByName(ULegoAbilityBlueprint* Blueprint, FName TimelineName)
{
	ULGATimeline* Result = nullptr;
	if (Blueprint)
	{
		Result = Blueprint->GetTimelineByName(TimelineName, true);
	}

	return Result;
}

void ULegoAbilityEditorUtils::SetAbilityTimelines(ULegoAbilityBlueprint* Blueprint,
	const TArray<ULGATimeline*>& Timelines)
{
	Blueprint->AbilityTimelines = Timelines;
}

void ULegoAbilityEditorUtils::GetOverridenTimelines(ULegoAbilityBlueprint* Blueprint,
	TArray<FLGATimelineOverride>& Timelines)
{
	Timelines = Blueprint->AbilityTimelineOverrides;
}

void ULegoAbilityEditorUtils::SetOverridenTimelines(ULegoAbilityBlueprint* Blueprint,
	const TArray<FLGATimelineOverride>& Timelines)
{
	Blueprint->AbilityTimelineOverrides = Timelines;
}

void ULegoAbilityEditorUtils::GetTrackActionEvents(FLGAActionTrack Track, TArray<FLGAActionEventHandle>& ActionEvents)
{
	for (FLGAActionEvent* Event : Track.Actions)
	{
		ActionEvents.Emplace(Event);
	}
}

void ULegoAbilityEditorUtils::GetActionEventByHandle(const FLGAActionEventHandle& Handle, FLGAActionEvent& Event)
{
	Event = *Handle.Event;
}

void ULegoAbilityEditorUtils::SetActionEventByHandle(const FLGAActionEventHandle& Handle, const FLGAActionEvent& Event)
{
	*Handle.Event = Event;
}
