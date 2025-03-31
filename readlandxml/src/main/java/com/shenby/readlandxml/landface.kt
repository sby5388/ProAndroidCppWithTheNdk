package com.shenby.readlandxml

import com.shenby.swig.LandFace
import java.util.Locale

fun LandFace.show(): String {



    return "landFace={x1=${x1.format()},y1=${y1.format()},z1=${z1.format()},\n" +
            "x2=${x2.format()},y2=${y2.format()},z2=${z2.format()},\n" +
            "x3=${x3.format()},y3=${y3.format()},z3=${z3.format()}}"
}

fun Double.format(digits: Int = 6) = String.format(Locale.ENGLISH, "%.${digits}f", this)