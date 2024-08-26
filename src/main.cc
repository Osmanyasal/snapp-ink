#include <iostream>

#include "filters/color/watarcolor.hh"
#include "filters/color/grayscale.hh"
#include "filters/color/sepia.hh"
#include "filters/color/mix.hh"
#include "filters/color/popup.hh"

int main(int argc, char **argv)
{

    std::string filter_name = "old2n.jpg";
    cv::Mat mat = cv::imread("../normal.jpg");
    // snapp::filters::color::WaterColor::get_filter().apply(mat, (void *)16);
    // snapp::filters::color::PopUp::get_filter().apply(mat);
    // snapp::filters::color::Sepia::get_filter().apply(mat);
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)(std::string{"./assets/old_filters/"} + filter_name).c_str());
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)"./assets/old_filters/old4n.jpg");
    // snapp::filters::color::GrayScale::get_filter().apply(mat);

    cv::imwrite(std::string{"../"} + filter_name, mat);

    return 0;
}