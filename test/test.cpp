/** @file test.cpp
 * @brief testcpp is used for unit testings 
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 */

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>
#include "Classifier.hpp"

struct ClassifierTest : public ::testing::Test {
  Classifier* classifier;
  ClassifierTest() {
    classifier = new Classifier;
  }
  virtual ~ClassifierTest() {
    delete classifier;
  }
};

struct DetectedTest : testing::Test {
  DetectedImg* detectedImg;
  DetectedTest() {
    detectedImg = new DetectedImg;
  }
  virtual ~DetectedTest() {
    delete detectedImg;
  }
};

TEST_F(ClassifierTest, SavedPath) {
  std::string a = "../classifier.yml";
  std::string b = classifier->getSavePath();
  EXPECT_STREQ(a.data(), b.data());
}

TEST_F(DetectedTest, loadImg) {
  cv::Mat img = cv::imread("../expSamples/StreetView/street5.jpeg");
  detectedImg->loadImgs(img);
  int res = detectedImg->getSize();
  EXPECT_EQ(1, res);
}

TEST_F(DetectedTest, ViewSetResult) {
  detectedImg->setResult(10);
  detectedImg->setResult(20);
  int res = detectedImg->viewResult(1);
  EXPECT_EQ(res, 20);
}
