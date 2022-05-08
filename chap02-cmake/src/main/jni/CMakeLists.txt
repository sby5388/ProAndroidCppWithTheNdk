cmake_minimum_required(VERSION 3.4.1)

#参考来源 https://blog.csdn.net/u011609853/article/details/105019452
#寻找swig
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

add_library(hello-jni SHARED
        Unix_wrap.c
        MyEnum_wrap.c
        MyStruct_wrap.c
        CppStruct_wrap.cxx
        my_struct_cpp.cpp
        CppClass_wrap.cxx
        Student.cpp
        hello-jni.c)

# Include libraries needed for hello-jni lib
target_link_libraries(hello-jni
        android
        #下一行是链接了Android的日志模块 log
        log)
