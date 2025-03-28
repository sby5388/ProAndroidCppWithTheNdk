//
// Created by ZN200762 on 2025/3/28.
//

#ifndef PROANDROIDCPPWITHTHENDK_LANDFACE_H
#define PROANDROIDCPPWITHTHENDK_LANDFACE_H


class LandFace {
public:
    LandFace();

    ~LandFace();

    double getX1() const;

    void setX1(double x1);

    double getY1() const;

    void setY1(double y1);

    double getZ1() const;

    void setZ1(double z1);

    double getX2() const;

    void setX2(double x2);

    double getY2() const;

    void setY2(double y2);

    double getZ2() const;

    void setZ2(double z2);

    double getX3() const;

    void setX3(double x3);

    double getY3() const;

    void setY3(double y3);

    double getZ3() const;

    void setZ3(double z3);


private:
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;

};


#endif //PROANDROIDCPPWITHTHENDK_LANDFACE_H
