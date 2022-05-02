
#include "my_struct_cpp.hpp"
#include "android_log.h"

/**
 * 传递参数：通过指针.
 */
void drawByPointer(struct PointCpp *p) {
    LOGD("drawByPointer x = %d , y =%d\n", p->x, p->y);
}

/**
 * 传递参数：通过引用.
 */
void drawByReference(struct PointCpp &p) {
    LOGD("drawByReference x = %d , y =%d\n", p.x, p.y);
}

/**
 * 传递参数：通过值
 */
void drawByValue(struct PointCpp pointCpp) {
    LOGD("drawByValuex = %d , y =%d\n", pointCpp.x, pointCpp.y);
}

/**
 * 默认参数的函数
 */
void func(int a, int b, int c) {
    LOGD("a = %d, b = %d, c = %d, sum = %d\n", a, b, c, a + b + c);
}