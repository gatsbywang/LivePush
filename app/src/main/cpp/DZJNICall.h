//
// Created by 花歹 on 2022/7/8.
//

#include <jni.h>

#ifndef MY_APPLICATION_DZJNICALL_H
#define MY_APPLICATION_DZJNICALL_H

enum ThreadMode{
    THREAD_CHILD,THREAD_MAIN
};

class DZJNICall{
public:
    JavaVM *javaVM;
    JNIEnv *jniEnv;
    jobject jLiveObj;
    jmethodID jConnectErrorMId;
    jmethodID jConnectSuccessMId;

public:
    DZJNICall(JavaVM *javaVM,JNIEnv *env,jobject jLiveObj);
    ~DZJNICall();

public:
    void callConnectError(ThreadMode threadMode,int code,char *msg);

    void callConnectSuccess(ThreadMode threadMode);

};

#endif //MY_APPLICATION_DZJNICALL_H
