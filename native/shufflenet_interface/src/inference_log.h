/**
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#ifndef CAMERA2BASIC_INFERENCE_LOG_H
#define CAMERA2BASIC_INFERENCE_LOG_H
#include <string>

#ifdef __ANDROID__
#include <android/log.h>
#else
#include<stdio.h>
#endif


#ifdef __ANDROID__
class LogFunction;
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"inference_sdk",__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,"inference_sdk",__VA_ARGS__)
#define LOGFUNC() LogFunction func_##__LINE__ = LogFunction(__FUNCTION__);

class LogFunction {
private:
    std::string function_;
public:
    LogFunction(const char *function) : function_(function) {
        LOGD("enter %s", function);
    }

    ~LogFunction() {
        LOGD("leave %s", function_.c_str());
    }
};
#else
class LogFunction;
#define  LOGE(...)  printf(__VA_ARGS__)
#define  LOGD(...)  printf(__VA_ARGS__)
#define LOGFUNC() LogFunction func_##__LINE__ = LogFunction(__FUNCTION__);

class LogFunction {
private:
    std::string function_;
public:
    LogFunction(const char *function) : function_(function) {
        printf("enter %s\n", function);
    }

    ~LogFunction() {
        printf("leave %s\n", function_.c_str());
    }
};
#endif

#endif //CAMERA2BASIC_INFERENCE_LOG_H
