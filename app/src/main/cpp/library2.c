#include <jni.h>
#include <stdio.h>

typedef void (*Callback)(const char*);

// Globalny wskaźnik do funkcji callback
static Callback registered_callback = NULL;

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_registerCallbackInLibrary2(JNIEnv *env, jobject obj, jlong functionPointer) {
    registered_callback = (Callback)functionPointer;
}

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_triggerCallback(JNIEnv *env, jobject obj) {
    if (registered_callback != NULL) {
        registered_callback("Hello from Library2!");
    } else {
        printf("No callback registered.\n");
    }
}
