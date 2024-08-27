#include "rembg.hh"
    
namespace snapp::filters::color
{
    BaseFilter &RemBG::get_filter()
    {
        static RemBG RemBG{};
        return RemBG;
    }

    void RemBG::apply(cv::Mat &img, void *user_data) const
    {
        std::string command{"python3 ./lib/rembg/rembg.py i "};

        std::pair<std::string, std::string> *src_dst = (std::pair<std::string, std::string> *)user_data;

        command += " " + src_dst->first + " " + src_dst->second;

        auto result = std::system(command.c_str());
        if (result == 0)
            std::cout << "Python script executed successfully.\n";
        else
            std::cerr << "Python script execution failed with code: " << result << "\n";
    }
}   