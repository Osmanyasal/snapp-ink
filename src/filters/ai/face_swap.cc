#include "face_swap.hh"

namespace snapp::filters::ai
{
    BaseFilter &FaceSwap::get_filter()
    {
        static FaceSwap FaceSwap{};
        return FaceSwap;
    }

    void FaceSwap::apply(cv::Mat &img, void *user_data) const
    {
        
    }
}