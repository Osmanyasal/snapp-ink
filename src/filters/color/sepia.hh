#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class Sepia : public BaseFilter
    {
        public:
            static const std::string NAME;
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        // Delete copy, move constructor and assignment operator
        Sepia(const Sepia &) = delete;
        Sepia(Sepia &&) = delete;
        Sepia &operator=(const Sepia &) = delete;

    private:
        Sepia() { std::cout << "ctor Sepia()\n"; };
        ~Sepia() = default;
    };

} // namespace snapp::filters::color
