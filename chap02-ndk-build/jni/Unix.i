/** 模块名称是Unix. */
%module Unix

%{
/** 包含POSIX 操作系统API */
#include <unistd.h>
#include "my_number.h"

%}

/** 告诉SWIG uid_t */
typedef unsigned int uid_t;

/** getuid 函数的异常处理,要写在函数名称的前面,改变输出的c语言 */
%exception getuid{
    $action
    if(!result){
        jclass clazz = (*jenv)->FindClass(jenv, "java/lang/OutOfMemoryError");
        (*jenv) -> ThrowNew(clazz, "Out of Memory");
        return $null;
    }
}
/** getuid的java异常处理，改变输出的java语言 */
%javaexception("java.lang.IllegalAccessException") getuid{
    $action
    if(!result){
        jclass clazz = (*jenv)->FindClass(jenv, "java/lang/IllegalAccessException");
        (*jenv)->ThrowNew(jenv, clazz, "IllegalAccess");
        return $null;
    }
}


/** 让SWIG 包装 getuid 函数 (定义在unistd.h中)*/
extern uid_t getuid(void);

/** 全局变量 counter */
extern int counter;

/** 常量会生成一个 module + Constant 的java接口文件 */
/** 使用define指令定义的常量 */
#define MAX_WIDTH 640

/** 使用%constant 指令定义的常量 */
%constant int MAX_HEIGHT = 320;

/** 可以使用%javaconst预处理指令修改常量的值 */
/** 如果是0(也是默认值)，那么跟生成的 值跟上面一致，也是从 native方法中获取*/
/** 如果是1，那么把值直接写入到java文件中，无需通过native获取 */
/** 用定义指令定义常量 */
%javaconst(1);
#define MIN_WIDTH 320
/** 使用%constant 指令定义的常量 */
%javaconst(0);
%constant int MIN_HEIGHT = 160;

/** 使用 %immutable预处理指令来标记一个只读变量 */
/** 只读变量只会生成getter(),而读写变量会生成getter和setter */
/** 启用只读模式*/
%immutable;
/** 声明只读变量*/
extern int readOnly;
/** 禁用只读模式*/
%mutable;
/** 声明读写变量*/
extern int readWrite;

/** */

