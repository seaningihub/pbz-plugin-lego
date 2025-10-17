// Copyright S-Game, Inc. All Rights Reserved.


#include "Actions/LGAAction_CameraShakeBase.h"
#include "LGATimeline.h"

UCameraShakeBase* ULGAAction_CameraShakeBase::AddCameraShake(const FLegoCameraShakePreviewerAddParams& Params)
{
	UCameraShakeBase* Result = nullptr;

#if WITH_EDITORONLY_DATA
	if (ULGATimeline* Timeline = GetTimeline(); Timeline && Params.ShakeClass)
	{
		Result = Timeline->AddCameraShake.Execute(Params);
	}
#endif

	return Result;
}

void ULGAAction_CameraShakeBase::RemoveCameraShake(UCameraShakeBase* ShakeInstance)
{
#if WITH_EDITORONLY_DATA
	if (ULGATimeline* Timeline = GetTimeline(); Timeline && ShakeInstance)
	{
		Timeline->RemoveCameraShake.Execute(ShakeInstance);
	}
#endif
}

float ULGAAction_CameraShakeBase::GetCameraShakeDuration(const TSubclassOf<UCameraShakeBase>& ShakeClass)
{
	if (ShakeClass)
	{
		return ShakeClass.GetDefaultObject()->GetCameraShakeDuration().Get();
	}
	return 0.0f;
}
