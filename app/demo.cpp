/** @file demo.cpp
 * @brief This is the demo cpp that calls a classifier class and sets up the path variables
 * necessary for class constructor.
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.*
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Classifier.hpp"

void dogClassifierInit(DetectedImg& imgs) {
  std::string dogPath = ("../expSamples/dog/");
  std::string loadDogPath = ("../Classifier_Dog.yml");
  Classifier classifierDog(loadDogPath, true, true);
  classifierDog.imgInit(dogPath);
  classifierDog.predictImg(imgs);

  /*
   Classifier classifierDog;
   classifierDog.setSavePath("../");
   classifierDog.setSaveName("Dog");
   classifierDog.imgInit(dogPath);
   */
}

int main() {
  cv::Mat street1 = cv::imread("../expSamples/StreetView/street3.jpeg");
  cv::Mat street2 = cv::imread("../expSamples/StreetView/street8.jpeg");
  cv::Mat street3 = cv::imread("../expSamples/StreetView/street4.jpeg");
  DetectedImg detectedImg;
  detectedImg.loadImgs(street1);
  detectedImg.loadImgs(street2);
  detectedImg.loadImgs(street3);
  dogClassifierInit(detectedImg);

  for (int i = 0; i < detectedImg.getSize(); i++) {
    if (detectedImg.viewResult(i) == 1)
      std::cout << "Image_" << i << " has dogs" << std::endl;
    else
      std::cout << "Image_" << i << " has no dog" << std::endl;
  }
  return 0;
}
