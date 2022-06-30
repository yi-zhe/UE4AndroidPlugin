#include "IPluginSample.h"
#include "PluginSampleBlueprintLibrary.h"


DEFINE_LOG_CATEGORY(LogPluginSample);

#define LOCTEXT_NAMESPACE "PluginSample"

class FPluginSample : public IPluginSample
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FPluginSample, PluginSample)

// Startup Module
void FPluginSample::StartupModule()
{    
#if PLATFORM_ANDROID || PLATFORM_IOS
    PlatformInterface = MakeShareable(new FPluginSamplePlatform());
#endif
}

// Shutdown Module
void FPluginSample::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE
