//
// Created by shenby07 on 2022/5/10.
//
#include <jni.h>
#include <cstdio>
#include <unistd.h>
#include "com_shenby_pacwth_chap07_threads_MainActivity.h"

/**
 * 缓存java的方法id
 */
static jmethodID gOnNativeMessage = nullptr;

extern "C" {

JNIEXPORT void JNICALL
Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeInit
        (JNIEnv *env, jobject obj) {
    if (gOnNativeMessage == nullptr) {
        //从对象中获取类
        jclass pJclass = env->GetObjectClass(obj);
        //为回调获取方法id
        gOnNativeMessage = env->GetMethodID(pJclass, "onNativeMessage", "(Ljava/lang/String;)V");

        //如果方法没有找到
        if (gOnNativeMessage == nullptr) {
            //获取异常类
            jclass exceptionClazz = env->FindClass("java/lang/RuntimeException");
            //抛出异常
            env->ThrowNew(exceptionClazz, "Unable to find Method");
        }
    }
}
JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeFree
        (JNIEnv *env, jobject obj) {
    //todo
}

//每隔一秒发送一个语句（反射调用JAVA）
JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeWorker
        (JNIEnv *env, jobject obj, jint id, jint iterations) {
    //循环给定的迭代数
    for (jint i = 0; i < iterations; ++i) {
        //准备消息
        char message[26];
        //todo 这个函数的作用
        sprintf(message, "Worker %d:Iteration %d", id, i);
        //来自C字符串的消息
        jstring messageString = env->NewStringUTF(message);
        //调用原生方法
        env->CallVoidMethod(obj, gOnNativeMessage, messageString);
        //检查是否产生异常
        if (nullptr != env->ExceptionOccurred()) {
            break;
        }
        //睡眠1秒
        sleep(1);
    }
}

JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_posixThreads
        (JNIEnv *env, jobject obj, jint threads, jint iterations) {
    //todo
}

}


