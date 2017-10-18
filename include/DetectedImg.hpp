/** @class DetectedImg.hpp
 * @brief This class is the data container that stores the detected images and its results from SVM testing.
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
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
