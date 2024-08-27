#include <iostream>
#include "snapp_ink.hh"

int main(int argc, char **argv)
{

    // std::string filter_name = "sketch32.jpg";
    cv::Mat mat = cv::imread("../ss.jpg");
    
    // snapp::filters::color::Sketch::get_filter().apply(mat, (void *)32);
    // snapp::filters::color::Sketch::get_filter().apply(mat, (void *)3);
    // snapp::filters::color::PopUp::get_filter().apply(mat);
    // snapp::filters::color::Sepia::get_filter().apply(mat);
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)(std::string{"./assets/old_filters/"} + filter_name).c_str());
    // snapp::filters::color::Mix::get_filter().apply(mat, (void *)"./assets/old_filters/old4n.jpg");
    // snapp::filters::color::GrayScale::get_filter().apply(mat);

    // std::pair<std::string, std::string> src_dst{"../ss.jpg", "../ss_removedbg.jpg"};
    // snapp::filters::color::RemBG::get_filter().apply(mat, (void*)&src_dst);

    // std::pair<std::string, std::string> src_dst{"../ss.jpg", "../2"};
    // snapp::filters::color::Colorisation::get_filter().apply(mat, (void*)&src_dst);

    std::pair<std::string, std::string> src_dst{"../tt.jpg", "../ss.jpg"};
    snapp::filters::ai::FaceSwap::get_filter().apply(mat, (void*)&src_dst);

    // cv::imwrite(std::string{"../"} + filter_name, mat);
    return 0;
}