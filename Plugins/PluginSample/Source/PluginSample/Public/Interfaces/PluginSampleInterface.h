#pragma once

#include "EngineMinimal.h"
#include "Core.h"

class IPluginSampleInterface
{
public:
    /**
    * Check if internet connection is available on a device
    *
    * @return - true if connection is available
    */
    virtual bool CheckInternetConnection() = 0;

    /**
    * Call static method of a java class
    */
    virtual void CallStatic() = 0;

    virtual void CallInstance() = 0;
};
