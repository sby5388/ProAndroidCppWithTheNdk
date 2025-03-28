/** cpp */
%module LandXml
%{
//#include "LandFace.h"
#include "./pugixml-1.15/src/pugixml.hpp"
#include "LandXmlReader.hpp"

%};
%include "std_string.i" // 包含 SWIG 对 std::string 的支持
%include "arrays_java.i"
%typemap(jni) double* "jdoubleArray"
%typemap(jtype) double* "double[]"
%typemap(jstype) double* "double[]"
%typemap(javaout) double* {
return $jnicall;
}


%include "LandXmlReader.hpp"