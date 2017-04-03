/*
 * A utility for preprocessing the images
 * that we use for training:
 * - Crop out uninteresting regions
 * - Convert to grayscale
 * - Perform a histogram equalization of the color spectrum to increase contrast
 */

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "image.hpp"

using namespace std;
using namespace cv;

Mat equalize(Mat image);

int main(int argc, char *argv[]) {
  if(argc != 3) {
    cerr << "preprocess an image; saving it to output path" << endl;
    cerr << "I suggest using a lossless format, such as png, for output" << endl;
    cerr << "usage: " << argv[0] << " <input_image_path> <output_image_path>" << endl;
    return 1;
  }
  const char *image_input_path = argv[1];
  const char *image_output_path = argv[2];

  Mat image = cv::imread(image_input_path, CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data) {
    cerr << "no image data; breaking out" << endl;
    return 1;
  }

  Mat equalizedImage = image::equalize(image);
  try {
    vector<int> params;
    imwrite(image_output_path, equalizedImage, params);
  } catch(runtime_error& ex) {
    fprintf(stderr, "unable to write preprocessed image to output file: %s: %s\n", image_output_path, ex.what());
    return 1;
  }
  
  return 0;
}

