#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class WaterColor : public BaseFilter
    {
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        WaterColor(const WaterColor &) = delete;
        WaterColor(WaterColor &&) = delete;
        WaterColor &operator=(const WaterColor &) = delete;

    private:
        WaterColor() { std::cout << "ctor WaterColor()\n"; };
        ~WaterColor() = default;
    };

} // namespace snapp::filters::color
