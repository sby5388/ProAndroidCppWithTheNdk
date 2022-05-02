/** cpp */
%module CppStruct

%{
#include "my_struct_cpp.hpp"
/** todo 这里还要导入cpp文件，否着编译不通过 */
#include "my_struct_cpp.cpp"

%}

struct PointCpp {
    int x;
    int y;
};

/**
 * 传递参数：通过指针.
 */
extern void drawByPointer(struct PointCpp *p);

/**
 * 传递参数：通过引用.
 */
extern void drawByReference(struct PointCpp

& p);

/**
 * 传递参数：通过值
 */
extern void drawByValue(struct PointCpp pointCpp);
