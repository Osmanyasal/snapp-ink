#pragma once

#include "base_filter.hh"

namespace snapp::filters::color
{
    class PopUp : public BaseFilter
    {
    public:
        static BaseFilter &get_filter();
        virtual void apply(cv::Mat &img, void *user_data) const override;

        void NewFunction() const;

        // Delete copy, move constructor and assignment operator
        PopUp(const PopUp &) = delete;
        PopUp(PopUp &&) = delete;
        PopUp &operator=(const PopUp &) = delete;

    private:
        PopUp() { std::cout << "ctor PopUp()\n"; };
        ~PopUp() = default;
    };

} // namespace snapp::filters::color
