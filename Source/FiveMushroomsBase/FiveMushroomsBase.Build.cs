// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FiveMushroomsBase : ModuleRules
{
	public FiveMushroomsBase(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AImodule","GameplayTasks" });
	}
}
