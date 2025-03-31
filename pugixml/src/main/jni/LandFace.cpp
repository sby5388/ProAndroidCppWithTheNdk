//
// Created by ZN200762 on 2025/3/28.
//

#include "LandFace.h"
int landFaceCount = 0;

LandFace::LandFace() : x1(0), y1(0), z1(0), x2(0), y2(0), z2(0), x3(0), y3(0), z3(0) {
    landFaceCount++;
}


LandFace::~LandFace() {
    landFaceCount--;
}
//
//double LandFace::getX1() const {
//    return x1;
//}
//
//void LandFace::setX1(double x1) {
//    LandFace::x1 = x1;
//}
//
//double LandFace::getY1() const {
//    return y1;
//}
//
//void LandFace::setY1(double y1) {
//    LandFace::y1 = y1;
//}
//
//double LandFace::getZ1() const {
//    return z1;
//}
//
//void LandFace::setZ1(double z1) {
//    LandFace::z1 = z1;
//}
//
//double LandFace::getX2() const {
//    return x2;
//}
//
//void LandFace::setX2(double x2) {
//    LandFace::x2 = x2;
//}
//
//double LandFace::getY2() const {
//    return y2;
//}
//
//void LandFace::setY2(double y2) {
//    LandFace::y2 = y2;
//}
//
//double LandFace::getZ2() const {
//    return z2;
//}
//
//void LandFace::setZ2(double z2) {
//    LandFace::z2 = z2;
//}
//
//double LandFace::getX3() const {
//    return x3;
//}
//
//void LandFace::setX3(double x3) {
//    LandFace::x3 = x3;
//}
//
//double LandFace::getY3() const {
//    return y3;
//}
//
//void LandFace::setY3(double y3) {
//    LandFace::y3 = y3;
//}
//
//double LandFace::getZ3() const {
//    return z3;
//}
//
//void LandFace::setZ3(double z3) {
//    LandFace::z3 = z3;
//}
//



