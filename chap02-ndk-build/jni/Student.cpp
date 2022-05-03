//
// Created by shenby07 on 2022/5/3.
//

#include "Student.hpp"
#include "android_log.h"


Student::Student() : id(0), weight(0) {
    LOGD("Student()");
}

Student::Student(int id, double weight) : id(id), weight(weight) {
    LOGD("Student(int %d, double %.2f)",id,weight);
}

Student::Student(int id) : id(id), weight(0) {
    LOGD("Student(int %d)",id);
}

Student::~Student() = default;

void Student::show() {
     LOGD("Student show id = %d,weight = %.2f",id,weight);
}

void Student::reset() {
    LOGD("Student reset ");
    id = -1;
    weight = 0;
}