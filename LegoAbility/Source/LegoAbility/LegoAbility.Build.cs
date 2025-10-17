// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class LegoAbility : ModuleRules
{
	public LegoAbility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		if (!File.Exists(Path.Combine(ModuleDirectory, @"Private", @"LegoAbility.cpp")))
		{
			bUsePrecompiled = true;
		}

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GameplayAbilities",
				// ... add other public dependencies that you statically link with here ...
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
				// ... add private dependencies that you statically link with here ...	
			}
		);

		if (Target.Type == TargetType.Editor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"AnimGraph"
					// ... add private dependencies that you statically link with here ...	
				}
			);
		}
	}
}
