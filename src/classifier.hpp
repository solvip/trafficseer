#pragma once

#include <opencv2/opencv.hpp>
#include <string>

/* classifier - An implementation of our classification method
 * We use three different classifiers:
 * - One trained on the front of cars, having a size of 16x16
 * - One trained on the front-right angle of cars, having a size of 24x24
 * - One trained on the combination of both above, having a size of 16x16
 */
class classifier {
public:
  classifier(std::string frontRightClassifierPath,
	     std::string frontClassifierPath,
	     std::string frontCombinedClassifierPath);

  /* detect - use all three classifiers to detect objects in image.
   * image should already be preprocessed.
   */
  std::vector<cv::Rect> detect(cv::Mat image);
  
private:
  cv::CascadeClassifier frontRight, front, frontCombined;
};
