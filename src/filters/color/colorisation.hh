#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class Colorisation : public BaseFilter
    {
    public:
        static const std::string NAME;

    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        Colorisation(const Colorisation &) = delete;
        Colorisation(Colorisation &&) = delete;
        Colorisation &operator=(const Colorisation &) = delete;

    private:
        Colorisation() { std::cout << "ctor Colorisation()\n"; };
        ~Colorisation() = default;
    };

} // namespace snapp::filters::color
