#include "colorisation.hh"
    
namespace snapp::filters::color
{
    const std::string Colorisation::NAME = "colorisation";

    BaseFilter &Colorisation::get_filter()
    {
        static Colorisation Colorisation{};
        return Colorisation;
    }

    void Colorisation::apply(cv::Mat &img, void *user_data) const
    {
        std::string command{"python3 ./lib/colorisation/demo_release.py"};

        std::pair<std::string, std::string> *src_dst = (std::pair<std::string, std::string> *)user_data;

        command += " -i " + src_dst->first + " -o " + src_dst->second;

        auto result = std::system(command.c_str());
        if (result == 0)
            std::cout << "Python script executed successfully.\n";
        else
            std::cerr << "Python script execution failed with code: " << result << "\n";
    }
}   