//
// Created by ZN200762 on 2025/11/12.
//

#ifndef PROANDROIDCPPWITHTHENDK_LANDXMLREADPROGRESSLISTENER_H
#define PROANDROIDCPPWITHTHENDK_LANDXMLREADPROGRESSLISTENER_H


class LandXmlReadProgressListener {

public:

    LandXmlReadProgressListener() {}

    virtual ~LandXmlReadProgressListener() {}

    virtual void onReadStart() {

    }

    virtual void onReadProgress(int progress) {

    }

    virtual void onReadFinish() {

    }

};


#endif //PROANDROIDCPPWITHTHENDK_LANDXMLREADPROGRESSLISTENER_H
