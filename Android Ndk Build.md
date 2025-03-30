Android Ndk Build 脚本文件的格式说明
在ndk-build构建过程中，需要使用到的2个文件是Android.mk和Application.mk

## Android.mk
例子采用既有的chap02-ndk-build的jni/Android.mk
``
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := hello-jni
LOCAL_SRC_FILES := hello-jni.c
include $(BUILD_SHARED_LIBRARY)
`

```shell


```

