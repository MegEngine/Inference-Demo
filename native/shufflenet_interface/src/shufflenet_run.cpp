/**
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include "shufflenet_interface.h"
#include "imagenet_class_info.h"
#include "inference_log.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void readBufFromFile(vector<uint8_t> &vf, const char *path)
{
    uint8_t one_char;
    ifstream f(path, ios::binary);
    if (!f)
        return;
    f.unsetf(ios::skipws);
    while (!f.eof())
    {
        f >> one_char;
        vf.push_back(one_char);
    }
    f.close();
    return;
}

bool test_shufflenet(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << " Wrong argument" << std::endl;
        return false;
    }

    //BGR
    cv::Mat bgr_ = cv::imread(argv[2], cv::IMREAD_COLOR);

    fprintf(stdout, "pic %dx%d c%d\n", bgr_.cols, bgr_.rows, bgr_.elemSize());
    vector<uint8_t> models;
    readBufFromFile(models, argv[1]);
    fprintf(stdout, "======== model size %ld\n", models.size());
    int num_size = 5;
    int output_size = 0;
    FrameResult f_results[5];
    ShuffleNetContext_PTR ptr = shufflenet_init({.model_data = models.data(), .model_size = models.size(), .json = IMAGENET_CLASS_INFOS, .limit_count = 1, .threshold=0.01f});
    if (ptr == nullptr)
    {
        fprintf(stderr, "fail to init model\n");
        return false;
    }

    shufflenet_recognize(ptr, FrameData{.data = bgr_.data, .size = static_cast<size_t>(bgr_.rows * bgr_.cols * bgr_.elemSize()), .width = bgr_.cols, .height = bgr_.rows, .rotation = ROTATION_0}, num_size, f_results, &output_size);
    printf("========output size %d\n", output_size);
    for (int ii = 0; ii < output_size; ii++)
    {
        printf("========output result[%d] Label:%s, Predict:%.2f\n", ii, (f_results + ii)->label,
             (f_results + ii)->accuracy);
    }
    printf("test done!\n");
    shufflenet_close(ptr);

    return true;
}

int main(int argc, char *argv[])
{
    test_shufflenet(argc, argv);
    return 0;
}