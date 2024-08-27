#include "face_augmentation.hh"

namespace snapp::filters::ai
{
    BaseFilter &FaceAugmentation::get_filter()
    {
        static FaceAugmentation FaceAugmentation{};
        return FaceAugmentation;
    }

    void FaceAugmentation::apply(cv::Mat &img, void *user_data) const
    {
        
    }
}