// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "EditorViewportClient.h"
#include "Camera/CameraShakeBase.h"

struct FLegoCameraShakePreviewerAddParams;
class FLegoAbilityEditor;
class FLegoAbilityEditorViewportClient;
class UCameraShakeBase;
struct FActiveCameraShakeInfo;

class FLegoAbilityCameraShakePreviewer : public FGCObject
{
public:
	using FViewportFilter = TFunctionRef<bool(FLegoAbilityEditorViewportClient*)>;

	FLegoAbilityCameraShakePreviewer(UWorld* InWorld);
	~FLegoAbilityCameraShakePreviewer();

	UWorld* GetWorld() const { return World; }

	void ModifyView(FEditorViewportViewModifierParams& Params);

	void UnRegisterViewModifiers();

	void RegisterViewModifier(FLegoAbilityEditorViewportClient* ViewportClient, bool bIgnoreDuplicateRegistration = false);
	void UnRegisterViewModifier(FLegoAbilityEditorViewportClient* ViewportClient);

	void Update(float DeltaTime, bool bIsPlaying);
	void Scrub(float ScrubTime);

	UCameraShakeBase* AddCameraShake(const FLegoCameraShakePreviewerAddParams& Params);
	void RemoveCameraShake(UCameraShakeBase* ShakeInstance);
	void RemoveAllCameraShakesFromSource(const UCameraShakeSourceComponent* SourceComponent);
	void RemoveAllCameraShakes();

	int32 NumActiveCameraShakes() const { return ActiveShakes.Num(); }
	void GetActiveCameraShakes(TArray<FActiveCameraShakeInfo>& ActiveCameraShakes) const;

	void OnObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);

private:
	// FGCObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override { return TEXT("FLegoAbilityCameraShakePreviewer"); }

private:
	void OnModifyView(FEditorViewportViewModifierParams& Params);

	void ResetModifiers();

private:
	UWorld* World;

	TArray<FLegoAbilityEditorViewportClient*> RegisteredViewportClients;

	struct FPreviewCameraShakeInfo
	{
		FCameraShakeBaseStartParams StartParams;
		TObjectPtr<UCameraShakeBase> ShakeInstance;
		TWeakObjectPtr<const UCameraShakeSourceComponent> SourceComponent;
		float StartTime;
	};
	TArray<FPreviewCameraShakeInfo> ActiveShakes;

	TOptional<float> LastDeltaTime;
	TOptional<float> LastScrubTime;

	FVector LastLocationModifier;
	FRotator LastRotationModifier;
	float LastFOVModifier;

	TArray<FPostProcessSettings> LastPostProcessSettings;
	TArray<float> LastPostProcessBlendWeights;
};


class FLegoAbilityEditorViewportClient : public FEditorViewportClient
{
public:
	FLegoAbilityEditorViewportClient(FPreviewScene* InPreviewScene, TWeakPtr<FLegoAbilityEditor> InAbilityEditor, const TWeakPtr<SEditorViewport>& InEditorViewportWidget);
	virtual ~FLegoAbilityEditorViewportClient();

	virtual void Draw(FViewport* InViewport, FCanvas* Canvas) override;
	virtual void Tick(float DeltaSeconds) override;

	void UpdateFollowCamera(float DeltaTime = 0.f);

	virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;
	virtual bool InputWidgetDelta(FViewport* Viewport, EAxisList::Type CurrentAxis, FVector& Drag, FRotator& Rot, FVector& Scale) override;

	virtual void ProcessClick(class FSceneView& View, class HHitProxy* HitProxy, FKey Key, EInputEvent Event, uint32 HitX, uint32 HitY) override;

	virtual void TrackingStarted(const struct FInputEventState& InInputState, bool bIsDragging, bool bNudge) override;
	virtual void TrackingStopped() override;

	virtual UE::Widget::EWidgetMode GetWidgetMode() const override;
	virtual FVector GetWidgetLocation() const override;
	virtual FMatrix GetWidgetCoordSystem() const override;

	FTransform GetWorldPositionForMouse(int32 MouseX, int32 MouseY);
	bool HasSelectedSpawnActors() const;

	bool HasSelectedActionForWidget() const;
	
	void CaptureThumbnail();
	void TickWorld(float DeltaSeconds);

	void SetFollowPreview(bool bFollow);

	FLegoAbilityCameraShakePreviewer& GetCameraShakePreviewer() { return CameraShakePreviewer;  }

private:
	bool m_CaptureThumbnail;
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;

	bool bCameraFollow;

	FLegoAbilityCameraShakePreviewer CameraShakePreviewer;
};

