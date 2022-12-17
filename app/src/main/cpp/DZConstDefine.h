//
// Created by 花歹 on 2022/7/5.
//

#ifndef MY_APPLICATION_DZCONSTDEFINE_H
#define MY_APPLICATION_DZCONSTDEFINE_H

#include <android/log.h>

#define TAG "JNI_TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


// -------------- 错误码 start ------------------

#define INIT_RTMP_CONNECT_ERROR_CODE -0x10
#define INIT_RTMP_CONNECT_STREAM_ERROR_CODE -0x11
// -------------- 错误码 end ------------------

#endif //MY_APPLICATION_DZCONSTDEFINE_H
