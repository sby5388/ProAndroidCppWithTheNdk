//
// Created by ZN200762 on 2025/3/28.
//

//#include "./pugixml-1.15/src/pugixml.hpp"
#include "LandXmlReader.hpp"
#include "android_log.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


LandXmlReader::LandXmlReader() {
}

LandXmlReader::~LandXmlReader() {
    close();
}


bool LandXmlReader::readData() {
    cout << result.description() << endl;
    if (!result) {
        LOGE("Error loading XML file:%s\n", result.description());
        return false;
    }
    const pugi::xml_node &nodeDefinition = doc.child("LandXML").child("Surfaces").child(
            "Surface").child("Definition");

    LOGD("readData surfType : %s\n", nodeDefinition.attribute("surfType").value());
    LOGD("readData area2DSurf : %s\n", nodeDefinition.attribute("area2DSurf").value());
    LOGD("readData area3DSurf : %s\n", nodeDefinition.attribute("area3DSurf").value());
    LOGD("readData surfType : %s\n", nodeDefinition.attribute("surfType").value());
    LOGD("readData elevMax : %s\n", nodeDefinition.attribute("elevMax").value());
    LOGD("readData elevMin : %s\n", nodeDefinition.attribute("elevMin").value());

    int pId = 1;

    // 读取 Pnts->P 节点
    const pugi::xml_node &nodePnts = nodeDefinition.child("Pnts");
    for (const pugi::xml_node &pNode: nodePnts.children("P")) {
        int id = std::stoi(pNode.attribute("id").value());
        if (pId != id) {
            LOGE("readData lossId : %d\n", pId);
        }
        pId = id + 1;

        // 解析坐标
        std::istringstream iss(pNode.text().as_string());
        double x, y, z;
        iss >> x >> y >> z;

        // 创建 NCoordinate 对象并添加到映射中
        coordinateMap[id] = NCoordinate(id, x, y, z);
    }
    LOGD("readData coordinateMap.size : %d\n", coordinateMap.size());


    // 读取 Faces->F 节点
    const pugi::xml_node &nodeFaces = nodeDefinition.child("Faces");
    for (pugi::xml_node f: nodeFaces.children("F")) {
        // 检查 i 属性
        if (f.attribute("i").as_int() == 1) {
            continue; // 忽略 i == 1 的 F 元素
        }

        // 获取 n 属性的值
        std::string nValue = f.attribute("n").as_string();
        std::istringstream nStream(nValue);
        int key1, key2, key3;

        // 读取 n 中的三个整数
        if (nStream >> key1 >> key2 >> key3) {
            // 检查 coordinateMap 中是否存在这三个 key
            if (coordinateMap.find(key1) != coordinateMap.end() &&
                coordinateMap.find(key2) != coordinateMap.end() &&
                coordinateMap.find(key3) != coordinateMap.end()) {

                // 创建 LandFace 对象
                LandFace face;
                face.x1 = coordinateMap[key1].x;
                face.y1 = coordinateMap[key1].y;
                face.z1 = coordinateMap[key1].z;

                face.x2 = coordinateMap[key2].x;
                face.y2 = coordinateMap[key2].y;
                face.z2 = coordinateMap[key2].z;

                face.x3 = coordinateMap[key3].x;
                face.y3 = coordinateMap[key3].y;
                face.z3 = coordinateMap[key3].z;

                // 将 LandFace 添加到列表中
                landFaces.push_back(face);
            }
        }
    }
    LOGD("readData landFaces.size : %d\n", landFaces.size());

    return true;
}

long LandXmlReader::getCount() {
    return landFaces.size();
}


void LandXmlReader::close() {
    coordinateMap.clear(); // 释放所有元素
    landFaces.clear(); // 释放所有元素
}

double *LandXmlReader::getSjwData(const long index) {
    if (index < 0 || index >= landFaces.size()) {
        double *result = new double[1];
        result[0] = 0;
        return result;
    }
    LandFace face = landFaces[index];
    double *a = new double[9];
    a[0] = face.x1;
    a[1] = face.y1;
    a[2] = face.z1;
    a[3] = face.x2;
    a[4] = face.y2;
    a[5] = face.z2;
    a[6] = face.x3;
    a[7] = face.y3;
    a[8] = face.z3;

    return a;
}

/**
 * 加载某一个序号的面对象
 * @param index
 * @return
 */
LandFace *LandXmlReader::loadLandFace(long index) {
    if (index < 0 || index >= landFaces.size()) {
        return &emptyFace;
    }
    LandFace face = landFaces[index];
    return &face;
}




void LandXmlReader::setLandXml(const string &path) {
    LOGD("Error setLandXml file:%s\n", path.c_str());
    result = doc.load_file(path.c_str());
}
