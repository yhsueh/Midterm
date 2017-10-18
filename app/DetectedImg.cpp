/** @file DetectedImg.cpp
 * @brief This is cpp file for DetectedImg class which stores the images and its results after the SVM analysis.
 * @author Yuyu Hsueh
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 * Licensor hereby grants Licensee a Sublicensable, Non-assignable & non-transferable, Pepetual, Commercial, Royalty free.
 * Including the rights to create but not distribute derivative works, Non-exclusive license, all with accordance with the 
 * terms set forth and other legal restrictions set forth in 3rd party software used while running Software.
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
