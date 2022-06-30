#pragma once

#include "Interfaces/PluginSampleInterface.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#include "EngineMinimal.h"
#include "Core.h"

class FPluginSamplePlatform : public IPluginSampleInterface
{
public:
    FPluginSamplePlatform();
    virtual ~FPluginSamplePlatform();

    virtual bool CheckInternetConnection() override;
    virtual void CallStatic() override;
    virtual void CallInstance() override;

    // JNI Methods
    static jmethodID CheckInternetConnectionMethod;
    static jclass AndroidLibClass;
    static jmethodID CallStaticMethod;
    static jmethodID CallInstanceMethod;
};
