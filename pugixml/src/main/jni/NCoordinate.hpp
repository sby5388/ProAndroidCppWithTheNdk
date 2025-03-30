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
    NCoordinate() : id(0), x(0), y(0), z(0) {}

    NCoordinate(int id, double x, double y, double z) : id(id), x(x), y(y), z(z) {}
};

#endif //PROANDROIDCPPWITHTHENDK_NCOORDINATE_HPP
