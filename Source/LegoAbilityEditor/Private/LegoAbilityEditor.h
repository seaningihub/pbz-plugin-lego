// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "BlueprintEditor.h"
#include "GameplayAbilitySpec.h"
#include "LGATimeline.h"
#include "CurveEditor.h"

class FLGATimelineModel;
class UAbilitySystemComponent;
class ULegoAbilityBlueprint;
class ULegoAbilityBlueprintGeneratedClass;
class ULegoAbilityEditorSettings;
class FLegoAbilityEditorToolbar;
class SViewportTabBody;
struct FCurveEditInfo;
class SLGATimelineCurveEditor;
class FLegoAbilityEditorViewportClient;

DECLARE_LOG_CATEGORY_EXTERN(LogLegoAbilityEditor, Log, All);

/**
 * Lego ability asset editor (extends Blueprint editor)
 */
class FLegoAbilityEditor : public FBlueprintEditor
{
public:
	FLegoAbilityEditor();
	virtual ~FLegoAbilityEditor();

	/** Initializes an instance of the Editor. */
	void InitLegoAbilityEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, const TArray<UBlueprint*>& InBlueprints);

	// IToolkit interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	// End of IToolkit interface

	/** Returns the AnimModel of LegoAbility. */
	TSharedPtr<FLGATimelineModel>& GetAnimModel() { return AnimModel; }

	/** Returns a pointer to the Lego Ability Blueprint object we are currently editing. */
	ULegoAbilityBlueprint* GetAbilityBlueprint() const;

	/** Returns a pointer to the Blueprint Generated Class of the Lego Ability Blueprint object we are currently editing. */
	ULegoAbilityBlueprintGeneratedClass* GetAbilityBlueprintGeneratedClass() const;

	/** Changes the currently viewed timeline to the new one*/
	void SetCurrentTimeline(ULGATimeline* Timeline);

	bool IsCurrentTimelineValid() const;

	/** Returns the name of the currently viewed timeline. */
	FName GetCurrentTimelineName() const { return CurrentTimeline.IsValid() ? CurrentTimeline->GetFName() : TEXT("NullTimeline"); }

	bool IsCurrentTimelineLocal();

	//~ Begin FBlueprintEditor Interface
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	//~ End FBlueprintEditor Interface

	/* Returns the dirty brush for a given mode. */
	const FSlateBrush* GetDirtyImageForMode(FName Mode) const;

	/* Returns the toolbar builder associated with this editor. */
	TSharedPtr<FLegoAbilityEditorToolbar> GetAbilityToolbarBuilder() { return ToolbarBuilder; }

	/* Returns a Const version of the Ability Editor Settings. */
	static ULegoAbilityEditorSettings& GetEditorSettings();

	/* Whether or not to allow Arrow Components on the Preview Actor. */
	FORCEINLINE bool IsDrawingArrowComponent() const { return m_DrawArrowComponent; }

	/* Whether or not to allow Camera Components on the Preview Actor. */
	FORCEINLINE bool IsDrawingCameraComponent() const { return m_DrawCameraComponent; }

	void SetPreviewAsset(const FAssetData& PreviewAsset);

	/* Sets the Viewport Widget. */
	void SetViewportTabBody(TWeakPtr<SViewportTabBody>& InViewportTabBody) { ViewportTabBody = InViewportTabBody; }

	/* Returns the Tab Icon of the Ability Editor. */
	virtual const FSlateBrush* GetDefaultTabIcon() const override;

	/* Get our Preview Actor. */
	AActor* GetAbilityPreviewActor() const { return PreviewActor.Get(); }

	/* Respawns the Preview Actor into its original state. */
	void ResetPreviewActor();

	/* Notify when user entering timeline mode. */
	void OnEnteringTimelineMode();

	void EditCurves(const FCurveEditInfo& InCurveInfo);

	FLegoAbilityEditorViewportClient* GetViewportClient();

public:
	/** Delegate called when entering timeline mode */
	DECLARE_EVENT(FLegoAbilityEditor, FOnEnterTimelineMode)
	FOnEnterTimelineMode OnEnterTimelineMode;

	/** Delegate called when a undo/redo transaction happens */
	DECLARE_EVENT(FLegoAbilityEditor, FOnAbilityBlueprintTransaction)
	FOnAbilityBlueprintTransaction OnAbilityBlueprintTransaction;

protected:
	virtual void PostUndo(bool bSuccessful) override;
	virtual void PostRedo(bool bSuccessful) override;
	virtual void RegisterApplicationModes(const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode, bool bNewlyCreated = false) override;

private:
	/** Menu Extension Helper. */
	void ExtendMenu();

	/** Toolbar Extension Helper. */
	void ExtendToolbar();

	/** Bind all Commands needed by this Editor. */
	void BindCommands();

	AActor* InternalSpawnActor(UClass* ActorClass, const FTransform& Transform = FTransform::Identity);

	/** Creates the Preview Actor. */
	void SpawnPreviewActor(const FTransform& initTransform = FTransform::Identity);

	/** Toggles Arrow Component. */
	void ToggleDrawArrowComponent();

	/** Toggles Camera Component. */
	void ToggleDrawCameraComponent();

	/** Captures the current Viewport image as thumbnail. */
	void CaptureThumbnail();

	void TogglePlay();

	/** Add/Remove delegate when timeline changed */
	void RegisterDelegatesForTimeline();
	void UnregisterDelegatesForTimeline();

	void OnTimelinePropertyChanged();
	void OnTimelineTransactionApplied();

	/** Brush to use as a dirty marker for assets */
	const FSlateBrush* AssetDirtyBrush;
	
	// Our Tab Icon
	const FSlateBrush* TabIcon;

	// Extenders
	TSharedPtr<FExtender> ToolbarExtender;
	TSharedPtr<FExtender> MenuExtender;

	/** The toolbar builder associated with this editor */
	TSharedPtr<FLegoAbilityEditorToolbar> ToolbarBuilder;

	/** The currently viewed timeline. */
	TWeakObjectPtr<ULGATimeline> CurrentTimeline;

	/** The handle of currently activated ability */
	FGameplayAbilitySpecHandle AbilitySpecHandle;

	/** Delegate handle for timeline property changed */
	FDelegateHandle PropertyChangedDelegateHandle;

	/** Delegate handle for timeline transaction applied */
	FDelegateHandle TransactionAppliedDelegateHandle;

	// Editor Settings
	static ULegoAbilityEditorSettings* EditorSettings;

	// Editor Viewport Tab
	TWeakPtr<SViewportTabBody> ViewportTabBody;

	// Class of Preview Actor
	TWeakObjectPtr<UClass> PreviewActorClass;

	// Preview Actor
	TWeakObjectPtr<AActor> PreviewActor;
	FTransform PreviewActorSavedTransform;


	// Various UI Options for our Ability Editor
	bool m_DrawArrowComponent;
	bool m_DrawCameraComponent;

	// anim model
	TSharedPtr<FLGATimelineModel> AnimModel;

	int32 CurrentProfileIndex;

	/** The timeline's curves that are currently being edited */
	TWeakPtr<SDockTab> TimelineCurveDocumentTab;

	/** The anim sequence curve editor */
	TWeakPtr<SLGATimelineCurveEditor> CurveEditor;
};