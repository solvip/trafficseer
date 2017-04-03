/**
 * trafficseer
 *
 * a traffic seeing, sentient being.
 */

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "image.hpp"
#include "classifier.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  cout << argv[0] << endl;
  bool debug = true;
  
  if(argc < 2) {
    std::cerr << "usage: " << argv[0] << " <image_path_1> [image_path_2] [image_path_...]" << std::endl;
    return 1;
  }

  classifier c("data/cascade/front-right/cascade.xml",
	       "data/cascade/front/cascade.xml",
	       "data/cascade/front-both/cascade.xml");

  char *image_path;
  Mat image, grayImage, equalizedImage;
  for(int i = 1; i < argc; i++) {
    image_path = argv[i];
    image = imread(image_path, 1);
    if(!image.data) {
      cerr << "no image data in " << image_path << endl;
      return -1;
    }

    cvtColor(image, grayImage, CV_BGR2GRAY);
    image::censor(grayImage);
    equalizedImage = image::equalize(grayImage);

    vector<Rect> objects = c.detect(equalizedImage);
    cout << image_path << ": " << objects.size() << endl;

    if(debug) {
      // Highlight
      for(cv::Rect cur : objects) {
	cv::rectangle(image, cur.tl(), cur.br(), cv::Scalar(0, 255, 0));
      }

      cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
      cv::imshow("Display Image", image);
      cv::waitKey(0);
    }
  }

  return 0;
}
