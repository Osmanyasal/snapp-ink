#include "mix.hh"

namespace snapp::filters::color
{
    const std::string Mix::NAME = "mix";
    
    BaseFilter &Mix::get_filter()
    {
        static Mix Mix{};
        return Mix;
    }

    void Mix::apply(cv::Mat &img, void *user_data) const
    {
        std::string stain_name{(char *)user_data};
        std::cout << "stain_name:" << stain_name << "\n";

        cv::Mat stain_img = cv::imread(stain_name);

        cv::resize(stain_img, stain_img, img.size());
        cv::addWeighted(img, 0.75, stain_img, .25, 0, img);
    }
}
