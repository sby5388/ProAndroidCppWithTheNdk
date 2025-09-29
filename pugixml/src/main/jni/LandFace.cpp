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


