//
// Created by shenby07 on 2022/5/2.
//

#ifndef PROANDROIDCPPWITHTHENDK_MY_ENUMS_H
#define PROANDROIDCPPWITHTHENDK_MY_ENUMS_H

/**
 * 匿名枚举
 */
enum {
    ONE = 1, TWO = 2, THREE, FOUR
};

/**
 * 命名枚举
 */
enum Numbers {
    A = 1, B = 2, C, D
};

/**
 * 被标记位不安全的枚举
 */
enum UnsafeNumbers {
    U1 = 11, U2 = 12, U3, U4
};

/**
 * 将被标记位java枚举
 */
enum Week {
    SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

#endif //PROANDROIDCPPWITHTHENDK_MY_ENUMS_H
