/** @file DetectedImg.hpp
 * @brief Classifier class generates binary class classifier from image samples.
 * images to train linear SVM. 
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 *
 * A binary classifier class is created to train to detect dogs/blind humans in a random images.
 */
#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

class DetectedImg {
 public:
  DetectedImg();
  void loadImgs(cv::Mat&);
  cv::Mat& getImgs(int ord);
  int viewResult(int order);
  void setResult(int);
  int getSize() {
    return detectedImgs.size();
  }

 private:
  std::vector<cv::Mat> detectedImgs;
  std::vector<int> result;
};
