//
// Created by ZN200762 on 2025/3/28.
//

//#include "./pugixml-1.15/src/pugixml.hpp"
#include "LandXmlReader.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


LandXmlReader::LandXmlReader() {
}

LandXmlReader::~LandXmlReader() {

}


bool LandXmlReader::readData() {
    cout << result.description() << endl;
    return true;
}

long LandXmlReader::getCount() {
    return 100L;
}


void LandXmlReader::close() {

}

double* LandXmlReader::getSjwData(long index) {
    double* a = new double [2];
    return a;
}

void LandXmlReader::setLandXml(const string &path) {
    result = doc.load_string(path.c_str());
}
