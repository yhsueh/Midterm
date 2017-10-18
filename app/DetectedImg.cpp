/** @file DetectedImg.hpp
 * @brief Classifier class generates binary class classifier from image samples.
 * images to train linear SVM. 
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 *
 * A binary classifier class is created to train to detect dogs/blind humans in a random images.
 */
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "DetectedImg.hpp"

DetectedImg::DetectedImg() {
}

void DetectedImg::loadImgs(cv::Mat& img) {
  detectedImgs.push_back(img);
}

cv::Mat& DetectedImg::getImgs(int ord) {
  return detectedImgs[ord];
}

void DetectedImg::setResult(int rest) {
  result.push_back(rest);
}

int DetectedImg::viewResult(int order) {
  return result[order];
}
