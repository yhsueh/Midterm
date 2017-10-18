/** @file ContactInfo.hpp
 * @brief Classifier class generates binary class classifier from image samples.
 * images to train linear SVM. 
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
 *
 * A binary classifier class is created to train to detect dogs/blind humans in a random images.
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class ContactInfo {
 public:
  ContactInfo()
      : name(""),
        phone(""),
        occupation("") {
  }
  void setContactInfo(string Name, string Phone, string job)
      : name(Name),
        phone(Phone),
        occupation(job) {
  }
  std::string getContactInfoPhone() {
    return phone;
  }
  std::string getContactInfoName() {
    return name;
  }
  std::string getContactInfoJob() {
    return occupation;
  }

 private:
  std::string name;
  std::string phone;
  std::string occupation;
};
