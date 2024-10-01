#include "face_swap.hh"

namespace snapp::filters::ai
{
    const std::string FaceSwap::NAME = "face_swap";
    BaseFilter &FaceSwap::get_filter()
    {
        static FaceSwap FaceSwap{};
        return FaceSwap;
    }

    void FaceSwap::apply(cv::Mat &img, void *user_data) const
    {
        std::string command{"python3 ./lib/roop/run.py"};

        std::pair<std::string, std::string> *src_dst = (std::pair<std::string, std::string> *)user_data;

        std::string target{src_dst->first.substr(0, src_dst->first.find_last_of('.'))};
        target += "_processed" + src_dst->first.substr(src_dst->first.find_last_of('.'));

        command += " -s " + src_dst->first + " -t " + src_dst->second + " -o " + target + " --frame-processor face_swapper face_enhancer";
        // command = "pwd;" + command;

        // std::cout << "command --> " << command << "\n";
        auto result = std::system(command.c_str());
        if (result == 0)
            std::cout << "Python script executed successfully.\n";
        else
            std::cerr << "Python script execution failed with code: " << result << "\n";
    }
}
