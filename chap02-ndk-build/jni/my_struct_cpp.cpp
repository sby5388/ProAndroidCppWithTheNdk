
#include "my_struct_cpp.hpp"
#include <cstdio>

//todo 这里的打印一直没有生效
/**
 * 传递参数：通过指针.
 */
void drawByPointer(struct PointCpp *p) {
//    pr<<"drawByPointer"<<endl;
    printf("drawByPointer x = %d , y =%d\n", p->x, p->y);
}

/**
 * 传递参数：通过引用.
 */
void drawByReference(struct PointCpp &p) {
//cout<<"drawByReference"<<endl;
    printf("drawByReference x = %d , y =%d\n", p.x, p.y);
}

/**
 * 传递参数：通过值
 */
void drawByValue(struct PointCpp pointCpp) {
    //cout<<"drawByValue"<<endl;
    printf("drawByValuex = %d , y =%d\n", pointCpp.x, pointCpp.y);
}