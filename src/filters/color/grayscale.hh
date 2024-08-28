#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class GrayScale : public BaseFilter
    {
        public:
            static const std::string NAME;

        public:
            static BaseFilter &get_filter();
            virtual void apply(cv::Mat &img, void *user_data) const override;

            // Delete copy, move constructor and assignment operator
            GrayScale(const GrayScale &) = delete;
            GrayScale(GrayScale &&) = delete;
            GrayScale &operator=(const GrayScale &) = delete;

        private:
            GrayScale() { std::cout << "ctor GrayScale()\n"; };
            ~GrayScale() = default;
    };

} // namespace snapp::filters::color
