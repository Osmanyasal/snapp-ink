#pragma once

#include "base_filter.hh"

namespace snapp::filters::ai
{
    class FaceSwap : public BaseFilter
    {
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        FaceSwap(const FaceSwap &) = delete;
        FaceSwap(FaceSwap &&) = delete;
        FaceSwap &operator=(const FaceSwap &) = delete;

    private:
        FaceSwap() { std::cout << "ctor FaceSwap()\n"; };
        ~FaceSwap() = default;
    };

} // namespace snapp::filters::ai
