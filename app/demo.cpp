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
