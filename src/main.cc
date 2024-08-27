#include <iostream>
#include "snapp_ink.hh"

int main(int argc, char **argv)
{

    std::string filter_name = "sketch32.jpg";
    cv::Mat mat = cv::imread("../ss.jpg");
    // snapp::filters::color::Sketch::get_filter().apply(mat, (void *)32);
    // snapp::filters::color::Sketch::get_filter().apply(mat, (void *)3);
    // snapp::filters::color::PopUp::get_filter().apply(mat);
    // snapp::filters::color::Sepia::get_filter().apply(mat);
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)(std::string{"./assets/old_filters/"} + filter_name).c_str());
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)"./assets/old_filters/old4n.jpg");
    // snapp::filters::color::GrayScale::get_filter().apply(mat);

    snapp::filters::ai::FaceAugmentation::get_filter().apply(mat);

    cv::imwrite(std::string{"../"} + filter_name, mat);
    return 0;
}