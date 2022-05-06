/** 模块名称是MyStruct. */
%module MyStruct

%{
#include "my_struct.h"

%}
/** Point 结构体*/
struct Point {
    int x;
    int y;
};