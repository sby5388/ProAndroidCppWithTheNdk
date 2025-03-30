//
// Created by shenby07 on 2022/5/14.
//
#include <stdarg.h>
#include <stdio.h>

/**
 * 打印可变参数
 * @param args 可变参数的数量 
 * @param ... 
 */
void print_ints(int args, ...);

int main() {
    print_ints(3, 10, 20, 40);
    return 0;
}

void print_ints(int args, ...) {
    //用于接收可变参数
    va_list ap;
    //可变参数从哪里开始:
    va_start(ap, args);
    int i;
    for (int i = 0; i < args; ++i) {
        int value = va_arg(ap,
        int);
        printf("argument : %i\n", value);
    }
    //结束：销毁可变参数
    va_end(ap);


}
