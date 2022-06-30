#include "PluginSamplePlatform.h"
#include "com_learn_lib_AndroidLib.h"

jmethodID FPluginSamplePlatform::CheckInternetConnectionMethod = nullptr;
jmethodID FPluginSamplePlatform::CallStaticMethod = nullptr;
jmethodID FPluginSamplePlatform::CallInstanceMethod = nullptr;
jclass    FPluginSamplePlatform::AndroidLibClass = nullptr;

FPluginSamplePlatform::FPluginSamplePlatform()
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        CheckInternetConnectionMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckInternetConnection", "()Z", false);
    }
}

FPluginSamplePlatform::~FPluginSamplePlatform()
{
}

bool FPluginSamplePlatform::CheckInternetConnection()
{
    bool bResult = false;

    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FPluginSamplePlatform::CheckInternetConnectionMethod);
    }
    return bResult;
}

void FPluginSamplePlatform::CallStatic() {
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        if (AndroidLibClass == nullptr) {
            AndroidLibClass = FAndroidApplication::FindJavaClass("com/learn/lib/AndroidLib");
        }
        if (AndroidLibClass) {
            CallStaticMethod = FJavaWrapper::FindStaticMethod(Env, AndroidLibClass, "calledFromNative2", "()V", false);
            if (CallStaticMethod) {
                Env->CallStaticVoidMethod(AndroidLibClass, CallStaticMethod);
            }
        }
    }
}

void FPluginSamplePlatform::CallInstance() {
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv()) {
        if (AndroidLibClass == nullptr) {
            AndroidLibClass = FAndroidApplication::FindJavaClass("com/learn/lib/AndroidLib");
        }
        if (AndroidLibClass) {
            CallInstanceMethod = FJavaWrapper::FindMethod(Env, AndroidLibClass, "calledFromNative", "()V", false);
            if (CallInstanceMethod) {
                FJavaWrapper::CallVoidMethod(Env, AndroidLibThisGlobal, FPluginSamplePlatform::CallInstanceMethod);
            }
        }
    }
}
