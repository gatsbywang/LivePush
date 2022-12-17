//
// Created by 花歹 on 2022/7/30.
//

#ifndef DEMOOPENSLES_DZPACKETQUEUE_H
#define DEMOOPENSLES_DZPACKETQUEUE_H

#include <queue>
#include <pthread.h>

extern "C" {
#include "librtmp/rtmp.h"
};

class DZPacketQueue {
public:
    std::queue<RTMPPacket*> *pPacketQueue;
    pthread_mutex_t packetMutex;    // 这是锁
    pthread_cond_t packetCond;  // 这是为了唤醒哪个线程所用

public:
    DZPacketQueue();
    ~DZPacketQueue();

public:
    void push(RTMPPacket *pPacket);

    RTMPPacket *pop();

    /**
     * 清空队列
     */
    void clear();
};


#endif //DEMOOPENSLES_DZPACKETQUEUE_H
