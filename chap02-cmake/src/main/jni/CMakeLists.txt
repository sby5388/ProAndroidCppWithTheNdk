cmake_minimum_required(VERSION 3.4.1)

#参考来源 https://blog.csdn.net/u011609853/article/details/105019452
#寻找swig
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
#
## 查找所有 .cxx 和 .h 文件
#file(GLOB JNI_FILES "./../../../swig/jni/*.cxx" "./../../../swig/jni/*.h")
#
## 查找指定目录中的所有 .c 文件
#file(GLOB ADDITIONAL_FILES "./../../../swig/jni/*.c")
#
## 将所有文件添加到库中
#add_library(hello-jni  SHARED ${JNI_FILES} ${ADDITIONAL_FILES})

#add_subdirectory("pugixml-1.15")

#add_library(pugixml
#        STATIC
#        ./pugixml-1.15/src/pugixml.cpp
#)
#
#add_library(landXml SHARED LandXmlReader.cpp LandFace.cpp)

add_library(hello-jni SHARED
        Unix_wrap.c
        MyEnum_wrap.c
        MyStruct_wrap.c
        CppStruct_wrap.cxx
        my_struct_cpp.cpp
        CppClass_wrap.cxx
        Student.cpp
        AsyncProvider_wrap.cxx
        AsyncUidProvider.cpp
        hello-jni.c)

# Include libraries needed for hello-jni lib
target_link_libraries(hello-jni
        android
        #下一行是链接了Android的日志模块 log
        log)

#target_link_libraries(landXml
#        pugixml
#        #下一行是链接了Android的日志模块 log
#        log)
