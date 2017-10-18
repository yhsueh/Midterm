/** @class ContactInfo.hpp
 * @brief This class stores the identity, name, and number of the contact.
 * @copyright Copyright 2017 Yuyu Hsueh. All rights reserved.
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
