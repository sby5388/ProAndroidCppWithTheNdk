//
// Created by shenby07 on 2022/5/2.
//

#ifndef PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP
#define PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP
//fixme 20220502 这里出错了，
//  使用"#include <iostream>" using namespace std;
//  使用 cout<<"sss"<<endl;时 一直报错

#include <cstdio>

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

#endif //PROANDROIDCPPWITHTHENDK_MY_STRUCT_CPP_HPP
