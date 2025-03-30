package com.shenby.readlandxml

import com.shenby.swig.LandFace

fun LandFace.show(): String {
    return "landFace=x1=${x1},y1=${y1},z1=${z1},\nx2=${x2},y2=${y2},z2=${z2},\nx3=${x3},y3=${y3},z3=${z3}"
}