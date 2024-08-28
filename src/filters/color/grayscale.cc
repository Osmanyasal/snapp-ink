#include "grayscale.hh"
namespace snapp::filters::color
{
    const std::string GrayScale::NAME = "grayscale";

    BaseFilter &GrayScale::get_filter()
    {
        static GrayScale GrayScale{};
        return GrayScale;
    }

    void GrayScale::apply(cv::Mat &img, void *user_data) const
    {
        cv::cvtColor(img, img, cv::COLOR_BGRA2GRAY);
        cv::cvtColor(img, img, cv::COLOR_GRAY2BGR);
    }
}