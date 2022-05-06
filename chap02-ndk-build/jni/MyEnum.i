/** 模块名称是MyEnum. */
%module MyEnum

%{
#include "my_enums.h"

%}

/** 匿名枚举,为每个枚举生成final静态变量*/
enum {
    ONE = 1, TWO = 2, THREE, FOUR
};

/** 命名枚举：类型安全，生成常量类*/
enum Numbers {
    A = 1, B = 2, C, D
};

/** 通过enumtypeunsafe.swg 将命名枚举标记为不安全，生成常量，可以用于switch */
%include "enumtypeunsafe.swg"
enum UnsafeNumbers {
    U1 = 11, U2 = 12, U3, U4
};

/** 使用 enums.swg 标记为 Java 枚举*/
%include "enums.swg"

enum Week {
    SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

/** */