#pragma once
#include <opencv2/opencv.hpp>

class image {
public:

  /* equalize - Perform a constrant-limited adaptive histogram equalization.
   * This performs better than simple histogram equalization when we've got bright
   * sky and dark street; or bright snow and black cars.
   */
  static cv::Mat equalize(cv::Mat image);

  static void censor(cv::Mat image);
};
