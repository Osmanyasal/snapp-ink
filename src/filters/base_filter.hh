#pragma once
#include <iostream>
#include <memory>
#include <omp.h>
#include <opencv2/imgproc/imgproc.hpp>

namespace snapp::filters
{
    class BaseFilter
    {
    public:
        BaseFilter() = default;
        ~BaseFilter() = default;
        virtual void apply(cv::Mat &img, void * user_data = nullptr) const = 0;
    };
}