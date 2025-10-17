// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Blueprint.h"
#include "LegoAbilityBlueprint.generated.h"

class ULGATimeline;
class ULGAAction;

USTRUCT(BlueprintType)
struct FLGATimelineOverride
{
	GENERATED_BODY()

	UPROPERTY()
	ULGATimeline* OverriddenTimeline = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "LegoAbility")
	ULGATimeline* Timeline = nullptr;

	UPROPERTY()
	bool bInheritMode = false;

	UPROPERTY()
	ULGATimeline* ParentTimeline = nullptr;

	UPROPERTY()
	TMap<FGuid, ULGAAction*> ActionOverrides;

	void ReplaceTimelineActions(ULGATimeline* Timeline) const;
};

UCLASS(BlueprintType)
class LEGOABILITYEDITOR_API ULegoAbilityBlueprint : public UBlueprint
{
	GENERATED_BODY()

public:
	/** Returns the most base ability blueprint for a given blueprint (if it is inherited from another ability blueprint, returning null if only native / non-ability BP classes are it's parent) */
	static ULegoAbilityBlueprint* FindRootLegoAbilityBlueprint(ULegoAbilityBlueprint* DerivedBlueprint);

	static bool ValidateGeneratedClass(const UClass* InClass);

	static bool RenameTimeline(ULegoAbilityBlueprint* Blueprint, const FName OldVarName, const FName NewVarName);

	static void DeleteTimeline(ULegoAbilityBlueprint* Blueprint, ULGATimeline* Timeline);

	ULGATimeline* GetTimelineByName(FName InName, bool bIncludeOverride = false) const;

	ULGATimeline* FindLatestTimelineTamplate(ULGATimeline* OverriddenTimeline);
	bool HasChildrenTimeline(ULGATimeline* ParentTimeline) const;
	bool HasTimeline(ULGATimeline* Timeline) const;

	ULGAAction* GetOverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid);
	bool OverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid);
	bool ResetOverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid);
	bool IsMyOverrideAction(ULGAAction* TestAction);

#if WITH_EDITOR
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override { return false; }
	virtual bool FindDiffs(const UBlueprint* OtherBlueprint, FDiffResults& Results) const override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	void ClearInvalidTimelines();

	virtual bool AlwaysCompileOnLoad() const override { return true; }
#endif

	void PostLoad() override;

	void UpdateTimelineTemplate(UObject* TargetClass = nullptr);

#if WITH_EDITORONLY_DATA
	/** Preview Asset Path */
	UPROPERTY()
	FSoftObjectPath PreviewAsset;

	/** Target Asset Path */
	UPROPERTY()
	FSoftObjectPath TargetAsset;

	/** If the user has manually chosen a thumbnail image, use that. */
	UPROPERTY()
	class UTexture2D* ThumbnailImage;
#endif

	UPROPERTY()
	TArray<ULGATimeline*> AbilityTimelines;

	UPROPERTY()
	TArray<FLGATimelineOverride> AbilityTimelineOverrides;
};