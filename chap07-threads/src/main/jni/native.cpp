//
// Created by shenby07 on 2022/5/10.
//
//定义使用信号量来同步线程
//#define USE_SEM 1

#include <jni.h>
#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include "com_shenby_pacwth_chap07_threads_MainActivity.h"

#if USE_SEM

#include <semaphore.h>

#endif

/**
 * 原生worker线程参数
 */
struct NativeWorkerArgs {
    jint id;
    jint iterations;

};

/**
 * 缓存java的方法id
 */
static jmethodID gOnNativeMessage = nullptr;

/**
 * Java 虚拟机接口指针
 */
static JavaVM *gVm = nullptr;

/**
 * 对象全局引用
 */
static jobject gObj = nullptr;

#if USE_SEM
/**
 * 信号量实例
 */
static sem_t sem;
#else
/**
 * 互斥锁实例
 */
static pthread_mutex_t mutex;
#endif


//C++按C语言来编译
extern "C" {
/**
 * 为原生worker线程添加启动程序
 * @param args
 * @return
 */
static void *nativeWorkerThread(void *args);

/**
 * 当共享库开始加载虚拟机时，会自动调用该函数
 * @param vm java虚拟机接口指针
 * @param reserved
 * @return
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    //缓存Java虚拟机接口指针
    gVm = vm;
    //todo 各个版本之间有什么差异吗
    return JNI_VERSION_1_6;
}


JNIEXPORT void JNICALL
Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeInit
        (JNIEnv *env, jobject obj) {

#if USE_SEM
    //初始化信号量
    //sem_init:第二个参数：0：只在该进程内的多个线程共享该信号量（linux只支持这个？）；其他值：多进程共享该信号量
    //第三个参数：信号量大小：最多同时有多少个线程进入被锁的代码块
    if (0 != sem_init(&sem, 0, 2)) {
        //获取异常类
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        //抛出异常
        env->ThrowNew(pJclass, "Unable to initialize sem");
        goto exit;
    }
#else

    //初始化互斥锁
    //pthread_mutex_init:第一个参数：需要初始化互斥锁变量的指针；第二个参数是互斥锁属性的结构指针，为空时使用默认值
    //返回0：初始化成功并处于锁打开的状态，否则其他值为失败
    if (0 != pthread_mutex_init(&mutex, nullptr)) {
        //获取异常类
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        //抛出异常
        env->ThrowNew(pJclass, "Unable to initialize mutex");
        goto exit;
    }

#endif

    if (gOnNativeMessage == nullptr) {
        //从对象中获取类
        jclass pJclass = env->GetObjectClass(obj);
        //为回调获取方法id
        gOnNativeMessage = env->GetMethodID(pJclass, "onNativeMessage", "(Ljava/lang/String;)V");

        if (nullptr == gObj) {
            //为对象创建一个新的全局引用
            gObj = env->NewGlobalRef(obj);
            if (gObj == nullptr) {
                //创建失败
                goto exit;
            }
        }


        //如果方法没有找到
        if (gOnNativeMessage == nullptr) {
            //获取异常类
            jclass exceptionClazz = env->FindClass("java/lang/RuntimeException");
            //抛出异常
            env->ThrowNew(exceptionClazz, "Unable to find Method");
        }
    }

    exit:
    {
        return;
    }
}
JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeFree
        (JNIEnv *env, jobject obj) {
    //删除全局引用，否则会发生内存泄露；对象无法在正确的时间点被回收
    if (nullptr != gObj) {
        //删除全局引用
        env->DeleteGlobalRef(gObj);
        gObj = nullptr;
    }

#if USE_SEM
    //销毁信号量
    //销毁一个另一个线程正在阻塞的信号量有可能导致未知的行为
    //0：成功；其他：失败
    if (0 != sem_destroy(&sem)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to destroy sem");
    }
#else
    //销毁互斥锁
    if (0 != pthread_mutex_destroy(&mutex)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to destroy mutex");
    }
#endif
}

//每隔一秒发送一个语句（反射调用JAVA）
JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeWorker
        (JNIEnv *env, jobject obj, jint id, jint iterations) {

#if USE_SEM
    //锁定信号量
    //如果当前信号量的值大于0，上锁成功，并且信号量的值递减；如果信号量的值为0，那么则挂起
    //返回0：成功；否则失败
    if (0 != sem_wait(&sem)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to lock sem(swm_wait)");
        goto exit;
    }

#else
    //锁定互斥锁
    //对一个已经初始化的互斥锁进行封锁操
    //如果互斥锁已经被锁上，那么调用线程将被挂起知道到互斥锁被打开；如果返回0成功，否则失败
    if (0 != pthread_mutex_lock(&mutex)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to lock mutex");
        goto exit;
    }
#endif

    //循环给定的迭代数
    for (jint i = 0; i < iterations; ++i) {
        //准备消息
        char message[26];
        //todo 这个函数的作用:将格式化后的文本内容写入到message这个数组中
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

#if USE_SEM
    //解锁信号量
    //解锁信号量之后，信号量的值会+1
    //返回0：成功；否则失败
    if (0 != sem_post(&sem)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to unlock sem(sem_post)");
        goto exit;
    }

#else
    //解锁互斥锁
    //调度策略决定解锁后执行哪个等待互斥锁的线程
    //返回0：成功，否则失败
    if (0 != pthread_mutex_unlock(&mutex)) {
        jclass pJclass = env->FindClass("java/lang/RuntimeException");
        env->ThrowNew(pJclass, "Unable to unlock mutex");
        goto exit;
    }
#endif

    exit:
    {
        return;
    };

}

JNIEXPORT void JNICALL Java_com_shenby_pacwth_chap07_threads_MainActivity_posixThreads
        (JNIEnv *env, jobject obj, jint threads, jint iterations) {
    //线程句柄
    pthread_t *handles = new pthread_t[threads];
    //为每个Worker创建一个POSIX线程
    for (jint i = 0; i < threads; ++i) {
        //原生线程参数
        NativeWorkerArgs *nativeWorkerArgs = new NativeWorkerArgs();
        nativeWorkerArgs->id = i;
        nativeWorkerArgs->iterations = iterations;

        //创建一个新线程，返回0成功，否则错误
        //第二个参数为线程属性，这里是默认值，为Null
        //第三个参数：相当于传入了一个函数指针，如同传入一个Runnable
        //第四个参数：真正的参数
        int result = pthread_create(&handles[i],
                                    nullptr,
                                    nativeWorkerThread,
                                    (void *) nativeWorkerArgs);
        if (result != 0) {
            //获取异常类
            jclass pJclass = env->FindClass("java/lang/RuntimeException");
            //抛出异常类
            env->ThrowNew(pJclass, "Unable to create thread");
            goto exit;
        }
    }

    //等待线程终止
    for (jint i = 0; i < threads; ++i) {
        void *result = nullptr;
        //pthread_join:挂起线程的执行，直到线程执行完成；返回0时执行成功，否则失败
        //连接每个线程句柄
        if (0 != pthread_join(handles[i], &result)) {
            //获取异常类
            jclass pJclass = env->FindClass("java/lang/RuntimeException");
            //抛出异常类
            env->ThrowNew(pJclass, "Unable to join thread");
        } else {
            //准备消息
            char message[26];
            //todo 这个函数的作用:将格式化后的文本内容写入到message这个数组中
            sprintf(message, "Worker %d:returned %d", i, result);
            //来自C字符串的消息
            jstring messageString = env->NewStringUTF(message);
            //调用原生方法
            env->CallVoidMethod(obj, gOnNativeMessage, messageString);
            //检查是否产生异常
            if (nullptr != env->ExceptionOccurred()) {
                goto exit;
            }
        }
    }

    exit:
    {
        return;
    };
}
static void *nativeWorkerThread(void *args) {
    JNIEnv *env = nullptr;
    //将当前线程附加到Java虚拟机上
    //并且获得JNIENV接口指针
    if (0 == gVm->AttachCurrentThread(reinterpret_cast<void **>(&env), nullptr)) {
        //获取原生worker参数
        NativeWorkerArgs *pArgs = (NativeWorkerArgs *) args;
        //在线程上下文中运行原生worker
        Java_com_shenby_pacwth_chap07_threads_MainActivity_nativeWorker(env,
                                                                        gObj,
                                                                        pArgs->id,
                                                                        pArgs->iterations);
        //删除原生worker线程参数;与 new 配合使用
        delete pArgs;
        //从Java虚拟机中分离当前线程
        gVm->DetachCurrentThread();
    }
    return (void *) 1;

}


}


