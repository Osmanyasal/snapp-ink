#include <iostream>
#include <opencv2/opencv.hpp>

#include "filters/color/watarcolor.hh"
#include "filters/color/grayscale.hh"

int main(int argc, char **argv)
{

    cv::Mat mat = cv::imread("/home/rt7/Desktop/ss.jpg");
    // auto& a1 = snapp::filters::color::WaterColor::get_filter().apply(mat, (void *)8);
    // snapp::filters::color::GrayScale::get_filter().apply(mat);
    
    cv::imwrite("/home/rt7/Desktop/ss_processed.jpg", mat);

    return 0;
}