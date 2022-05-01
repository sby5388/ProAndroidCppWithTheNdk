package com.example.hellojni;

public class HelloJni {

    static {
        System.loadLibrary("hello-jni");
    }

    public HelloJni() {
    }

    public native String stringFromJNI();
}
