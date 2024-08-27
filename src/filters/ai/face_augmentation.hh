#pragma once

#include "base_filter.hh"

namespace snapp::filters::ai
{
    class FaceAugmentation : public BaseFilter
    {
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        FaceAugmentation(const FaceAugmentation &) = delete;
        FaceAugmentation(FaceAugmentation &&) = delete;
        FaceAugmentation &operator=(const FaceAugmentation &) = delete;

    private:
        FaceAugmentation() { std::cout << "ctor FaceAugmentation()\n"; };
        ~FaceAugmentation() = default;
    };

} // namespace snapp::filters::ai
