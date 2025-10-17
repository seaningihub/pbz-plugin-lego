// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Animation/AnimInstance.h"
#include "AssetViewerSettings.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/PostProcessComponent.h"
#include "EditorReimportHandler.h"
#include "Editor/EditorPerProjectUserSettings.h"
#include "Engine/AssetManager.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/WorldSettings.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Materials/MaterialInstanceConstant.h"
#include "SBlueprintEditorToolbar.h"
#include "ScopedTransaction.h"
#include "Slate/SLGAEditorViewport.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorModes.h"
#include "LegoAbilityEditorSettings.h"
#include "LegoAbilityEditorStyle.h"
#include "LegoAbilityEditorToolbar.h"
#include "LGATask_PlayTimeline.h"
#include "Timeline/LGATimelineModel.h"
#include "Timeline/LGATimelinePreviewer.h"
#include "LegoAbilityTypes.h"
#include "RichCurveEditorModel.h"
#include "Timeline/SLGATimelineCurveEditor.h"
#include "LegoAbilityEditorViewportClient.h"
#include "Materials/Material.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

DEFINE_LOG_CATEGORY(LogLegoAbilityEditor);

ULegoAbilityEditorSettings* FLegoAbilityEditor::EditorSettings;

FLegoAbilityEditor::FLegoAbilityEditor()
	: AssetDirtyBrush(nullptr)
	, TabIcon(nullptr)
	, CurrentTimeline(ULGATimeline::GetNullTimeline())
	, m_DrawArrowComponent(false)
	, m_DrawCameraComponent(false)
{
	EditorSettings = GetMutableDefault<ULegoAbilityEditorSettings>();

	// Slightly annoying/obfuscated setting. This setting can prevent particles from being drawn - not sure why.
	// Persona calls this out but only mentions that it's attached effects but it's all effects.
	PreviewScene.GetWorld()->GetWorldSettings()->SetIsTemporarilyHiddenInEditor(false);

	UAssetViewerSettings* DefaultSettings = UAssetViewerSettings::Get();
	check(DefaultSettings);

	CurrentProfileIndex = DefaultSettings->Profiles.IsValidIndex(CurrentProfileIndex) ? GetDefault<UEditorPerProjectUserSettings>()->AssetViewerProfileIndex : 0;
	ensureMsgf(DefaultSettings->Profiles.IsValidIndex(CurrentProfileIndex), TEXT("Invalid default settings pointer or current profile index"));
	FPreviewSceneProfile& Profile = DefaultSettings->Profiles[CurrentProfileIndex];
	Profile.LoadEnvironmentMap();

	// Always set up sky light using the set cube map texture, reusing the sky light from PreviewScene class
	PreviewScene.SetSkyCubemap(Profile.EnvironmentCubeMap.Get());
	PreviewScene.SetSkyBrightness(Profile.SkyLightIntensity);

	// Large scale to prevent sphere from clipping
	const FTransform SphereTransform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(2000));
	UStaticMeshComponent* SkyComponent = NewObject<UStaticMeshComponent>(GetTransientPackage());

	// Set up sky sphere showing the same cube map as used by the sky light
	UStaticMesh* SkySphere = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/AssetViewer/Sphere_inversenormals.Sphere_inversenormals"), NULL, LOAD_None, NULL);
	check(SkySphere);
	SkyComponent->SetStaticMesh(SkySphere);
	SkyComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SkyComponent->CastShadow = false;
	SkyComponent->bCastDynamicShadow = false;

	UMaterial* SkyMaterial = LoadObject<UMaterial>(NULL, TEXT("/Engine/EditorMaterials/AssetViewer/M_SkyBox.M_SkyBox"), NULL, LOAD_None, NULL);
	check(SkyMaterial);

	UMaterialInstanceConstant* InstancedSkyMaterial = NewObject<UMaterialInstanceConstant>(GetTransientPackage());
	InstancedSkyMaterial->Parent = SkyMaterial;

	UTextureCube* DefaultTexture = LoadObject<UTextureCube>(NULL, TEXT("/Engine/MapTemplates/Sky/SunsetAmbientCubemap.SunsetAmbientCubemap"));

	InstancedSkyMaterial->SetTextureParameterValueEditorOnly(FName("SkyBox"), (Profile.EnvironmentCubeMap.Get() != nullptr) ? Profile.EnvironmentCubeMap.Get() : DefaultTexture);
	InstancedSkyMaterial->SetScalarParameterValueEditorOnly(FName("CubemapRotation"), Profile.LightingRigRotation / 360.0f);
	InstancedSkyMaterial->SetScalarParameterValueEditorOnly(FName("Intensity"), Profile.SkyLightIntensity);
	InstancedSkyMaterial->PostLoad();
	SkyComponent->SetMaterial(0, InstancedSkyMaterial);
	PreviewScene.AddComponent(SkyComponent, SphereTransform);

	const FTransform Transform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(1));

	UPostProcessComponent* PostProcessComponent = NewObject<UPostProcessComponent>();
	PostProcessComponent->Settings = Profile.PostProcessingSettings;
	PostProcessComponent->bUnbound = true;
	PreviewScene.AddComponent(PostProcessComponent, Transform);

	// Set up floor for preview character
	UStaticMesh* FloorMesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/EditorMeshes/AssetViewer/Floor_Mesh.Floor_Mesh"), NULL, LOAD_None, NULL);
	check(FloorMesh);
	UStaticMeshComponent*  FloorMeshComponent = NewObject<UStaticMeshComponent>(GetTransientPackage());
	FloorMeshComponent->SetStaticMesh(FloorMesh);
	FloorMeshComponent->bSelectable = false;

	float FloorOffset = 0;
	FTransform FloorTransform(FRotator(0, 0, 0), FVector(0, 0, -(FloorOffset)), FVector(16.0f, 16.0f, 1.0f));
	PreviewScene.AddComponent(FloorMeshComponent, FloorTransform);


	PreviewScene.SetLightDirection(Profile.DirectionalLightRotation);
}

FLegoAbilityEditor::~FLegoAbilityEditor()
{
	UnregisterDelegatesForTimeline();
	GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);
}

void FLegoAbilityEditor::InitLegoAbilityEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, const TArray<UBlueprint*>& InBlueprints)
{
	check(InBlueprints.Num() > 0);

	if (!AssetDirtyBrush)
	{
		AssetDirtyBrush = FAppStyle::GetBrush("ContentBrowser.ContentDirty");
	}

	if (!TabIcon)
	{
		TabIcon = FLegoAbilityEditorStyle::GetBrush("LegoAbilityEditor.Tabs.Timeline");
	}

	TSharedPtr<FLegoAbilityEditor> ThisPtr(SharedThis(this));
	if (!Toolbar.IsValid())
	{
		Toolbar = MakeShareable(new FBlueprintEditorToolbar(ThisPtr));
	}

	if (!ToolbarBuilder.IsValid())
	{
		ToolbarBuilder = MakeShareable(new FLegoAbilityEditorToolbar(ThisPtr));
	}

	BindCommands();

	// Create anim model
	AnimModel = MakeShared<FLGATimelineModel>(ToolkitCommands, ThisPtr, ULGATimeline::GetNullTimeline());

	AnimModel->OnEditCurves = FOnEditCurves::CreateLambda([this](const FCurveEditInfo& InCurveInfo)
	{
		this->EditCurves(InCurveInfo);
	});

	AnimModel->Initialize();

	// Initialize the asset editor and spawn tabs
	InitBlueprintEditor(Mode, InitToolkitHost, InBlueprints, false);

	// Custom Menu/Toolbar
	ExtendMenu();
	ExtendToolbar();

	// set timeline mode as default
	SetCurrentMode(FLegoAbilityEditorModes::TimelineMode);
	SpawnPreviewActor();
}

FName FLegoAbilityEditor::GetToolkitFName() const
{
	return FName("LegoAbilityEditor");
}

FText FLegoAbilityEditor::GetBaseToolkitName() const
{
	return LOCTEXT("LegoAbilityEditorAppLabel", "Ability Editor");
}

FText FLegoAbilityEditor::GetToolkitName() const
{
	const TArray<UObject*>& CurrentEditingObjects = GetEditingObjects();
	check(CurrentEditingObjects.Num() > 0);
	const UObject* EditingObject = CurrentEditingObjects[0];

	FFormatNamedArguments Args;
	Args.Add(TEXT("ObjectName"), FText::FromString(EditingObject->GetName()));
	Args.Add(TEXT("DirtyState"), EditingObject->GetOutermost()->IsDirty() ? FText::FromString(TEXT("*")) : FText::GetEmpty());
	return FText::Format(LOCTEXT("LegoAbilityToolkitName", "{ObjectName}{DirtyState}"), Args);
}

FText FLegoAbilityEditor::GetToolkitToolTipText() const
{
	const UObject* EditingObject = GetEditingObject();

	check(EditingObject != NULL);

	return FAssetEditorToolkit::GetToolTipTextForObject(EditingObject);
}

FString FLegoAbilityEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("LegoAbilityEditor");
}

FLinearColor FLegoAbilityEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

ULegoAbilityBlueprint* FLegoAbilityEditor::GetAbilityBlueprint() const
{
	return Cast<ULegoAbilityBlueprint>(GetBlueprintObj());
}

ULegoAbilityBlueprintGeneratedClass* FLegoAbilityEditor::GetAbilityBlueprintGeneratedClass() const
{
	if (UBlueprint* Blueprint = GetBlueprintObj())
	{
		return Cast<ULegoAbilityBlueprintGeneratedClass>(Blueprint->GeneratedClass);
	}

	return nullptr;
}

void FLegoAbilityEditor::SetCurrentTimeline(ULGATimeline* Timeline)
{
	if (Timeline != CurrentTimeline)
	{
		UnregisterDelegatesForTimeline();
		CurrentTimeline = Timeline;
		RegisterDelegatesForTimeline();
		AnimModel->SetAbilityTimeline(Timeline);
		Timeline->PreviewWorld = PreviewScene.GetWorld();
		Timeline->AddCameraShake.BindLambda(
			[this](const FLegoCameraShakePreviewerAddParams& Params)
			{
				UCameraShakeBase* Result = nullptr;
				if (GetViewportClient())
				{
					Result = GetViewportClient()->GetCameraShakePreviewer().AddCameraShake(Params);
				}
				return Result;
			}
		);

		Timeline->RemoveCameraShake.BindLambda(
			[this](UCameraShakeBase* ShakeInstance)
			{
				if (GetViewportClient())
				{
					GetViewportClient()->GetCameraShakePreviewer().RemoveCameraShake(ShakeInstance);
				}
			}
		);

		if (CurveEditor.IsValid())
		{
			CurveEditor.Pin()->ResetCurves();
		}

		ResetPreviewActor();
	}
}

void FLegoAbilityEditor::RegisterDelegatesForTimeline()
{
	if (IsCurrentTimelineValid())
	{
		PropertyChangedDelegateHandle = CurrentTimeline->OnPropertyChanged.AddSP(this, &FLegoAbilityEditor::OnTimelinePropertyChanged);
		TransactionAppliedDelegateHandle = CurrentTimeline->OnTransactionApplied.AddSP(this, &FLegoAbilityEditor::OnTimelineTransactionApplied);
	}
}

void FLegoAbilityEditor::UnregisterDelegatesForTimeline()
{
	if (IsCurrentTimelineValid())
	{
		CurrentTimeline->OnPropertyChanged.Remove(PropertyChangedDelegateHandle);
		CurrentTimeline->OnTransactionApplied.Remove(TransactionAppliedDelegateHandle);
	}
}

void FLegoAbilityEditor::OnTimelinePropertyChanged()
{
	FBlueprintEditorUtils::MarkBlueprintAsModified(GetBlueprintObj());
	if (ULegoAbilityBlueprint* AbilityBlueprint = GetAbilityBlueprint())
	{
		AbilityBlueprint->UpdateTimelineTemplate();
	}

	if (CurveEditor.IsValid())
	{
		CurveEditor.Pin()->ClearInvalidCurves();
	}
}

void FLegoAbilityEditor::OnTimelineTransactionApplied()
{
	AnimModel->UpdateRange();
}



bool FLegoAbilityEditor::IsCurrentTimelineLocal()
{
	if (ULegoAbilityBlueprint* Blurpeint = GetAbilityBlueprint())
	{
		return Blurpeint->HasTimeline(CurrentTimeline.Get());
	}
	return false;
}

void FLegoAbilityEditor::Tick(float DeltaTime)
{
	FBlueprintEditor::Tick(DeltaTime);

	// Note: The weak ptr can become stale if the actor is reinstanced due to a Blueprint change, etc. In that 
	// case we look to see if we can find the new instance in the preview world and then update the weak ptr.
	if (PreviewActor.IsStale(true) && PreviewActorClass.IsValid())
	{
		UWorld* PreviewWorld = PreviewScene.GetWorld();
		for (TActorIterator<AActor> It(PreviewWorld); It; ++It)
		{
			AActor* Actor = *It;
			if (!Actor->IsPendingKillPending() && Actor->GetClass() == PreviewActorClass.Get())
			{
				PreviewActor = Actor;
				if (UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, true))
				{
					if (ASC->IsRegistered() && !ASC->HasBeenInitialized())
					{
						ASC->InitializeComponent();
					}
				}
				break;
			}
		}
	}
}

void FLegoAbilityEditor::PostUndo(bool bSuccessful)
{
	FBlueprintEditor::PostUndo(bSuccessful);
	OnAbilityBlueprintTransaction.Broadcast();
}

void FLegoAbilityEditor::PostRedo(bool bSuccessful)
{
	FBlueprintEditor::PostRedo(bSuccessful);
	OnAbilityBlueprintTransaction.Broadcast();
}

void FLegoAbilityEditor::RegisterApplicationModes(const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode, bool bNewlyCreated/* = false*/)
{
	if (InBlueprints.Num() == 1)
	{
		TArray<TSharedRef<FApplicationMode>> TempModeList;
		TSharedPtr<FLegoAbilityEditor> ThisPtr(SharedThis(this));
		TempModeList.Add(MakeShareable(new FLegoAbilityEditorTimelineMode(ThisPtr)));
		TempModeList.Add(MakeShareable(new FLegoAbilityEditorBlueprintMode(ThisPtr)));

		for (TSharedRef<FApplicationMode>& AppMode : TempModeList)
		{
			AddApplicationMode(AppMode->GetModeName(), AppMode);
		}
	}
}

TStatId FLegoAbilityEditor::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FLegoAbilityEditor, STATGROUP_Tickables);
}


const FSlateBrush* FLegoAbilityEditor::GetDirtyImageForMode(FName Mode) const
{
	// Right now, both modes edit the same object. So, just return the brush if any assets are dirty.
	for (UObject* Obj : GetEditingObjects())
	{
		if (UPackage* package = Obj->GetOutermost())
		{
			if (package->IsDirty())
			{
				return AssetDirtyBrush;
			}
		}
	}

	return nullptr;
}



ULegoAbilityEditorSettings& FLegoAbilityEditor::GetEditorSettings()
{
	if (!EditorSettings)
	{
		EditorSettings = GetMutableDefault<ULegoAbilityEditorSettings>();
	}
	return *EditorSettings;
}


bool FLegoAbilityEditor::IsCurrentTimelineValid() const
{
	return CurrentTimeline.IsValid() && CurrentTimeline.Get() != ULGATimeline::GetNullTimeline();
}


void FLegoAbilityEditor::SetPreviewAsset(const FAssetData& PreviewAsset)
{
	ULegoAbilityBlueprint* AbilityBlueprint = GetAbilityBlueprint();
	FSoftObjectPath NewPreviewAsset = UAssetManager::Get().GetAssetPathForData(PreviewAsset);
	if (NewPreviewAsset != AbilityBlueprint->PreviewAsset)
	{
		AbilityBlueprint->PreviewAsset = NewPreviewAsset;
		SpawnPreviewActor();
	}
}

const FSlateBrush* FLegoAbilityEditor::GetDefaultTabIcon() const
{
	return TabIcon ? TabIcon : FWorkflowCentricApplication::GetDefaultTabIcon();
}


void FLegoAbilityEditor::OnEnteringTimelineMode()
{
	OnEnterTimelineMode.Broadcast();
}

void FLegoAbilityEditor::EditCurves(const FCurveEditInfo& InCurveInfo)
{
	if (!TimelineCurveDocumentTab.IsValid())
	{
		TSharedRef<SLGATimelineCurveEditor> NewCurveEditor = SNew(SLGATimelineCurveEditor, AnimModel->GetTimelinePreviewer())
			.ExternalTimeSliderController(AnimModel->GetTimelinePreviewer().Get()->CurrentTimeSliderContrller)
			.TabManager(TabManager);

		CurveEditor = NewCurveEditor;

		TSharedPtr<SDockTab> CurveTab = SNew(SDockTab)
			.Label(LOCTEXT("CurveEditorTabTitle", "Curve Editor"))
			.TabRole(ETabRole::DocumentTab)
			.TabColorScale(GetTabColorScale())
			[
				NewCurveEditor
			];

		TimelineCurveDocumentTab = CurveTab;

		TabManager->InsertNewDocumentTab(FTimelineTabSummoner::CurveEditorTab, FTabManager::ESearchPreference::RequireClosedTab, CurveTab.ToSharedRef());
	}
	else
	{
		TabManager->DrawAttention(TimelineCurveDocumentTab.Pin().ToSharedRef());
	}

	check(CurveEditor.IsValid());

	CurveEditor.Pin()->AddCurve(InCurveInfo.Timeline, InCurveInfo.CurveName, InCurveInfo.OnCurveModified);

	CurveEditor.Pin()->ZoomToFit();
}

FLegoAbilityEditorViewportClient* FLegoAbilityEditor::GetViewportClient()
{
	if (ViewportTabBody.IsValid())
	{
		return static_cast<FLegoAbilityEditorViewportClient*>(ViewportTabBody.Pin()->GetEditorViewportClient().Get());
	}

	return nullptr;
}

void FLegoAbilityEditor::ExtendMenu()
{
	if (MenuExtender.IsValid())
	{
		RemoveMenuExtender(MenuExtender);
		MenuExtender.Reset();
	}

	MenuExtender = MakeShareable(new FExtender);

	//FKismet2Menu::SetupBlueprintEditorMenu(MenuExtender, *this);

	// Custom Menus for Ability Editor
	{
		struct Local
		{
			static void AddAbilityFileMenu(FMenuBuilder& MenuBuilder)
			{
				// View
				MenuBuilder.BeginSection("FLegoAbilityEditor", LOCTEXT("AbilityEditorMenu_File", "Blueprint"));
				{
				}
				MenuBuilder.EndSection();
			}

			static void AddAbilityTimelineMenu(FMenuBuilder& MenuBuilder)
			{
				const FLegoAbilityEditorCommands& Commands = FLegoAbilityEditorCommands::Get();
				MenuBuilder.BeginSection("EditTimeline", LOCTEXT("AbilityEditorMenu_Timeline", "Timeline"));
				MenuBuilder.AddMenuSeparator();
				MenuBuilder.AddMenuEntry(Commands.m_ToggleDrawArrowComponent);
				MenuBuilder.AddMenuEntry(Commands.m_ToggleDrawCameraComponent);
				MenuBuilder.EndSection();
			}

			static void AddAbilityTimelineDropdownMenu(FMenuBarBuilder& MenuBarBuilder)
			{
				MenuBarBuilder.AddPullDownMenu(LOCTEXT("Timeline", "Timeline"),
					LOCTEXT("Timeline_Tooltip", "Opens the Timeline Menu"),
					FNewMenuDelegate::CreateStatic(&Local::AddAbilityTimelineMenu),
					"Timeline");
			}
		};

		MenuExtender->AddMenuBarExtension(
			"Edit",
			EExtensionHook::After,
			GetToolkitCommands(),
			FMenuBarExtensionDelegate::CreateStatic(&Local::AddAbilityTimelineDropdownMenu));
	}

	AddMenuExtender(MenuExtender);
}

void FLegoAbilityEditor::ExtendToolbar()
{
	// If the ToolbarExtender is valid, remove it before rebuilding it
	if (ToolbarExtender.IsValid())
	{
		RemoveToolbarExtender(ToolbarExtender);
		ToolbarExtender.Reset();
	}

	ToolbarExtender = MakeShareable(new FExtender);
	ToolbarBuilder->AddAbilityEditorModesToolbar(ToolbarExtender);
	AddToolbarExtender(ToolbarExtender);
}

void FLegoAbilityEditor::BindCommands()
{
	const FLegoAbilityEditorCommands& Commands = FLegoAbilityEditorCommands::Get();
	
	ToolkitCommands->MapAction(Commands.m_CaptureThumbnail, FExecuteAction::CreateSP(this, &FLegoAbilityEditor::CaptureThumbnail));
	ToolkitCommands->MapAction(Commands.m_ToggleDrawArrowComponent, FExecuteAction::CreateSP(this, &FLegoAbilityEditor::ToggleDrawArrowComponent), FCanExecuteAction(), FIsActionChecked::CreateSP(this, &FLegoAbilityEditor::IsDrawingArrowComponent));
	ToolkitCommands->MapAction(Commands.m_ToggleDrawCameraComponent, FExecuteAction::CreateSP(this, &FLegoAbilityEditor::ToggleDrawCameraComponent), FCanExecuteAction(), FIsActionChecked::CreateSP(this, &FLegoAbilityEditor::IsDrawingCameraComponent));

	ToolkitCommands->MapAction(FLegoAbilityEditorTimelineCommands::Get().TogglePlay,
		FExecuteAction::CreateRaw(this, &FLegoAbilityEditor::TogglePlay));
}

AActor* FLegoAbilityEditor::InternalSpawnActor(UClass* ActorClass, const FTransform& Transform)
{
	UWorld* PreviewWorld = PreviewScene.GetWorld();
	if (AActor* SpawnedActor = PreviewWorld->SpawnActorDeferred<AActor>(ActorClass, Transform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn))
	{
		if (UCharacterMovementComponent* CharMoveComp = SpawnedActor->FindComponentByClass<UCharacterMovementComponent>())
		{
			CharMoveComp->UpdatedComponent = nullptr;
			CharMoveComp->bRunPhysicsWithNoController = true;
		}

		if (SpawnedActor->Implements<ULegoAbilityPreviewInterface>())
		{
			ILegoAbilityPreviewInterface::Execute_PostPreviewActorCreated(SpawnedActor);
		}

		SpawnedActor->FinishSpawning(Transform);

		return SpawnedActor;
	}

	return nullptr;
}

void FLegoAbilityEditor::SpawnPreviewActor(const FTransform& initTransform)
{
	if (PreviewActor.IsValid())
	{
		PreviewActor->GetWorld()->RemoveActor(PreviewActor.Get(), false);
		PreviewActor->Destroy();
		PreviewActor.Reset();
	}

	const FSoftObjectPath& AssetPath = GetAbilityBlueprint()->PreviewAsset;
	if (AssetPath.IsValid())
	{
		PreviewActorClass = Cast<UClass>(AssetPath.TryLoad());
		if (PreviewActorClass.IsValid())
		{
			PreviewActor = InternalSpawnActor(PreviewActorClass.Get(), initTransform);
			if (PreviewActor.IsValid())
			{
				PreviewActorSavedTransform = PreviewActor->GetTransform();
				ResetPreviewActor();
			}
			else
			{
				UE_LOG(LogLegoAbilityEditor, Error, TEXT("Spawn preview actor %s failed"), *AssetPath.GetAssetPathString());
			}
		}
		else
		{
			UE_LOG(LogLegoAbilityEditor, Error, TEXT("Load blueprint class %s failed"), *AssetPath.GetAssetPathString());
		}
	}
}


void FLegoAbilityEditor::ResetPreviewActor()
{
	if (PreviewActor.IsValid())
	{
		PreviewActor->SetActorTransform(PreviewActorSavedTransform);

		UAbilitySystemComponent* AbilityComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(PreviewActor.Get());
		if (!AbilityComponent)
		{
			UE_LOG(LogLegoAbilityEditor, Warning, TEXT("Unable to find an Ability Component for Actor class %s, one has been added temporarily. Please fix the source asset."), *(PreviewActorClass->GetName()));
			AbilityComponent = NewObject<UAbilitySystemComponent>(PreviewActor.Get());
			PreviewActor->AddOwnedComponent(AbilityComponent);
			AbilityComponent->RegisterComponent();
		}

		if (UArrowComponent* ArrowComponent = PreviewActor->FindComponentByClass<UArrowComponent>())
		{
			ArrowComponent->SetVisibility(m_DrawArrowComponent);
		}

		if (UCameraComponent* CameraComponent = PreviewActor->FindComponentByClass<UCameraComponent>())
		{
			// Hide the Camera Mesh.
			CameraComponent->SetVisibility(m_DrawCameraComponent, true);
		}
	}
}

void FLegoAbilityEditor::ToggleDrawArrowComponent()
{
	m_DrawArrowComponent = !m_DrawArrowComponent;
	ResetPreviewActor();
}

void FLegoAbilityEditor::ToggleDrawCameraComponent()
{
	m_DrawCameraComponent = !m_DrawCameraComponent;
	ResetPreviewActor();
}

void FLegoAbilityEditor::CaptureThumbnail()
{
	if (ViewportTabBody.IsValid())
	{
		ViewportTabBody.Pin()->CaptureThumbnail();
	}
}

void FLegoAbilityEditor::TogglePlay()
{
	FLGATimelinePreviewer* Previewer = AnimModel->GetTimelinePreviewer().Get();
	if (Previewer)
	{
		Previewer->TogglePlay();
	}
}

#undef LOCTEXT_NAMESPACE
