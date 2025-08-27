// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IsekaiRPG : ModuleRules
{
	public IsekaiRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"IsekaiRPG",
			"IsekaiRPG/Variant_Platforming",
			"IsekaiRPG/Variant_Platforming/Animation",
			"IsekaiRPG/Variant_Combat",
			"IsekaiRPG/Variant_Combat/AI",
			"IsekaiRPG/Variant_Combat/Animation",
			"IsekaiRPG/Variant_Combat/Gameplay",
			"IsekaiRPG/Variant_Combat/Interfaces",
			"IsekaiRPG/Variant_Combat/UI",
			"IsekaiRPG/Variant_SideScrolling",
			"IsekaiRPG/Variant_SideScrolling/AI",
			"IsekaiRPG/Variant_SideScrolling/Gameplay",
			"IsekaiRPG/Variant_SideScrolling/Interfaces",
			"IsekaiRPG/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
