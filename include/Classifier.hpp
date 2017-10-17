/** @file Classifer.h
* @brief Classifier class generates binary class classifier from image samples.
* images to train linear SVM. 
* @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
*
* A binary classifier class is created to train to detect dogs/blind humans in a random images.
*/
#pragma once
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <string>
#include <vector>

class Classifier {
 public:
  /** A classifier class
  * The classifier class does pre-process the image samples, both positive and negative 
  * samples are required. The class extracts HOG features, train
  *
  */
  Classifier();
  Classifier(std::string path, bool flag, bool flag2)
      : loadPath(path),
        pos_num(0),
        loadFlag(flag),
        testSampleFlag(flag2) {}

  void imgInit(std::string&);
  void setSavePath(std::string savepath) {
    savePath = savepath;
  }
  void setSaveName(std::string savename) {
    saveName = savename;
  }
  bool predictImg(std::string);

 private:
  cv::Ptr<cv::ml::SVM> svm;
  cv::Mat streetView;
  std::string loadPath;
  std::string savePath;  // Saving classifier
  std::string saveName;
  std::vector<cv::Mat> images;
  std::vector<float> primalSupportVector;
  unsigned pos_num;
  bool loadFlag;
  bool testSampleFlag;
  void imgDenoise();
  void extractHOGandTrain();
  void get_svm_detector();
};
