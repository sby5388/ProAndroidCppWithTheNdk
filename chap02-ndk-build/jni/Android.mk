LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hello-jni
LOCAL_SRC_FILES := hello-jni.c
LOCAL_LDLIBS:=-llog

#生成代理类的包
MY_SWIG_PACKAGE := com.shenby.swig
#应该处理的SWIG接口文件列表
MY_SWIG_INTERFACES := Unix.i
#SWIG生成封装程序的指令代码类型，为C或者C++
MY_SWIG_TYPE := c

#包含构建swig
include $(LOCAL_PATH)/my_swig_generate.mk

#生成代理类的包
MY_SWIG_PACKAGE := com.shenby.swig
#应该处理的SWIG接口文件列表
MY_SWIG_INTERFACES := MyEnum.i
#SWIG生成封装程序的指令代码类型，为C或者C++
MY_SWIG_TYPE := c

#包含构建swig
include $(LOCAL_PATH)/my_swig_generate.mk

#生成代理类的包
MY_SWIG_PACKAGE := com.shenby.swig
#应该处理的SWIG接口文件列表
MY_SWIG_INTERFACES := MyStruct.i
#SWIG生成封装程序的指令代码类型，为C或者C++
MY_SWIG_TYPE := c

#包含构建swig
include $(LOCAL_PATH)/my_swig_generate.mk

#todo 生成cpp
#生成代理类的包
MY_SWIG_PACKAGE := com.shenby.swig
#应该处理的SWIG接口文件列表
MY_SWIG_INTERFACES := CppStruct.i
#SWIG生成封装程序的指令代码类型，为C或者C++
MY_SWIG_TYPE := cxx
include $(LOCAL_PATH)/my_swig_generate.mk

#生成代理类的包
MY_SWIG_PACKAGE := com.shenby.swig
#应该处理的SWIG接口文件列表
MY_SWIG_INTERFACES := CppClass.i
#SWIG生成封装程序的指令代码类型，为C或者C++
MY_SWIG_TYPE := cxx
include $(LOCAL_PATH)/my_swig_generate.mk


include $(BUILD_SHARED_LIBRARY)

ifdef Unix_wrap
#只是起引用作用而已,不会编译动态库
include $(CLEAR_VARS)
LOCAL_MODULE := Unix_wrap
LOCAL_SRC_FILES := Unix_wrap.c
include $(BUILD_SHARED_LIBRARY)
endif


