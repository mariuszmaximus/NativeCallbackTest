#include <jni.h>
#include <stdio.h>
#include <android/log.h> // Dodaj ten nagłówek

#define LOG_TAG "NativeCallbackTest" // Ustaw nazwę tagu dla logów
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__) // Log poziomu INFO
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__) // Log poziomu ERROR

typedef void (*Callback)(const char*);

typedef int (*CallbackProcessImage)(char* inage, int width, int height);

// Global
static Callback registered_callback = NULL;
static CallbackProcessImage registered_callbackProcessImage = NULL;

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_registerCallbackInLibrary2(JNIEnv *env, jobject obj, jlong functionPointer) {
    registered_callback = (Callback)functionPointer;
    LOGI("Callback registered successfully [registered_callback].");
}

JNIEXPORT void JNICALL
Java_com_example_nativecallbacktest_NativeInterop_registerCallbackInLibrary2ProcessImage(JNIEnv *env, jobject obj, jlong functionPointer) {
    registered_callbackProcessImage = (CallbackProcessImage)functionPointer;
    LOGI("Callback registered successfully [registered_callbackProcessImage].");
}

void leltek_ProcessImage()
{
    char img[4] = {1,2,3,4};

    LOGI("Image BEFORE %d %d %d %d.\n", img[0],img[1],img[2],img[3]);

    if (registered_callbackProcessImage != NULL)
    {
        int result = registered_callbackProcessImage(img, 2, 2);
    }
    LOGI("Image AFTER %d %d %d %d.\n", img[0],img[1],img[2],img[3]);

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

    leltek_ProcessImage();
}
