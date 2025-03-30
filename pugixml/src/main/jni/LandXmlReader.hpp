//
// Created by ZN200762 on 2025/3/28.
//

#ifndef PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP
#define PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP

#include "./pugixml115/src/pugixml.hpp"
#include "LandFace.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "NCoordinate.hpp"

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
     * 加载某一个序号的面对象
     * @param index
     * @return
     */
    LandFace* loadLandFace(long index);

    /**
     * 关闭
     */
    void close();

private:
    pugi::xml_document doc;
    pugi::xml_parse_result result;
    // 存储 ID-NCoordinate 的映射
    std::unordered_map<int, NCoordinate> coordinateMap;
    std::vector<LandFace> landFaces;

    LandFace emptyFace;

};


#endif //PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP
