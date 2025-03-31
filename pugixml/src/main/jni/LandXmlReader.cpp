//
// Created by ZN200762 on 2025/3/28.
//

//#include "./pugixml-1.15/src/pugixml.hpp"
#include "LandXmlReader.hpp"
#include "android_log.h"
#include <string>
#include <vector>
#include <iostream>

extern int landFaceCount;
using namespace std;


LandXmlReader::LandXmlReader() {
    emptyFace = new LandFace();
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
    LOGD("readData elevMax : %s\n", nodeDefinition.attribute("elevMax").value());
    LOGD("readData elevMin : %s\n", nodeDefinition.attribute("elevMin").value());

    // 存储 ID-NCoordinate 的映射
    std::unordered_map<int, NCoordinate> coordinateMap;

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
    LOGD("readData coordinateMap.size : %lu\n", coordinateMap.size());

    bool first = true;

    // 读取 Faces->F 节点
    const pugi::xml_node &nodeFaces = nodeDefinition.child("Faces");
    for (pugi::xml_node f: nodeFaces.children("F")) {
        // 检查 i 属性
        if (f.attribute("i").as_int() == 1) {
            continue; // 忽略 i == 1 的 F 元素
        }

        // 获取 n 属性的值
        std::istringstream iss(f.text().as_string());

        int key1, key2, key3;
        iss >> key1 >> key2 >> key3;
        // 检查 coordinateMap 中是否存在这三个 key
        if (coordinateMap.find(key1) != coordinateMap.end() &&
            coordinateMap.find(key2) != coordinateMap.end() &&
            coordinateMap.find(key3) != coordinateMap.end()) {

            // 创建 LandFace 对象
            auto face = new LandFace();
            face->x1 = coordinateMap[key1].x;
            face->y1 = coordinateMap[key1].y;
            face->z1 = coordinateMap[key1].z;

            face->x2 = coordinateMap[key2].x;
            face->y2 = coordinateMap[key2].y;
            face->z2 = coordinateMap[key2].z;

            face->x3 = coordinateMap[key3].x;
            face->y3 = coordinateMap[key3].y;
            face->z3 = coordinateMap[key3].z;
            // 将 LandFace 添加到列表中
            landFaces.push_back(face);
        }

    }
    LOGD("readData landFaces.size : %lu\n", landFaces.size());
    return true;
}

long LandXmlReader::getCount() {
    return landFaces.size();
}


void LandXmlReader::close() {
    if (hasClosed) {
        return;
    }
    hasClosed = true;

    // 释放每个指针并清空向量
    for (LandFace *face: landFaces) {
        delete face;  // 删除指针指向的对象
    }
    landFaces.clear();  // 清空向量

    delete emptyFace;
    LOGD("close--landFaceCount = %d\n", landFaceCount);
}
//
//double *LandXmlReader::getSjwData(const long index) {
//    if (index < 0 || index >= landFaces.size()) {
//        double *result = new double[1];
//        result[0] = 0;
//        return result;
//    }
//    const auto *face = landFaces[index];
//    double *a = new double[9];
//    a[0] = face->x1;
//    a[1] = face->y1;
//    a[2] = face->z1;
//    a[3] = face->x2;
//    a[4] = face->y2;
//    a[5] = face->z2;
//    a[6] = face->x3;
//    a[7] = face->y3;
//    a[8] = face->z3;
//
//    return a;
//}

/**
 * 加载某一个序号的面对象
 * @param index
 * @return
 */
LandFace *LandXmlReader::loadLandFace(long index) {
//    LOGD("loadLandFace landFaces.size : %lu\n", landFaces.size());
//    LOGD("loadLandFace index : %d\n", index);

    if (index < 0 || index >= landFaces.size()) {
        return emptyFace;
    }
//    LandFace face = landFaces[index];

//    LOGD("readData face1 : %f %f %f\n", face.x1 ,face.y1,face.z1 );
//    LOGD("readData face2 : %f %f %f\n", face.x2 ,face.y2,face.z2 );
//    LOGD("readData face3 : %f %f %f\n", face.x3 ,face.y3,face.z3 );

    return landFaces[index];
}


void LandXmlReader::setLandXml(const string &path) {
    LOGD("Error setLandXml file:%s\n", path.c_str());
    result = doc.load_file(path.c_str());
}
