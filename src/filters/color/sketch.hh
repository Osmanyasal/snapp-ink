#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class Sketch : public BaseFilter
    {
        public:
            static const std::string NAME;

        public:
            static BaseFilter &get_filter();
            virtual void apply(cv::Mat &img, void *user_data) const override;

            // Delete copy, move constructor and assignment operator
            Sketch(const Sketch &) = delete;
            Sketch(Sketch &&) = delete;
            Sketch &operator=(const Sketch &) = delete;

        private:
            Sketch() { std::cout << "ctor Sketch()\n"; };
            ~Sketch() = default;
    };

} // namespace snapp::filters::color
