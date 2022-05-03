//
// Created by shenby07 on 2022/5/3.
//

#ifndef PROANDROIDCPPWITHTHENDK_ASYNCUIDPROVIDER_HPP
#define PROANDROIDCPPWITHTHENDK_ASYNCUIDPROVIDER_HPP

/** 异步获取uid */
typedef unsigned int uid_t;

class AsyncUidProvider {
public:
    AsyncUidProvider();

    virtual ~AsyncUidProvider();

    void get();

    virtual void onUid(uid_t uid);

};

#endif //PROANDROIDCPPWITHTHENDK_ASYNCUIDPROVIDER_HPP
