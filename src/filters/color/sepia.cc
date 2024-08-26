#include "sepia.hh"

namespace snapp::filters::color
{
    BaseFilter &Sepia::get_filter()
    {
        static Sepia Sepia{};
        return Sepia;
    }

    void Sepia::apply(cv::Mat &img, void *user_data) const
    {
        cv::Mat sepiaKernel = (cv::Mat_<float>(3, 3) << 0.272, 0.534, 0.131,
                               0.349, 0.686, 0.168,
                               0.393, 0.769, 0.189);

        cv::transform(img, img, sepiaKernel);
    }
}