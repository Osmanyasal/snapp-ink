#include "face_augmentation.hh"

namespace snapp::filters::ai
{
    const std::string FaceAugmentation::NAME = "face_autmentation";
    
    BaseFilter &FaceAugmentation::get_filter()
    {
        static FaceAugmentation FaceAugmentation{};
        return FaceAugmentation;
    }

    void FaceAugmentation::apply(cv::Mat &img, void *user_data) const
    {
        std::string command{"python3 ./lib/roop/run.py"};

        std::pair<std::string, std::string> *src_dst = (std::pair<std::string, std::string> *)user_data;

        command += " -s " + src_dst->first + " -t " + src_dst->first + " -o " + src_dst->second + " --frame-processor face_enhancer";

        auto result = std::system(command.c_str());
        if (result == 0)
            std::cout << "Python script executed successfully.\n";
        else
            std::cerr << "Python script execution failed with code: " << result << "\n";
    }
}