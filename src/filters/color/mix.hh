#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class Mix : public BaseFilter
    {
    public:
        static const std::string NAME;

    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        Mix(const Mix &) = delete;
        Mix(Mix &&) = delete;
        Mix &operator=(const Mix &) = delete;

    private:
        Mix() { std::cout << "ctor Mix()\n"; };
        ~Mix() = default;
    };

} // namespace snapp::filters::color
