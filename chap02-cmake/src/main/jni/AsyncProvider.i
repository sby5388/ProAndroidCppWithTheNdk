/** 模块名称是AsyncProvider. */
/** directors:提供对交叉语言多态性的支持，默认是关闭的 */
%module(directors = 1) AsyncProvider

/** 启用 AsyncUidProvider 的directors */
%feature("director") AsyncUidProvider;

%{
/** 包含POSIX 操作系统API */
#include <unistd.h>
#include "AsyncUidProvider.hpp"

%}

%include "AsyncUidProvider.hpp"