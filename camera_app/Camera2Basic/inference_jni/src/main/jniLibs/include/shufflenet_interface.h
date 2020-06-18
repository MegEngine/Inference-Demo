/**
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#ifndef MGE_INFERENCE_SAMPLE_SHUFFLENET_INTERFACE_H
#define MGE_INFERENCE_SAMPLE_SHUFFLENET_INTERFACE_H

#include <stddef.h>

#define PUBLIC_API __attribute__((visibility("default")))

// ========= jni interface =============== //
#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        ROTATION_0 = 0,
        ROTATION_90 = 90,
        ROTATION_180 = 180,
        ROTATION_270 = 270,
    } FRAME_ROTATION;

    typedef struct
    {
        void *data;
        size_t size;
        int width;
        int height;
        FRAME_ROTATION rotation;
    } FrameData;

    typedef struct
    {
        char label[128];
        float accuracy;
    } FrameResult;

    typedef struct
    {
        void *model_data;
        size_t model_size;
        const char *json;
        int label_count;
        int limit_count;
        float threshold;
    } ModelInit;

    typedef void *ShuffleNetContext_PTR;

    ShuffleNetContext_PTR PUBLIC_API shufflenet_init(const ModelInit &init);
    void PUBLIC_API shufflenet_recognize(ShuffleNetContext_PTR sc, const FrameData &frame, int number,
                                         FrameResult *results, int *output_size);
    void PUBLIC_API shufflenet_close(ShuffleNetContext_PTR sc);

#ifdef __cplusplus
}
#endif

#endif //MGE_INFERENCE_SAMPLE_SHUFFLENET_INTERFACE_H
