/** cpp class */
%module CppClass

%{
#include "Student.hpp"
/** todo 这里还要导入cpp文件，否着编译不通过 */
#include "Student.cpp"

%}

%include "Student.hpp"