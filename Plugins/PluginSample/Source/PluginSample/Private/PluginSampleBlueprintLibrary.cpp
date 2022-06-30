#include "PluginSampleBlueprintLibrary.h"

UPluginSampleBlueprintLibrary::UPluginSampleBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

bool UPluginSampleBlueprintLibrary::CheckInternetConnection()
{
#if PLATFORM_ANDROID || PLATFORM_IOS
    return IPluginSample::Get().GetPlatformInterface()->CheckInternetConnection();
#else
    return true;
#endif
}

bool UPluginSampleBlueprintLibrary::CallStaticMethod()
{
    IPluginSample::Get().GetPlatformInterface()->CallStatic();
    return true;
}

bool UPluginSampleBlueprintLibrary::CallInstanceMethod()
{
    IPluginSample::Get().GetPlatformInterface()->CallInstance();
    return true;
}
