#include "sketch.hh"
namespace snapp::filters::color
{

    BaseFilter &Sketch::get_filter()
    {
        static Sketch Sketch{};
        return Sketch;
    }

    void Sketch::apply(cv::Mat &img, void *user_data) const
    {
        int num_of_locations = (long)user_data;
        // Reshape the image to a 2D array of pixels
        cv::Mat Z = img.reshape(1, img.rows * img.cols);
        Z.convertTo(Z, CV_32F); // Convert to float

        // Criteria for k-means
        cv::TermCriteria criteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 10, 1.0);

        // Variables for k-means
        cv::Mat labels;
        cv::Mat centers;

        // Apply k-means clustering
        cv::kmeans(Z, num_of_locations, labels, criteria, 10, cv::KMEANS_RANDOM_CENTERS, centers);
        // Convert centers to 8-bit
        centers.convertTo(centers, CV_8U);

        // Map each pixel to the center

#pragma omp parallel for
        for (int i = 0; i < img.rows * img.cols; ++i)
        {
            int cluster_idx = labels.at<int>(i);
            img.at<cv::Vec3b>(i / img.cols, i % img.cols) = centers.at<cv::Vec3b>(cluster_idx);
        }
    }
}