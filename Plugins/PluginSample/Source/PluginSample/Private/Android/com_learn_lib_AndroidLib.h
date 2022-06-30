#pragma once
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <android/log.h>
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, "==##", __VA_ARGS__)

/* Header for class com_learn_lib_AndroidLib */

#ifndef _Included_com_learn_lib_AndroidLib
#define _Included_com_learn_lib_AndroidLib
#ifdef __cplusplus
extern "C" {
#endif

    jobject AndroidLibThisGlobal = nullptr;

    /*
     * Class:     com_learn_lib_AndroidLib
     * Method:    init
     * Signature: (Lcom/learn/lib/AndroidLib;)V
     */
    JNIEXPORT void JNICALL Java_com_learn_lib_AndroidLib_init(JNIEnv*, jobject, jobject);

    /*
     * Class:     com_learn_lib_AndroidLib
     * Method:    destroy
     * Signature: ()V
     */
    JNIEXPORT void JNICALL Java_com_learn_lib_AndroidLib_destroy(JNIEnv*, jobject);

#ifdef __cplusplus
}
#endif
#endif
