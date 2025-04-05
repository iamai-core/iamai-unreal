// Some copyright should be here...

using UnrealBuildTool;

public class iamaiUnreal : ModuleRules {

    public iamaiUnreal( ReadOnlyTargetRules Target ) : base( Target ) {

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableExceptions = true;
        PublicDefinitions.Add( "PLATFORM_EXCEPTIONS_DISABLED=0" );

        PublicDependencyModuleNames.AddRange( new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "AudioCapture"
        } );


        PrivateDependencyModuleNames.AddRange( new string[] {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
        } );

    }

}
