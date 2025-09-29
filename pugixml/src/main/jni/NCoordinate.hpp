//
// Created by shenby07 on 2025/3/30.
//

#ifndef PROANDROIDCPPWITHTHENDK_NCOORDINATE_HPP
#define PROANDROIDCPPWITHTHENDK_NCOORDINATE_HPP


class NCoordinate {
public:
    int id;
    double x, y, z;

    // 默认构造函数
    NCoordinate();
    // 带参数的构造函数
    NCoordinate(int id, double x, double y, double z);

    ~NCoordinate();

};

#endif //PROANDROIDCPPWITHTHENDK_NCOORDINATE_HPP
