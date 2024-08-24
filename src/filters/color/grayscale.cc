#include "grayscale.hh"
namespace snapp::filters::color
{
    BaseFilter &GrayScale::get_filter()
    {
        static GrayScale GrayScale{};
        return GrayScale;
    }

    void GrayScale::apply(cv::Mat &img, void *user_data) const
    {
        cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    }
}