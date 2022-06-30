#pragma once

#include "Modules/ModuleManager.h"
#include "EngineMinimal.h"
#include "Core.h"
#include "Interfaces/PluginSampleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPluginSample, Log, All);

typedef TSharedPtr<IPluginSampleInterface, ESPMode::ThreadSafe> FPluginSamplePlatformPtr;

class IPluginSample : public IModuleInterface
{
public:
    static inline IPluginSample& Get()
    {
        return FModuleManager::LoadModuleChecked< IPluginSample >("PluginSample");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("PluginSample");
    }

    inline FPluginSamplePlatformPtr GetPlatformInterface() const
    {
        return PlatformInterface;
    }

protected:
    FPluginSamplePlatformPtr PlatformInterface;
};
