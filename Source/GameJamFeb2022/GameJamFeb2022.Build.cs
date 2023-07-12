// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameJamFeb2022 : ModuleRules
{
	public GameJamFeb2022(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "GameplayTasks" });
	}
}
