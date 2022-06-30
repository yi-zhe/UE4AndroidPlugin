
#include "com_learn_lib_AndroidLib.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_learn_lib_AndroidLib_init(JNIEnv * env, jobject thiz, jobject androidLibThis) {
    if (AndroidLibThisGlobal == nullptr) {
        AndroidLibThisGlobal = static_cast<jobject>(env->NewGlobalRef(androidLibThis));
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_learn_lib_AndroidLib_destroy(JNIEnv * env, jobject thiz) {
    if (AndroidLibThisGlobal) {
        env->DeleteGlobalRef(AndroidLibThisGlobal);
        AndroidLibThisGlobal = nullptr;
    }
}
