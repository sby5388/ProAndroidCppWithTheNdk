/** cpp */
%module(directors = 1) LandXml
%{
//#include "LandFace.h"
#include "./pugixml115/src/pugixml.hpp"
#include "NCoordinate.hpp"
#include "LandXmlReadProgressListener.h"
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

/* turn on director wrapping Callback */
%feature("director") LandXmlReadProgressListener;

%include "LandXmlReadProgressListener.h"
%include "LandFace.h"
%include "NCoordinate.hpp"
%include "LandXmlReader.hpp"