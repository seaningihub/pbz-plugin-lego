// Copyright S-Game, Inc. All Rights Reserved.
using System.IO;

namespace UnrealBuildTool.Rules
{
	public class LegoAbilityEditor : ModuleRules
	{
		public LegoAbilityEditor(ReadOnlyTargetRules Target) : base (Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			if (!File.Exists(Path.Combine(ModuleDirectory, @"Private", @"LegoAbilityEditor.cpp")))
			{
				bUsePrecompiled = true;
			}
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"LegoAbility",
					// ... add other public dependencies that you statically link with here ...
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"ApplicationCore",
					"AssetTools",
					"BlueprintGraph",
					"ClassViewer",
					"ContentBrowser",
					"Core",
					"CoreUObject",
					"EditorStyle",
					"Engine",
					"InputCore",
					"Kismet",
					"KismetCompiler",
					"KismetWidgets",
					"Persona",
					"Projects",
					"PropertyEditor",
					"SequencerWidgets",
					"Slate",
					"SlateCore",
					"TimeManagement",
					"ToolMenus",
					"UnrealEd",
					"GameplayAbilities",
					"GameplayTasks",
					"AdvancedPreviewScene",
					"EditorWidgets",
					"AppFramework",
					"CurveEditor"
				}
			);
		}
	}
}
