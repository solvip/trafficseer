#include <opencv2/opencv.hpp>

#include "classifier.hpp"

using namespace std;
using namespace cv;

// We use a scalefactor of 1.05 to trade off better detection with cpu + ram.
// See http://stackoverflow.com/questions/20801015/recommended-values-for-opencv-detectmultiscale-parameters
static const float SCALE_FACTOR = 1.10;
static const float MIN_NEIGHBORS = 6;

static vector<Rect> mergeVectors(vector<Rect> a, vector<Rect> b);

classifier::classifier(string frontRightClassifierPath,
		       string frontClassifierPath,
		       string frontCombinedClassifierPath)
{
  this->frontRight = CascadeClassifier(frontRightClassifierPath);
  this->front = CascadeClassifier(frontClassifierPath);
  this->frontCombined = CascadeClassifier(frontCombinedClassifierPath);
}

vector<Rect> classifier::detect(Mat image) {
  vector<Rect> front, frontRight, frontCombined;
  this->front.detectMultiScale(image, front, SCALE_FACTOR, MIN_NEIGHBORS, 0, Size(16, 16), Size(32, 32));
  this->frontRight.detectMultiScale(image, frontRight, SCALE_FACTOR, MIN_NEIGHBORS, 0, Size(24, 24), Size(100, 100));
  this->frontCombined.detectMultiScale(image, frontCombined, SCALE_FACTOR, MIN_NEIGHBORS, 0, Size(16, 16), Size(32, 32));

  vector<Rect> results = mergeVectors(front, frontRight);
  results = mergeVectors(results, frontCombined);
  
  int size = results.size();
  for(Rect r : results) {
    results.push_back(r);
  }
  
  groupRectangles(results, 1, 0.2);
  
  return results;
}

static vector<Rect> mergeVectors(vector<Rect> a, vector<Rect> b) {
  vector<Rect> ret(a);
  
  ret.insert(ret.end(), b.begin(), b.end());
  
  return ret;
}
