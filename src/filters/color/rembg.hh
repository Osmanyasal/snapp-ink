#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class RemBG : public BaseFilter
    {
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        RemBG(const RemBG &) = delete;
        RemBG(RemBG &&) = delete;
        RemBG &operator=(const RemBG &) = delete;

    private:
        RemBG() { std::cout << "ctor RemBG()\n"; };
        ~RemBG() = default;
    };

} // namespace snapp::filters::color
