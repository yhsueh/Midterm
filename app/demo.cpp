/** @file demo.cpp
* @brief Classifier class that uses the extracted HOG features of the sample
* images to train linear SVM. 
* @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
*
* A binary classifier class is created to train to detect dogs in a random images.
*/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Classifier.hpp"

void init() {
  std::string dogPath = ("../expSamples/dog/");
  std::string loadDogPath = ("../Classifier_Dog.yml");
  std::string streetImgPath = ("../expSamples/StreetView/street9.jpeg");
  Classifier classifierDog(loadDogPath, true, true);
  classifierDog.imgInit(dogPath);
  classifierDog.predictImg(streetImgPath);

  /*
   Classifier classifierDog;
   classifierDog.setSavePath("../");
   classifierDog.setSaveName("Dog");
   classifierDog.imgInit(dogPath);
   */
}

int main() {
  init();
  return 0;
}
