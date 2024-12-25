#include <jni.h>
#include <stdio.h>
#include <android/log.h> // Dodaj ten nagłówek

#define LOG_TAG "NativeCallbackTest" // Ustaw nazwę tagu dla logów
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__) // Log poziomu INFO
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__) // Log poziomu ERROR

void library1_callback(const char* message) {
    LOGI("!!!!!!!!!!!!!!!!!! LIBRARY 1 ");

    printf("Library1 callback: %s\n", message);
}

int library1_callback_ProcessImage(char* image, int width,int height)
{
    int l = width * height;
    for (int i=0; i < width * height; i++ )
    {
        image[i] = image[i] * 10;
    }
    printf("Library1 library1_callback_processImage  %d x %d\n", width, height);
    return 0;
}

JNIEXPORT jlong JNICALL
Java_com_example_nativecallbacktest_NativeInterop_getCallbackFunctionPointerProcessImage(JNIEnv *env, jobject obj) {
    return (jlong)&library1_callback_ProcessImage; // Zwracamy wskaźnik do funkcji
}

JNIEXPORT jlong JNICALL
Java_com_example_nativecallbacktest_NativeInterop_getCallbackFunctionPointer(JNIEnv *env, jobject obj) {
    return (jlong)&library1_callback; // Zwracamy wskaźnik do funkcji
}
