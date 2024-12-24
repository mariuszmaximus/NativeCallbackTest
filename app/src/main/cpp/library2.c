#include <jni.h>
#include <stdio.h>
#include <android/log.h> // Dodaj ten nagłówek

#define LOG_TAG "NativeCallbackTest" // Ustaw nazwę tagu dla logów
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__) // Log poziomu INFO
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__) // Log poziomu ERROR

typedef void (*Callback)(const char*);

// Globalny wskaźnik do funkcji callback
static Callback registered_callback = NULL;

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_registerCallbackInLibrary2(JNIEnv *env, jobject obj, jlong functionPointer) {
    registered_callback = (Callback)functionPointer;
    LOGI("Callback registered successfully.");
}

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_triggerCallback(JNIEnv *env, jobject obj) {

    LOGI("!!!!!!!!!!!!!!!!!! LIBRARY 2 ");
    if (registered_callback != NULL) {
        registered_callback("Hello from Library2!");
        LOGI("Callback version");
    } else {
        LOGI("No callback registered.\n");
    }
}
