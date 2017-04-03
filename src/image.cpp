#include <opencv2/opencv.hpp>

#include "image.hpp"

using namespace std;
using namespace cv;

Mat image::equalize(Mat image) {
  Mat equalizedImage;
  createCLAHE(2.0, Size(8, 8))->apply(image, equalizedImage);
  
  return equalizedImage;
}

void image::censor(Mat image) {
  // Remove the right-hand side and the top of the image
  Size imgSize = image.size();
  Point right[] = {
    Point(0, 100), // top left
    Point(0, 0), // mid left
    Point(imgSize.width, 0), // top right
    Point(imgSize.width, imgSize.height), // bottom right
    Point(310, imgSize.height), // bottom left
    Point(280, 100), // top mid
  };
  fillConvexPoly(image, right, 6, Scalar(0, 0, 0));

  // Remove the left part of the picture that isn't road
  Point left[] = {
    Point(0, 100), // top left
    Point(220, 100), // top right
    Point(0, 240), // bottom
  };
  fillConvexPoly(image, left, 3, Scalar(0, 0, 0));

  
  return;
}
