//
// Created by shenby07 on 2022/5/2.
//

#ifndef PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP
#define PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP

/**
 * swig 生成 C++
 */
struct PointCpp {
    int x;
    int y;
};

/**
 * 传递参数：通过指针.
 */
void drawByPointer(struct PointCpp *p);

/**
 * 传递参数：通过引用.
 */
void drawByReference(struct PointCpp &p);

/**
 * 传递参数：通过值
 */
void drawByValue(struct PointCpp pointCpp);

/**
 * 默认参数的函数
 */
void func(int a = 1, int b = 2, int c = 3);

#endif //PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP
