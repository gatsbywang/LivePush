//
// Created by 花歹 on 2022/11/6.
//

#include <jni.h>
#include "DZLivePush.h"
#include "DZConstDefine.h"

DZLivePush *pLivePush =NULL;
DZJNICall *pJniCall =NULL;
JavaVM *pJavaVm =  NULL;

// 重写 so 被加载时会调用的一个方法
//
extern "C"
JNIEXPORT  jint JNICALL JNI_onLoad(JavaVM *javaVm,void *reserved){
    LOGE("JNI_OnLoad -->");
    pJavaVm = javaVm;
    JNIEnv *env = NULL;
    if(javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK){
        return -1;
    }

    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_livepush_LivePush_nInitConnect(JNIEnv *env,jobject instance,jstring url){
    const char *pUrl = env->GetStringUTFChars(url,0);

    pJniCall = new DZJNICall(pJavaVm,env,instance);
    pLivePush = new DZLivePush(pUrl,pJniCall);

    pLivePush->initConnect();

    env->ReleaseStringUTFChars(url,pUrl);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_livepush_LivePush_nStop(JNIEnv *env, jobject thiz) {
    if(pLivePush !=NULL){
        delete (pLivePush);
        pLivePush = NULL;
    }

    if(pJniCall !=NULL){
        delete (pJniCall);
        pJniCall = NULL;
    }
}