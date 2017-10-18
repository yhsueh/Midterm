/**@class Classifer.h
 * @brief Classifier class generates binary class classifier from image samples
 * \nimages to train linear SVM. 
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 *
 * A binary classifier class is created to train to detect dogs/blind humans in a random images.
 */
#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "DetectedImg.hpp"

class Classifier {
 public:
  /** 
   *  Classifier constructor, the classifier is by default in loading mode
   */
  Classifier()
      : loadPath(""),
        savePath("../classifier.yml"),
        saveName("NoName"),
        pos_num(0),
        loadFlag(false),
        testSampleFlag(false) {
  }
  /** 
   *  Classifier second constructor, the classifier is in training mode
   */
  Classifier(std::string path, bool flag, bool flag2)
      : loadPath(path),
        pos_num(0),
        loadFlag(flag),
        testSampleFlag(flag2) {
  }
  /** 
   *  imgInit takes in path string where samples are
   */
  void imgInit(std::string&);
  void setSavePath(std::string savepath) {
    savePath = savepath;
  }
  void setSaveName(std::string savename) {
    saveName = savename;
  }
  /** 
   *  Analyzing images using SVM classifier. Its input is DetectedImg type.
   */
  void predictImg(DetectedImg&);
  std::string getSavePath() {
    return savePath;
  }

  cv::Ptr<cv::ml::SVM> getSVM() {
    return svm;
  }

 protected:
  cv::Ptr<cv::ml::SVM> svm; /**< A smartpointer to SVM */
  std::string loadPath; /**< Directory path to the classifier */
  std::string savePath; /**< Directory path for storing newly trained classifier */
  std::string saveName; /**< Classifier's name */
  std::vector<cv::Mat> images; /**< Positive and negative images */
  std::vector<float> primalSupportVector; /**< Optimal support vector */
  unsigned pos_num; /**< Number of positive samples */
  bool loadFlag;
  bool testSampleFlag;
  void imgDenoise(); /**< Remove noise in samples */
  void extractHOGandTrain(); /**< Extract Hog from samples */
  void get_svm_detector();/**< Derive primal SV */
};
