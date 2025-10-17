// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGAAction.h"
#include "LGAAction_MotionWarping_Base.generated.h"

class UMotionWarpingComponent;

UCLASS(Abstract, Blueprintable, meta = (DisplayName = "Motions Warping Base"))
class LEGOABILITY_API ULGAAction_MotionWarping_Base : public ULGAAction
{
	GENERATED_BODY()

public:
	virtual void OnBecomeRelevant(UMotionWarpingComponent* MotionWarpingComp, const UAnimSequenceBase* Animation, float StartTime, float EndTime);

public:
	ULGAAction_MotionWarping_Base();
};