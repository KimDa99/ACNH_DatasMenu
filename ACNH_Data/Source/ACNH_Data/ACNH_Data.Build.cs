// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ACNH_Data : ModuleRules
{
	public ACNH_Data(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		PrivateDependencyModuleNames.Add("OnlineSubsystem");
	}
}
