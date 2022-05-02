//
// Created by shenby07 on 2022/5/2.
//

#ifndef PROANDROIDCPPWITHTHENDK_BY_NUMBER_H
#define PROANDROIDCPPWITHTHENDK_BY_NUMBER_H
/**
 * 定义一个全局变量 counter，供 Unix.i调用
 */

int counter = 0;
/**
 * 只读全局变量
 */
const int readOnly = 100;
/**
 * 全局读写变量
 */
int readWrite = 200;

#endif //PROANDROIDCPPWITHTHENDK_BY_NUMBER_H
