// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorViewportClient.h"
#include "Editor/EditorEngine.h"
//#include "Editor/UnrealEd/Private/Editor/ActorPositioning.h"
#include "Engine/Selection.h"
#include "EngineUtils.h"
#include "ImageUtils.h"
#include "ObjectTools.h"
#include "ScopedTransaction.h"
#include "SnappingUtils.h"
#include "LegoAbilityBlueprint.h" 
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorSettings.h"
#include "Actions/LGAAction.h"
#include "Editor/ActorPositioning.h"
#include "Timeline/LGATimelineModel.h"
#include "Timeline/LGATimelinePreviewer.h"

#include "Camera/CameraModifier_CameraShake.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Camera/CameraShakeBase.h"
#include "SceneView.h"

extern UNREALED_API UEditorEngine* GEditor;

FLegoAbilityEditorViewportClient::FLegoAbilityEditorViewportClient(FPreviewScene* InPreviewScene, TWeakPtr<FLegoAbilityEditor> InAbilityEditor, const TWeakPtr<SEditorViewport>& InEditorViewportWidget)
	: FEditorViewportClient(nullptr, InPreviewScene, InEditorViewportWidget)
	, m_CaptureThumbnail(false)
	, AbilityEditor(InAbilityEditor)
	, CameraShakePreviewer(InPreviewScene->GetWorld())
{
	check(AbilityEditor.IsValid());
	ViewFOV = FMath::Clamp(AbilityEditor.Pin()->GetEditorSettings().FOV, 70.0f, 180.0f);

	// DrawHelper set up
	DrawHelper.PerspectiveGridSize = HALF_WORLD_MAX1;
	DrawHelper.AxesLineThickness = 0.0f;
	DrawHelper.bDrawGrid = true;

	EngineShowFlags.SetEditor(false);
	EngineShowFlags.ScreenSpaceReflections = 1;
	EngineShowFlags.AmbientOcclusion = 1;
	EngineShowFlags.SetSnap(0);

	SetRealtime(true);

	EngineShowFlags.DisableAdvancedFeatures();
	EngineShowFlags.SetSeparateTranslucency(true);
	EngineShowFlags.SetCompositeEditorPrimitives(true);
	EngineShowFlags.SetParticles(true);

	if (UWorld* PreviewWorld = PreviewScene->GetWorld())
	{
		PreviewWorld->bAllowAudioPlayback = !AbilityEditor.Pin()->GetEditorSettings().bMuteAudio;
	}

	bCameraFollow = false;

	CameraShakePreviewer.RegisterViewModifier(this, true);
}

FLegoAbilityEditorViewportClient::~FLegoAbilityEditorViewportClient()
{
}

void FLegoAbilityEditorViewportClient::Draw(FViewport* InViewport, FCanvas* Canvas)
{
	FEditorViewportClient::Draw(InViewport, Canvas);
	
	if (m_CaptureThumbnail)
	{
		if (ULegoAbilityBlueprint* AbilityBP = AbilityEditor.Pin()->GetAbilityBlueprint())
		{
			int32 SrcWidth = InViewport->GetSizeXY().X;
			int32 SrcHeight = InViewport->GetSizeXY().Y;

			// Read the contents of the viewport into an array.
			TArray<FColor> OrigBitmap;
			if (InViewport->ReadPixels(OrigBitmap))
			{
				check(OrigBitmap.Num() == SrcWidth * SrcHeight);

				//pin to smallest value
				int32 CropSize = FMath::Min<uint32>(SrcWidth, SrcHeight);
				//pin to max size
				int32 ScaledSize = FMath::Min<uint32>(ThumbnailTools::DefaultThumbnailSize, CropSize);

				//calculations for cropping
				TArray<FColor> CroppedBitmap;
				CroppedBitmap.AddUninitialized(CropSize*CropSize);
				//Crop the image
				int32 CroppedSrcTop = (SrcHeight - CropSize) / 2;
				int32 CroppedSrcLeft = (SrcWidth - CropSize) / 2;
				for (int32 Row = 0; Row < CropSize; ++Row)
				{
					//Row*Side of a row*byte per color
					int32 SrcPixelIndex = (CroppedSrcTop + Row)*SrcWidth + CroppedSrcLeft;
					const void* SrcPtr = &(OrigBitmap[SrcPixelIndex]);
					void* DstPtr = &(CroppedBitmap[Row*CropSize]);
					FMemory::Memcpy(DstPtr, SrcPtr, CropSize * 4);
				}
				
				//Scale image down if needed
				TArray<FColor> ScaledBitmap;
				if (ScaledSize < CropSize)
				{
					FImageUtils::ImageResize(CropSize, CropSize, CroppedBitmap, ScaledSize, ScaledSize, ScaledBitmap, true);
				}
				else
				{
					//just copy the data over. sizes are the same
					ScaledBitmap = CroppedBitmap;
				}

				// Compress.
				FCreateTexture2DParameters Params;
				Params.bDeferCompression = true;
				AbilityBP->ThumbnailImage = FImageUtils::CreateTexture2D(ScaledSize, ScaledSize, ScaledBitmap, AbilityBP, TEXT("ThumbnailTexture"), RF_NoFlags, Params);
				AbilityBP->MarkPackageDirty();
			}
		}

		m_CaptureThumbnail = false;
	}
}

void FLegoAbilityEditorViewportClient::Tick(float DeltaSeconds)
{
	TSharedPtr<FLegoAbilityEditor> AbilityEditorPin = AbilityEditor.Pin();
	if (AbilityEditorPin.IsValid())
	{
		float FOV = FMath::Clamp(AbilityEditorPin->GetEditorSettings().FOV, 70.0f, 180.0f);

		// See if we need to update our FOV. 
		if (!FMath::IsNearlyEqual(FOV, ViewFOV))
		{
			ViewFOV = FOV;
			Invalidate();
		}

		if (AbilityEditorPin->GetAnimModel().IsValid())
		{
			FLGATimelinePreviewer* Previewer = AbilityEditorPin->GetAnimModel()->GetTimelinePreviewer().Get();
			if (Previewer)
			{
				float PreviewDeltaSeconds = DeltaSeconds;
				if (UWorld* PreviewWorld = PreviewScene->GetWorld())
				{
					float WorldDilation = PreviewWorld->GetWorldSettings()->GetEffectiveTimeDilation();
					PreviewDeltaSeconds *= WorldDilation;
				}

				if (AActor* PreviewActor = AbilityEditorPin->GetAbilityPreviewActor())
				{
					PreviewDeltaSeconds *= PreviewActor->GetActorTimeDilation();
				}

				Previewer->Tick(PreviewDeltaSeconds);
			}
		}

		PreviewScene->GetWorld()->bAllowAudioPlayback = !AbilityEditorPin->GetEditorSettings().bMuteAudio;

		FEditorViewportClient::Tick(DeltaSeconds);

		UpdateFollowCamera(DeltaSeconds);

		TickWorld(DeltaSeconds);

		CameraShakePreviewer.Update(DeltaSeconds, true);
	}
	else
	{
		FEditorViewportClient::Tick(DeltaSeconds);
	}

}


void FLegoAbilityEditorViewportClient::UpdateFollowCamera(float DeltaTime /*= 0.f*/)
{
	if (!bCameraFollow)
	{
		return;
	}

	TSharedPtr<FLegoAbilityEditor> AbilityEditorPin = AbilityEditor.Pin();
	if (AbilityEditorPin.IsValid() && AbilityEditorPin->GetAbilityPreviewActor())
	{
		AActor* PreviewActor = AbilityEditorPin->GetAbilityPreviewActor();

		// Check if the viewport is transitioning
		FViewportCameraTransform& ViewTransform = GetViewTransform();
		if (!ViewTransform.IsPlaying())
		{
			FMinimalViewInfo ActorViewInfo;
			PreviewActor->CalcCamera(DeltaTime, ActorViewInfo);
			
			// Post processing is handled by OverridePostProcessingSettings
			ViewFOV = ActorViewInfo.FOV;
			//AspectRatio = ActorViewInfo.AspectRatio;
			SetViewLocation(ActorViewInfo.Location);
			SetViewRotation(ActorViewInfo.Rotation);
		}
	}
}

bool FLegoAbilityEditorViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	bool handled = false;

	if (EventArgs.Key == EKeys::Escape)
	{
		GEditor->SelectNone(false, true, false);
		handled = true;
	}

	return FEditorViewportClient::InputKey(EventArgs) || handled;
}

bool FLegoAbilityEditorViewportClient::InputWidgetDelta(FViewport* InViewport, EAxisList::Type CurrentAxis, FVector& Drag, FRotator& Rot, FVector& Scale)
{
	bool handled = false;
	if (HasSelectedActionForWidget())
	{
		TArray<class ULGAAction*>& SelectedActions = AbilityEditor.Pin()->GetAnimModel()->GetSelectedActions();

		for (ULGAAction* Action : SelectedActions)
		{
			if (Action->NeedShowTransformWidget())
			{
				const FScopedTransaction Delta(NSLOCTEXT("UnrealEd", "Action Movement", "Action Movement"));

				if ((!bCameraFollow && GetCurrentWidgetAxis() != EAxisList::None) || bCameraFollow)
				{
					if (Action->InputWidgetDelta(AbilityEditor.Pin()->GetAbilityPreviewActor(), InViewport, CurrentAxis, Drag, Rot, Scale))
					{
						handled = true;
					}
				}
			}
		}

		if (handled)
		{
			return true;
		}
	}
	else if (HasSelectedSpawnActors() && CurrentAxis != EAxisList::None)
	{
		const FScopedTransaction Delta(NSLOCTEXT("UnrealEd", "Actor Movement", "Actor Movement"));
		for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
		{
			if (AActor* SelectedActor = Cast<AActor>(*It))
			{
				GEditor->ApplyDeltaToActor(SelectedActor, true, &Drag, &Rot, &Scale);
				handled = true;
			}
		}

		return handled;
	}

	return FEditorViewportClient::InputWidgetDelta(InViewport, CurrentAxis, Drag, Rot, Scale) || handled;
}

void FLegoAbilityEditorViewportClient::ProcessClick(class FSceneView& View, class HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY)
{
	if (HitProxy && HitProxy->IsA(HActor::StaticGetType()))
	{
		HActor* ActorProxy = (HActor*)HitProxy;
		if (AbilityEditor.IsValid())
		{
			AActor* PreviewActor = AbilityEditor.Pin()->GetAbilityPreviewActor();
			
			if (PreviewActor == ActorProxy->Actor)
			{
				GEditor->SelectNone(false, true, false);
				GEditor->SelectActor(ActorProxy->Actor, true, true, true);
				SetWidgetMode(UE::Widget::EWidgetMode::WM_Translate);
				return;
			}
		}
	}

	FEditorViewportClient::ProcessClick(View, HitProxy, Key, Event, HitX, HitY);
}

void FLegoAbilityEditorViewportClient::TrackingStarted(const struct FInputEventState& InInputState, bool bIsDragging, bool bNudge)
{
	if (HasSelectedSpawnActors() || HasSelectedActionForWidget())
	{
		GEditor->DisableDeltaModification(true);
	}

	FEditorViewportClient::TrackingStarted(InInputState, bIsDragging, bNudge);
}

void FLegoAbilityEditorViewportClient::TrackingStopped()
{
	if (HasSelectedSpawnActors() || HasSelectedActionForWidget())
	{
		GEditor->DisableDeltaModification(false);
	}

	FEditorViewportClient::TrackingStopped();
}

UE::Widget::EWidgetMode FLegoAbilityEditorViewportClient::GetWidgetMode() const
{
	if (!HasSelectedSpawnActors() && !HasSelectedActionForWidget())
	{
		return UE::Widget::EWidgetMode::WM_None;
	}

	return FEditorViewportClient::GetWidgetMode();
}

FVector FLegoAbilityEditorViewportClient::GetWidgetLocation() const
{
	if (HasSelectedActionForWidget())
	{
		TArray<class ULGAAction*>& SelectedActions = AbilityEditor.Pin()->GetAnimModel()->GetSelectedActions();

		for (ULGAAction* Action : SelectedActions)
		{
			if (Action->NeedShowTransformWidget())
			{
				return Action->GetWidgetLocation(AbilityEditor.Pin()->GetAbilityPreviewActor());
			}
		}
	}
	else if (HasSelectedSpawnActors())
	{
		FVector WidgetLocation = FVector::ZeroVector;
		int32 TotalSelectedActors = 0;
		for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
		{
			if (AActor* SelectedActor = Cast<AActor>(*It))
			{
				WidgetLocation += SelectedActor->GetActorLocation();
				++TotalSelectedActors;
			}
		}

		if (TotalSelectedActors != 0)
		{
			WidgetLocation *= (1.0f / (float)TotalSelectedActors);
		}

		return WidgetLocation;
	}

	return FEditorViewportClient::GetWidgetLocation();
}


FMatrix FLegoAbilityEditorViewportClient::GetWidgetCoordSystem() const
{
	if (HasSelectedActionForWidget() && GetWidgetCoordSystemSpace() == ECoordSystem::COORD_Local)
	{
		TArray<class ULGAAction*>& SelectedActions = AbilityEditor.Pin()->GetAnimModel()->GetSelectedActions();

		for (ULGAAction* Action : SelectedActions)
		{
			if (Action->NeedShowTransformWidget())
			{	
				return FQuatRotationMatrix(Action->GetWidgetRotation(AbilityEditor.Pin()->GetAbilityPreviewActor()).Quaternion());
			}
		}
	}

	return FEditorViewportClient::GetWidgetCoordSystem();
}

FTransform FLegoAbilityEditorViewportClient::GetWorldPositionForMouse(int32 MouseX, int32 MouseY)
{
	Viewport->InvalidateHitProxy();

	FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
		Viewport,
		GetScene(),
		EngineShowFlags)
		.SetRealtimeUpdate(IsRealtime()));
	FSceneView* View = CalcSceneView(&ViewFamily);
	FViewportCursorLocation Cursor(View, this, MouseX, MouseY);

	HHitProxy* HitProxy = Viewport->GetHitProxy(Cursor.GetCursorPos().X, Cursor.GetCursorPos().Y);

	const FActorPositionTraceResult TraceResult = FActorPositioning::TraceWorldForPositionWithDefault(Cursor, *View);

	GEditor->UnsnappedClickLocation = TraceResult.Location;
	GEditor->ClickLocation = TraceResult.Location;
	GEditor->ClickPlane = FPlane(TraceResult.Location, TraceResult.SurfaceNormal);

	// Snap the new location if snapping is enabled
	FSnappingUtils::SnapPointToGrid(GEditor->ClickLocation, FVector::ZeroVector);

	return FTransform(GEditor->ClickLocation);
}

bool FLegoAbilityEditorViewportClient::HasSelectedSpawnActors() const
{
	if (AbilityEditor.IsValid())
	{
		AActor* PreviewActor = AbilityEditor.Pin()->GetAbilityPreviewActor();
		for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
		{
			if (PreviewActor == (Cast<AActor>(*It)))
			{
				return true;
			}
		}
	}

	return false;
}


bool FLegoAbilityEditorViewportClient::HasSelectedActionForWidget() const
{
	if (AbilityEditor.IsValid())
	{
		TArray<class ULGAAction*>& SelectedActions = AbilityEditor.Pin()->GetAnimModel()->GetSelectedActions();

		for (ULGAAction* Action : SelectedActions)
		{
			if (Action->IsValidLowLevel() && Action->NeedShowTransformWidget())
			{
				return true;
			}
		}
	}

	return false;
}

void FLegoAbilityEditorViewportClient::CaptureThumbnail()
{
	if (AbilityEditor.IsValid())
	{
		m_CaptureThumbnail = true;
	}
}

void FLegoAbilityEditorViewportClient::TickWorld(float DeltaSeconds)
{
	UWorld* PreviewWorld = PreviewScene->GetWorld();
	if (!PreviewWorld->bBegunPlay)
	{
		for (FActorIterator It(PreviewWorld); It; ++It)
		{
			It->DispatchBeginPlay();
		}
		PreviewWorld->bBegunPlay = true;
	}

	PreviewWorld->Tick(LEVELTICK_All, DeltaSeconds);
}

void FLegoAbilityEditorViewportClient::SetFollowPreview(bool bFollow)
{
	bCameraFollow = bFollow;
}



/**
 *  Camera Shake Previewer
 */

FLegoAbilityCameraShakePreviewer::FLegoAbilityCameraShakePreviewer(UWorld* InWorld)
	: World(InWorld)
	, LastDeltaTime(0.f)
	, LastLocationModifier(FVector::ZeroVector)
	, LastRotationModifier(FRotator::ZeroRotator)
	, LastFOVModifier(0.f)
{
	// Handle camera shakes being recompiled.
	FCoreUObjectDelegates::OnObjectsReplaced.AddRaw(this, &FLegoAbilityCameraShakePreviewer::OnObjectsReplaced);
}

FLegoAbilityCameraShakePreviewer::~FLegoAbilityCameraShakePreviewer()
{
	//if (!ensureMsgf(RegisteredViewportClients.Num() == 0, TEXT("Forgot to call UnRegisterViewModifiers!")))
	{
		UnRegisterViewModifiers();
	}

	FCoreUObjectDelegates::OnObjectsReplaced.RemoveAll(this);
}

UCameraShakeBase* FLegoAbilityCameraShakePreviewer::AddCameraShake(const FLegoCameraShakePreviewerAddParams& Params)
{
	FCameraShakeBaseStartParams StartParams;
	StartParams.Scale = Params.Scale;
	StartParams.PlaySpace = Params.PlaySpace;
	StartParams.UserPlaySpaceRot = Params.UserPlaySpaceRot;
	StartParams.DurationOverride = Params.DurationOverride;

	UCameraShakeBase* NewShake = NewObject<UCameraShakeBase>(World, Params.ShakeClass);
	NewShake->StartShake(StartParams);

	ActiveShakes.Add({ StartParams, NewShake, Params.SourceComponent, Params.GlobalStartTime });

	return NewShake;
}

void FLegoAbilityCameraShakePreviewer::RemoveCameraShake(UCameraShakeBase* ShakeInstance)
{
	const bool bImmediately = true;
	for (int32 i = ActiveShakes.Num() - 1; i >= 0; --i)
	{
		FPreviewCameraShakeInfo& ActiveShake = ActiveShakes[i];
		if (ActiveShake.ShakeInstance == ShakeInstance)
		{
			ActiveShake.ShakeInstance->StopShake(bImmediately);
			ActiveShake.ShakeInstance->TeardownShake();
			ActiveShakes.RemoveAt(i, 1);
			break;
		}
	}
}

void FLegoAbilityCameraShakePreviewer::RemoveAllCameraShakesFromSource(const UCameraShakeSourceComponent* SourceComponent)
{
	int32 NumRemoved = 0;
	const bool bImmediately = true;
	for (int32 i = ActiveShakes.Num() - 1; i >= 0; --i)
	{
		FPreviewCameraShakeInfo& ActiveShake = ActiveShakes[i];
		if (ActiveShake.SourceComponent.Get() == SourceComponent && ActiveShake.ShakeInstance != nullptr)
		{
			ActiveShake.ShakeInstance->StopShake(bImmediately);
			ActiveShake.ShakeInstance->TeardownShake();
			ActiveShakes.RemoveAt(i, 1);
			++NumRemoved;
		}
	}
}

void FLegoAbilityCameraShakePreviewer::RemoveAllCameraShakes()
{
	const bool bImmediately = true;
	for (FPreviewCameraShakeInfo& ActiveShake : ActiveShakes)
	{
		if (ActiveShake.ShakeInstance)
		{
			ActiveShake.ShakeInstance->StopShake(bImmediately);
			ActiveShake.ShakeInstance->TeardownShake();
		}
	}
	ActiveShakes.Empty();
}

void FLegoAbilityCameraShakePreviewer::GetActiveCameraShakes(TArray<FActiveCameraShakeInfo>& ActiveCameraShakes) const
{
	for (const FPreviewCameraShakeInfo& ActiveShake : ActiveShakes)
	{
		FActiveCameraShakeInfo ShakeInfo;
		ShakeInfo.ShakeInstance = ActiveShake.ShakeInstance;
		ShakeInfo.ShakeSource = ActiveShake.SourceComponent;
		ActiveCameraShakes.Add(ShakeInfo);
	}
}

void FLegoAbilityCameraShakePreviewer::Update(float DeltaTime, bool bIsPlaying)
{
	LastDeltaTime = DeltaTime;
	LastScrubTime.Reset();

	if (!bIsPlaying)
	{
		ResetModifiers();
	}
}

void FLegoAbilityCameraShakePreviewer::Scrub(float ScrubTime)
{
	LastDeltaTime.Reset();
	LastScrubTime = ScrubTime;

	ResetModifiers();
}

void FLegoAbilityCameraShakePreviewer::ResetModifiers()
{
	LastLocationModifier = FVector::ZeroVector;
	LastRotationModifier = FRotator::ZeroRotator;
	LastFOVModifier = 0.f;

	LastPostProcessSettings.Reset();
	LastPostProcessBlendWeights.Reset();
}

void FLegoAbilityCameraShakePreviewer::ModifyView(FEditorViewportViewModifierParams& Params)
{
	OnModifyView(Params);
}

void FLegoAbilityCameraShakePreviewer::OnModifyView(FEditorViewportViewModifierParams& Params)
{
	FMinimalViewInfo& InOutPOV(Params.ViewInfo);
	const FMinimalViewInfo OriginalPOV(Params.ViewInfo);

	// This is a simpler version of what UCameraModifier_CameraShake does, with extra
	// support for scrubbing.
	if (LastDeltaTime.IsSet() || LastScrubTime.IsSet())
	{
		LastPostProcessSettings.Reset();
		LastPostProcessBlendWeights.Reset();

		for (FPreviewCameraShakeInfo& ActiveShake : ActiveShakes)
		{
			if (ActiveShake.ShakeInstance != nullptr)
			{
				float CurShakeAlpha = 1.f;

				if (ActiveShake.SourceComponent.IsValid())
				{
					const UCameraShakeSourceComponent* SourceComponent = ActiveShake.SourceComponent.Get();
					const float AttenuationFactor = SourceComponent->GetAttenuationFactor(InOutPOV.Location);
					CurShakeAlpha *= AttenuationFactor;
				}

				if (LastDeltaTime.IsSet())
				{
					ActiveShake.ShakeInstance->UpdateAndApplyCameraShake(LastDeltaTime.GetValue(), CurShakeAlpha, InOutPOV);
				}
				else if (LastScrubTime.IsSet())
				{
					float RelativeScrubTime = LastScrubTime.GetValue() - ActiveShake.StartTime;
					ActiveShake.ShakeInstance->ScrubAndApplyCameraShake(RelativeScrubTime, CurShakeAlpha, InOutPOV);
				}

				if (InOutPOV.PostProcessBlendWeight > 0.f)
				{
					Params.AddPostProcessBlend(InOutPOV.PostProcessSettings, InOutPOV.PostProcessBlendWeight);
					LastPostProcessSettings.Add(InOutPOV.PostProcessSettings);
					LastPostProcessBlendWeights.Add(InOutPOV.PostProcessBlendWeight);
				}
				InOutPOV.PostProcessSettings = FPostProcessSettings();
				InOutPOV.PostProcessBlendWeight = 0.f;
			}
		}

		LastLocationModifier = InOutPOV.Location - OriginalPOV.Location;
		LastRotationModifier = InOutPOV.Rotation - OriginalPOV.Rotation;
		LastFOVModifier = InOutPOV.FOV - OriginalPOV.FOV;

		LastDeltaTime.Reset();
		LastScrubTime.Reset();

		// Delete any obsolete shakes.
		for (int32 i = ActiveShakes.Num() - 1; i >= 0; i--)
		{
			const FPreviewCameraShakeInfo& ShakeInfo = ActiveShakes[i];
			if (ShakeInfo.ShakeInstance == nullptr || ShakeInfo.ShakeInstance->IsFinished() || ShakeInfo.SourceComponent.IsStale())
			{
				if (ShakeInfo.ShakeInstance != nullptr)
				{
					ShakeInfo.ShakeInstance->TeardownShake();
				}

				ActiveShakes.RemoveAt(i, 1);
			}
		}
	}
	else
	{
		InOutPOV.Location += LastLocationModifier;
		InOutPOV.Rotation += LastRotationModifier;
		InOutPOV.FOV += LastFOVModifier;

		for (int32 PPIndex = 0; PPIndex < LastPostProcessSettings.Num(); ++PPIndex)
		{
			Params.AddPostProcessBlend(LastPostProcessSettings[PPIndex], LastPostProcessBlendWeights[PPIndex]);
		}
	}
}


void FLegoAbilityCameraShakePreviewer::RegisterViewModifier(FLegoAbilityEditorViewportClient* ViewportClient, bool bIgnoreDuplicateRegistration)
{
	if (RegisteredViewportClients.Contains(ViewportClient))
	{
		// Already registered to this viewport.
		ensureMsgf(bIgnoreDuplicateRegistration, TEXT("Given viewport is already registered."));
		return;
	}

	RegisteredViewportClients.Add(ViewportClient);
	ViewportClient->ViewModifiers.AddRaw(this, &FLegoAbilityCameraShakePreviewer::OnModifyView);
}


void FLegoAbilityCameraShakePreviewer::UnRegisterViewModifiers()
{
	for (FLegoAbilityEditorViewportClient* ViewportClient : RegisteredViewportClients)
	{
		ViewportClient->ViewModifiers.RemoveAll(this);
	}
	RegisteredViewportClients.Reset();
}

void FLegoAbilityCameraShakePreviewer::UnRegisterViewModifier(FLegoAbilityEditorViewportClient* ViewportClient)
{
	const int32 NumRemoved = RegisteredViewportClients.Remove(ViewportClient);
	if (ensureMsgf(NumRemoved > 0, TEXT("The given viewport client wasn't registered.")))
	{
		ViewportClient->ViewModifiers.RemoveAll(this);
	}
}


void FLegoAbilityCameraShakePreviewer::AddReferencedObjects(FReferenceCollector& Collector)
{
	for (FPreviewCameraShakeInfo& ActiveShake : ActiveShakes)
	{
		if (ActiveShake.ShakeInstance)
		{
			Collector.AddReferencedObject(ActiveShake.ShakeInstance);
		}
	}
}

void FLegoAbilityCameraShakePreviewer::OnObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	const bool bImmediately = true;
	for (int32 i = ActiveShakes.Num() - 1; i >= 0; i--)
	{
		FPreviewCameraShakeInfo& ActiveShake = ActiveShakes[i];
		if (UObject* const* NewShakeInstance = ReplacementMap.Find(ActiveShake.ShakeInstance))
		{
			// If a camera shake gets recompiled, stop the old version, and start the
			// new version with the same parameters.
			ActiveShake.ShakeInstance->StopShake(bImmediately);
			ActiveShake.ShakeInstance->TeardownShake();

			ActiveShake.ShakeInstance = Cast<UCameraShakeBase>(*NewShakeInstance);
			if (ensure(ActiveShake.ShakeInstance))
			{
				ActiveShake.ShakeInstance->StartShake(ActiveShake.StartParams);
			}
		}
	}
}
