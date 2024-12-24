#include <jni.h>
#include <stdio.h>

void library1_callback(const char* message) {
    printf("Library1 callback: %s\n", message);
}

JNIEXPORT jlong JNICALL
Java_com_example_nativecallbacktest_NativeInterop_getCallbackFunctionPointer(JNIEnv *env, jobject obj) {
    return (jlong)&library1_callback; // Zwracamy wskaźnik do funkcji
}
