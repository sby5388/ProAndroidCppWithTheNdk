/** cpp */
%module LandXml
%{
//#include "LandFace.h"
#include "./pugixml115/src/pugixml.hpp"
#include "LandXmlReader.hpp"
#include "LandFace.h"

%};
%include "std_string.i" // 包含 SWIG 对 std::string 的支持
%include "arrays_java.i"
%typemap(jni) double* "jdoubleArray"
%typemap(jtype) double* "double[]"
%typemap(jstype) double* "double[]"
%typemap(javaout) double* {
return $jnicall;
}

%include "LandFace.h"
%include "LandXmlReader.hpp"