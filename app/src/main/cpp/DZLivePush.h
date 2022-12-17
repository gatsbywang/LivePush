//
// Created by 小蜗牛 on 2022/11/6.
//

#ifndef LIVEPUSH_DZLIVEPUSH_H
#define LIVEPUSH_DZLIVEPUSH_H


#include "DZJNICall.h"
#include <malloc.h>

#include <string.h>

#include "DZPacketQueue.h"
#include "DZConstDefine.h"

extern "C" {
#include "librtmp/rtmp.h"
}


class DZLivePush {

public:
    DZJNICall *pJniCall = NULL;
    char *liveUrl = NULL;
    DZPacketQueue *pPacketQueue;
    RTMP *pRtmp = NULL;

public:
    DZLivePush(const char *liveUrl, DZJNICall *pJNICall);

    ~DZLivePush();

public:
    void initConnect();
};


#endif //LIVEPUSH_DZLIVEPUSH_H
