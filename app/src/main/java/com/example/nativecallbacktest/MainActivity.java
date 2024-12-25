package com.example.nativecallbacktest;

import android.os.Bundle;
import android.util.Log;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "NativeCallbackTest";

    static {
        System.loadLibrary("draminski");
        System.loadLibrary("leltek");
    }

    private NativeInterop nativeInterop = new NativeInterop();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Zarejestruj i wywołaj callback
        long callbackPointer = nativeInterop.getCallbackFunctionPointer();
        nativeInterop.registerCallbackInLibrary2(callbackPointer);

        long callbackPointerProcessImage = nativeInterop.getCallbackFunctionPointerProcessImage();
        nativeInterop.registerCallbackInLibrary2ProcessImage(callbackPointerProcessImage);


        nativeInterop.triggerCallback();

        Log.d(TAG, "Callback test finished");
    }
}
