package com.learn.lib;

public class AndroidLib {

    public static final AndroidLib ANDROID_LIB = new AndroidLib();

    public void calledFromNative() {
        android.util.Log.e("==##", "Hello instance method");
    }

    public static void calledFromNative2() {
        android.util.Log.e("==##", "Hello static method");
    }

    public static native void init(AndroidLib lib);

    public static native void destroy();
}
