//
// Created by shenby07 on 2022/5/3.
//

#ifndef PROANDROIDCPPWITHTHENDK_STUDENT_HPP
#define PROANDROIDCPPWITHTHENDK_STUDENT_HPP


class Student {
public:
    Student();

    Student(int id);

    Student(int id, double weight);

    ~Student();

    void show();

    int id;
private:
    /** 私有的方法不会展示到java中 */
    void reset();
    /** 私有的属性不会生成getter()和setter() */
    double weight;
};


#endif //PROANDROIDCPPWITHTHENDK_STUDENT_HPP
