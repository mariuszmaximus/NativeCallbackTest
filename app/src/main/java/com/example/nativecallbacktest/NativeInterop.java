package com.example.nativecallbacktest;

public class NativeInterop {
    static {
        System.loadLibrary("library1");
        System.loadLibrary("library2");
    }

    public native long getCallbackFunctionPointer();
    public native long getCallbackFunctionPointerProcessImage();
    public native void registerCallbackInLibrary2(long functionPointer);

    public native void registerCallbackInLibrary2ProcessImage(long functionPointer);
    public native void triggerCallback();

    public static void main(String[] args) {
        NativeInterop interop = new NativeInterop();

        // Pobierz wskaźnik do funkcji callback z library1
        long callbackPointer = interop.getCallbackFunctionPointer();

        // Zarejestruj callback w library2
        interop.registerCallbackInLibrary2(callbackPointer);

        // Wywołaj callback w library2
        interop.triggerCallback();
    }
}
