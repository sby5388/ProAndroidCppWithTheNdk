//
// Created by ZN200762 on 2025/9/29.
//

#include "NCoordinate.hpp"
int coordinateCount = 0;
// 默认构造函数
NCoordinate::NCoordinate() : id(0), x(0), y(0), z(0) {
    coordinateCount++;
}

NCoordinate::NCoordinate(int id, double x, double y, double z) : id(id), x(x), y(y), z(z) {
    coordinateCount++;
}

NCoordinate::~NCoordinate() {
    coordinateCount--;
}