#include <iostream> 

#include "filters/color/watarcolor.hh"
#include "filters/color/grayscale.hh"
#include "filters/color/sepia.hh"
#include "filters/color/mix.hh"
#include "filters/color/popup.hh"

int main(int argc, char **argv)
{

    cv::Mat mat = cv::imread("../ss2.png");
    // auto& a1 = snapp::filters::color::WaterColor::get_filter().apply(mat, (void *)8);
    // snapp::filters::color::GrayScale::get_filter().apply(mat);
    // snapp::filters::color::Sepia::get_filter().apply(mat);
    // snapp::filters::color::PopUp::get_filter().apply(mat);
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)"./assets/old_filters/old3n.jpg");

    cv::imwrite("../ss_processed.jpg", mat);

    return 0;
}