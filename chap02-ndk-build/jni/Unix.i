/* 模块名称是Unix. */
%module Unix

%{
/* 包含POSIX 操作系统API */
#include <unistd.h>
#include "my_number.h"

%}

/* 告诉SWIG uid_t */
typedef unsigned int uid_t;

/* 让SWIG 包装 getuid 函数 (定义在unistd.h中)*/
extern uid_t getuid(void);

/* 全局变量 counter */
extern int counter;
