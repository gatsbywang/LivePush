//
// Created by 花歹 on 2022/7/30.
//
#include "DZPacketQueue.h"


DZPacketQueue::DZPacketQueue() {
    pPacketQueue = new std::queue<RTMPPacket *>();
    pthread_mutex_init(&packetMutex,NULL);
    pthread_cond_init(&packetCond,NULL);
}

void DZPacketQueue::clear() {
    // 需要清除队列，RTMPPacket*的内存数据
    pthread_mutex_lock(&packetMutex);

    while (!pPacketQueue->empty()){
        RTMPPacket *pPacket = pPacketQueue->front();
        pPacketQueue->pop();

        RTMPPacket_Free(pPacket);
        free(pPacket);
    }

    pthread_mutex_unlock(&packetMutex);
}

DZPacketQueue::~DZPacketQueue() {

    if(pPacketQueue != NULL){
        clear();
        delete (pPacketQueue);
        pPacketQueue = NULL;
    }
    

    pthread_mutex_destroy(&packetMutex);
    pthread_cond_destroy(&packetCond);
}

void DZPacketQueue::push(RTMPPacket *pPacket) {

    pthread_mutex_lock(&packetMutex);
    pPacketQueue->push(pPacket);
    pthread_cond_signal(&packetCond);
    pthread_mutex_unlock(&packetMutex);
}

RTMPPacket *DZPacketQueue::pop() {
    RTMPPacket *pPacket;
    pthread_mutex_lock(&packetMutex);

    // 取不到就阻塞
    while (pPacketQueue->empty()){
        pthread_cond_wait(&packetCond,&packetMutex);
    }

    pPacket = pPacketQueue->front();
    pPacketQueue->pop();

    pthread_mutex_unlock(&packetMutex);

    return pPacket;
}

