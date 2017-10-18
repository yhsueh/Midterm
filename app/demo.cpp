/** @file demo.cpp
 * @brief This is where classifier class is called and set up.
 * @author Yuyu Hsueh
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 * Licensor hereby grants Licensee a Sublicensable, Non-assignable & non-transferable, Pepetual, Commercial, Royalty free.
 * Including the rights to create but not distribute derivative works, Non-exclusive license, all with accordance with the 
 * terms set forth and other legal restrictions set forth in 3rd party software used while running Software.
 */

#include <string>
#include <vector>
#include <memory>
#include "Classifier.hpp"

void dogClassifierInit(DetectedImg& imgs, int mode) {
  /**
   * @brief Dog classifier initialization. Mode 1 loads classifier. Mode 2 trains new classifier.
   * @param DetectedImg, int
   * @return none
   */
  std::string dogPath = ("../expSamples/dog/");
  std::string loadDogPath = ("../Classifier_Dog.yml");
  if (mode) {
    Classifier classifierDog(loadDogPath, true, true);
    classifierDog.imgInit(dogPath);
    classifierDog.predictImg(imgs);
  } else {
    Classifier classifierDog;
    classifierDog.setSavePath("../");
    classifierDog.setSaveName("Dog");
    classifierDog.imgInit(dogPath);
    classifierDog.predictImg(imgs);
  }
}

int main() {
  /**
   * @brief In this demo, three street views are tested, and the results from SVM analysis will be returned along with the image.
   * @param none
   * @return none
   */
  cv::Mat street1 = cv::imread("../expSamples/StreetView/street3.jpeg");
  cv::Mat street2 = cv::imread("../expSamples/StreetView/street8.jpeg");
  cv::Mat street3 = cv::imread("../expSamples/StreetView/street4.jpeg");
  DetectedImg detectedImg;
  detectedImg.loadImgs(street1);
  detectedImg.loadImgs(street2);
  detectedImg.loadImgs(street3);
  int mode = 0; /**< mode 0: train classifier; mode 1: load pretrained classifier*/

  dogClassifierInit(detectedImg, mode);

  for (int i = 0; i < detectedImg.getSize(); i++) {
    if (detectedImg.viewResult(i) == 1)
      std::cout << "Image_" << i << " has dogs" << std::endl;
    else
      std::cout << "Image_" << i << " has no dog" << std::endl;
  }
  return 0;
}
