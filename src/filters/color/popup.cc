#include "popup.hh"

namespace snapp::filters::color
{
    const std::string PopUp::NAME = "popup";

    BaseFilter &PopUp::get_filter()
    {
        static PopUp PopUp{};
        return PopUp;
    }

    void PopUp::apply(cv::Mat &img, void *user_data) const
    {
        cv::Mat hsv, gray;
        // convert the BGR image to HSV colour space
        cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

        // obtain the grayscale image of the original image
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

        // Set the bounds for the red hue
        cv::Scalar lower_red(120, 50, 50);
        cv::Scalar upper_red(180, 255, 255);

        // Create a mask using the bounds set
        cv::Mat mask;
        cv::inRange(hsv, lower_red, upper_red, mask);

        // Create an inverse of the mask
        cv::Mat mask_inv;
        cv::bitwise_not(mask, mask_inv);

        // Filter only the red color from the original image using the mask (foreground)
        cv::Mat res;
        cv::bitwise_and(img, img, res, mask);

        // Filter the regions containing colors other than red from the grayscale image (background)
        cv::Mat background;
        cv::bitwise_and(gray, gray, background, mask_inv);

        // Convert the one-channeled grayscale background to a three-channeled image
        cv::Mat background_3ch;
        cv::cvtColor(background, background_3ch, cv::COLOR_GRAY2BGR);

        // Add the foreground and the background
        cv::Mat final_result;
        cv::add(res, background_3ch, final_result);

        img = final_result;
    }
}