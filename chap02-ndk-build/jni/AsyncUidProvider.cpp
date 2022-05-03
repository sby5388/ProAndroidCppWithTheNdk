//
// Created by shenby07 on 2022/5/3.
//
#include <unistd.h>
#include "android_log.h"
#include "AsyncUidProvider.hpp"

AsyncUidProvider::AsyncUidProvider() {
    LOGD("AsyncUidProvider AsyncUidProvider()");
}

AsyncUidProvider::~AsyncUidProvider() {
    LOGD("AsyncUidProvider ~AsyncUidProvider");
}

void AsyncUidProvider::get() {
    LOGD("AsyncUidProvider get()");
    onUid(getuid());
}

void AsyncUidProvider::onUid(uid_t uid){
    LOGD("AsyncUidProvider onUid( %d)", uid);
}