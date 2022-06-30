using System.IO;

namespace UnrealBuildTool.Rules
{
    public class PluginSample : ModuleRules
    {
        public PluginSample(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            PrecompileForTargets = PrecompileTargetsType.Any;

            PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject"});

            PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PrivateDependencyModuleNames.AddRange(new string[] { "Launch", "ThirdLib" });
                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "PluginSample_UPL_Android.xml"));
            }
        }
    }
}
