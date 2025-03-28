//
// Created by ZN200762 on 2025/3/28.
//

#ifndef PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP
#define PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP

#include "./pugixml-1.15/src/pugixml.hpp"
#include <string>
#include <vector>

using namespace std;


class LandXmlReader {
public:
    LandXmlReader();

    ~LandXmlReader();

    /**
     * 设置路径
     * @param path 文件路径
     */
    void setLandXml(const string &path);

    /**
     * 读取数据
     * @return
     */
    bool readData();

    /**
     * 获取三角网的数量
     * @return
     */
    long getCount();


    /**
     * 获取某个面(包含三个点)
     */
    double *getSjwData(long index);

    /**
     * 关闭
     */
    void close();

private:
    pugi::xml_document doc;
    pugi::xml_parse_result result;

};


#endif //PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP
