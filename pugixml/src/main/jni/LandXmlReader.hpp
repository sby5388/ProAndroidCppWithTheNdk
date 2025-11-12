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
#include "LandXmlReadProgressListener.h"

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
     * 检查xml文件的数据是否合规
     * @return
     */
    bool checkFileContent();

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

    double getArea2d();
    double getArea3d();
    double getElevMax();
    double getElevMin();

    /**
     * 加载某一个序号的面对象
     * @param index
     * @return
     */
    LandFace *loadLandFace(long index);


    long getCoordinateCount();

    NCoordinate *loadNCoordinate(long index);

    /**
     * 关闭
     */
    void close();

    void setListener(LandXmlReadProgressListener *listener);

    void deleteListener();

private:
    pugi::xml_document doc;
    pugi::xml_parse_result result;

    std::vector<LandFace*> landFaces;
    /**
     * 存放三角网节点数据
     */
    std::vector<NCoordinate*> coordinates;

    LandFace *emptyFace;

    NCoordinate *emptyCoordinate;

    LandXmlReadProgressListener *listener;
    bool hasClosed = false;

    double area2d = 0.0;
    double area3d = 0.0;
    double elevMin = 0.0;
    double elevMax = 0.0;

};


#endif //PROANDROIDCPPWITHTHENDK_LANDXMLREADER_HPP
