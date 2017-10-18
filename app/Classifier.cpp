/** @file Classifier.cpp
 * @brief This is cpp file for Classifier class which extracts HOG features from sample images and trains binary class
 * classifier for dogs and supposedly humans.
 * @author Yuyu Hsueh
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 * Licensor hereby grants Licensee a Sublicensable, Non-assignable & non-transferable, Pepetual, Commercial, Royalty free.
 * Including the rights to create but not distribute derivative works, Non-exclusive license, all with accordance with the 
 * terms set forth and other legal restrictions set forth in 3rd party software used while running Software.
 */
#include "Classifier.hpp"
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <string>
#include <vector>
Classifier::Classifier() {
  loadPath = "";
  savePath = "../classifier.yml";
  saveName = "NoName";
  pos_num = 0;
  loadFlag = false;
  testSampleFlag = false;
}

void Classifier::imgDenoise() {
  cv::Mat GrayImg, denoised;
  for (auto& i : images) {
    cv::GaussianBlur(i, i, cv::Size(3, 3), 1);
  }
  std::cout << "Denoise Process Completes" << std::endl;
}

void Classifier::extractHOGandTrain() {
  // Create the HOG samples
  cv::Mat sampleMatrix;
  std::string prefix = "Classifier_";
  std::string ext = ".yml";
  std::vector<float> discriptor;
  // Create Classifier
  if (!(loadFlag)) {
    cv::HOGDescriptor hog(cv::Size(64, 64),  // WinSize
                          cv::Size(8, 8),  // blocksize
                          cv::Size(4, 4),  // blockStride
                          cv::Size(8, 8),  // CellSize
                          9,  // nbins,
        1,  // derivAper,
        -1,  // winSigma,
        0,  // histogramNormType,
        0.2,  // L2HysThresh,
        1,  // gammal correction,
        64,  // nlevels=64
        1);  // Use signed gradients
    hog.compute(images[0], discriptor);
    int featureSize = discriptor.size();

    std::cout << "FeatureSize" << featureSize << std::endl;
    int numberOfSamples = images.size();
    cv::Mat samples(numberOfSamples, featureSize, CV_32F);

    // Format the HOG samples
    for (int i = 0; i < numberOfSamples; i++) {
      discriptor.clear();
      hog.compute(images[i], discriptor);
      for (int k = 0; k < featureSize; k++) {
        samples.ptr<float>(i)[k] = discriptor[k];
      }
    }

    std::cout << "ExtractHOG completes" << std::endl;

    // Create positive and negative labels
    cv::Mat labels(numberOfSamples, 1, CV_32S);
    labels.rowRange(0, pos_num) = 1.0;
    labels.rowRange(pos_num, numberOfSamples) = -1.0;

    // Create SVM Classifier
    svm = cv::ml::SVM::create();
    svm->setType(cv::ml::SVM::C_SVC);
    svm->setKernel(cv::ml::SVM::LINEAR);
    cv::Ptr < cv::ml::TrainData > trainData = cv::ml::TrainData::create(
        samples, cv::ml::SampleTypes::ROW_SAMPLE, labels);
    svm->trainAuto(trainData);
    std::string filename = savePath + prefix + saveName + ext;
    svm->save(filename);

    std::cout << "Training completes" << std::endl;
    // GOOGLETESTLENGTH
  } else {  // Load classifier
    svm = cv::ml::SVM::create();
    svm->setType(cv::ml::SVM::C_SVC);
    svm->setKernel(cv::ml::SVM::LINEAR);
    svm = cv::ml::SVM::load(loadPath);
    std::cout << "Load process completes" << std::endl;

    // Test Samples
    if (testSampleFlag) {
      std::vector<float> testingDecs;
      cv::HOGDescriptor hog(cv::Size(64, 64),  // WinSize
                            cv::Size(8, 8),  // blocksize
                            cv::Size(4, 4),  // blockStride
                            cv::Size(8, 8),  // CellSize
                            9,  // nbins,
          1,  // derivAper,
          -1,  // winSigma,
          0,  // histogramNormType,
          0.2,  // L2HysThresh,
          1,  // gammal correction,
          64,  // nlevels=64
          1);  // Use signed gradients
      cv::Mat testSample = cv::imread("../expSamples/testing/1.jpg");
      cv::resize(testSample, testSample, cv::Size(64, 64));
      cv::GaussianBlur(testSample, testSample, cv::Size(3, 3), 1);
      cv::imshow("test", testSample);
      cv::waitKey();
      cv::destroyWindow("test");
      hog.compute(testSample, testingDecs);
      cv::Mat predictions;
      svm->predict(testingDecs, predictions);
      std::cout << "Prediction Sample Test (1 dog: -1 not dog): "
          << predictions.at<float>(0) << std::endl;
    }
    // GOOGLETEST LENGTH
  }
}

// Extract from Test_HOG.hpp from OPENCV3
void Classifier::get_svm_detector() {
  std::cout << "Begin computing primal support vector" << std::endl;
  // get the support vectors
  cv::Mat sv = svm->getSupportVectors();
  const int sv_total = sv.rows;

  // get the decision function
  cv::Mat alpha, svidx;
  double rho = svm->getDecisionFunction(0, alpha, svidx);
  CV_Assert(alpha.total() == 1 && svidx.total() == 1 && sv_total == 1);
  CV_Assert(
      (alpha.type() == CV_64F && alpha.at<double>(0) == 1.)
          || (alpha.type() == CV_32F && alpha.at<float>(0) == 1.f));
  CV_Assert(sv.type() == CV_32F);

  primalSupportVector.clear();
  primalSupportVector.resize(sv.cols + 1);
  std::memcpy(&primalSupportVector[0], sv.ptr(),
              sv.cols * sizeof(primalSupportVector[0]));
  primalSupportVector[sv.cols] = static_cast<float>(-rho);
}

void Classifier::predictImg(DetectedImg& detectedImgs) {
  // GOOGLETEST Size
  std::cout << "PredictImg process begins" << std::endl;
  cv::HOGDescriptor hog(cv::Size(64, 64),  // WinSize
                        cv::Size(8, 8),  // blocksize
                        cv::Size(4, 4),  // blockStride
                        cv::Size(8, 8),  // CellSize
                        9,  // nbins,
      1,  // derivAper,
      -1,  // winSigma,
      0,  // histogramNormType,
      0.2,  // L2HysThresh,
      1,  // gammal correction,
      64,  // nlevels=64
      1);  // Use signed gradients

  hog.setSVMDetector(primalSupportVector);
  std::vector < cv::Rect > detections;
  std::vector<double> foundWeights;

  for (int i = 0; i < detectedImgs.getSize(); i++) {
    int dogAlert = -1;
    cv::Mat street = detectedImgs.getImgs(i);
    cv::GaussianBlur(street, street, cv::Size(3, 3), 7);
    cv::resize(street, street, cv::Size(500, 400));

    // cv::imshow("HI",street);
    // cv::waitKey();
    hog.detectMultiScale(street, detections, foundWeights, 0, cv::Size(4, 4));
    for (size_t i = 0; i < detections.size(); i++) {
      if (foundWeights[i] > 1 && detections[i].y > 140
          && foundWeights[i] < 3.5) {
        cv::rectangle(street, detections[i], cv::Scalar(0, 255, 0), 1);
        dogAlert = 1;
      }
    }
    cv::imshow("streetView", street);
    cv::waitKey();
    cv::destroyWindow("streetView");
    detectedImgs.setResult(dogAlert);
  }
}

void Classifier::imgInit(std::string &trainPath) {
  if (loadFlag) {
    extractHOGandTrain();
  } else {
    images.clear();
    cv::Mat img;
    boost::filesystem::path p(trainPath);
    boost::filesystem::directory_iterator end_itr;
    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; itr++) {
      cv::Mat resizedImg;
      img = cv::imread(itr->path().string());
      cv::resize(img, resizedImg, cv::Size(64, 64));
      images.push_back(resizedImg);
      pos_num = pos_num + 1;
    }

    if (images.empty()) {
      std::cout << "Error in loading postive samples" << std::endl;
    }

    boost::filesystem::path p2("../expSamples/non_dog/");
    boost::filesystem::directory_iterator end_itr2;
    for (boost::filesystem::directory_iterator itr2(p2); itr2 != end_itr2;
        itr2++) {
      img = cv::imread(itr2->path().string());
      images.push_back(img);
    }

    if (images.size() == pos_num) {
      std::cout << "Error in loading negative samples" << std::endl;
    }

    std::cout << "Init completes" << std::endl;
    imgDenoise();
    extractHOGandTrain();
  }
  get_svm_detector();
  // predictImg();
}

