/** @file Classifier.cpp
* @brief Classifier class that uses the extracted HOG features of the sample
* images to train linear SVM. 
* @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
*
* A binary classifier class is created to train to detect dogs in a random images.
*/
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
