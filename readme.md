# C++ Boilerplate
[![Build Status](https://travis-ci.org/yhsueh/Midterm.svg?branch=master)](https://travis-ci.org/yhsueh/Midterm)

[![Coverage Status](https://coveralls.io/repos/github/yhsueh/Midterm/badge.svg?branch=master)](https://coveralls.io/github/yhsueh/Midterm?branch=master)
---

## Sprint Planning Google Spreadsheet
https://docs.google.com/spreadsheets/d/1WPp6IvV1L7NysiTNfeEvrVmxwbvYig_B03FKdd1seJg/edit?usp=sharing

## Overview

    This program is object detection modoule of the robot that helps to expel stray dogs from the area where children or elders are likely to go such as schools or supermarkets. In developing countries, stray dogs can be dangerous as they can be infected with rabies. To stop them from harming innocent beings, the home-made robot is created to patrol the streets and deter dogs. When the robot observes a dog-like object, it would send messages to residents and students nearby so they can avoid the area. At the same time, the robot would trigger the alarm to deter dogs. The robot is helpful, but it might scare off the vision impaired peoples' guiding dogs when it is doing its work. Therefore, if the robot detects humans and dogs together, then it would do nothing.

    Due to time constraint, the program is not completed except for the object detection module, which is the core feature of this program. The planning and prioritized user stories of this project can be viewed from google spreadsheet attached above. The spreadsheet contains product backlog, iterative backlog, and bug log.

    The pipeline of the object detection module is: prepare positive and negative samples, denoise and resizes all the images to 64x64 pixels, extract HOG features from the images, train the classifier with HOG features, detect the object from a random image with the classifier.

    The noise of the images is removed by appling guassian filter. It is simple and effective at reducing guassian noise. The HOG + SVM technique is popular at identifying objects through their shapes and contours. Another popular technique is cascade Harr training, but it is relatively time consuming and is worse than HOG for this application. Nevertheless, Cascade Harr prevails HOG on face recognitions. 

    The performance of the object detection module is decent, but there are lots of false postives results. The possible reason is that the positive images used to train the classifier consisted of frontal, real and side view of dogs. The mixture of different views of dogs could affect the performance. A demo is presented in the folder, the instructions of how to the demo is addressed below. The demo shows three successful cases of dog detection. 

## License

- Preamble: 
    This Agreement, signed on Oct 17, 2017 (hereinafter: Effective Date) governs the relationship between UMD, a Business Entity, (hereinafter: Licensee) and ENPM, a private person whose principal place of business is UMD (hereinafter: Licensor). This Agreement sets the terms, rights, restrictions and obligations on using Dog Expeller (hereinafter: The Software) created and owned by Licensor, as detailed herein

- License Grant:    

    Limited: Licensee may use Software for the purpose of:
        Running Software on Licensee’s Website[s] and Server[s];

        Allowing 3rd Parties to run Software on Licensee’s Website[s] and Server[s];

        Publishing Software’s output to Licensee and 3rd Parties;

        Distribute verbatim copies of Software’s output (including compiled binaries);

        Modify Software to suit Licensee’s needs and specifications.

    This license is granted perpetually, as long as you do not materially breach it.

    Binary Restricted: Licensee may sublicense Software as a part of a larger work containing more than Software, distributed solely in Object or Binary form under a personal, non-sublicensable, limited license. Such redistribution shall be limited to unlimited codebases.

    Non Assignable & Non-Transferable: Licensee may not assign or transfer his rights and duties under this license.

    Commercial, Royalty Free: Licensee may use Software for any purpose, including paid-services, without any royalties

    Including the Right to Create Derivative Works: Licensee may create derivative works based on Software, including amending Software’s source code, modifying it, integrating it into a larger work or removing portions of Software, as long as no distribution of the derivative works is made 

- Term & Termination: 
    The Term of this license shall be until terminated. Licensor may terminate this Agreement, including Licensee’s license in the case where Licensee :

    became insolvent or otherwise entered into any liquidation process; or

    exported The Software to any jurisdiction where licensor may not enforce his rights under this agreements in; or

    Licensee was in breach of any of this license's terms and conditions and such breach was not cured, immediately upon notification; or

    Licensee in breach of any of the terms of clause 2 to this license; or

    Licensee otherwise entered into any arrangement which caused Licensor to be unable to enforce his rights under this License.

## Dependencies
Two shared libraries are used in this project, OpenCV and Boost filesystem libraries. The program won't run without installing them on the machine. Fortunately, these libraries can be installed easily on Ubuntu. First, to install OpenCV, switch to the project root directory, and type the following command. The bash file is created by milq.

```
bash install0opencvInstall.sh
```
by http://milq.github.io/install-opencv-ubuntu-debian/

Second, the boost filesystem library is installed to facilitate files and directories manipulations. It is available in Ubuntu package repository. To install it, type the following commands in command window:

```
sudo apt-get update
sudo apt-get install libboost-all-dev
```


## Standard build via command-line
```
git clone --recursive https://github.com/yhsueh/Midterm
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Run Demo

- Demo 
    To run demo, after building the project with cmake and make, run the shell-app executables in app folder under project root directory. 
    In demo mode, the pre-trained SVM would be used to identify objects. To switch to training mode, simply change the mode variable in demo.cpp to 0, and the program will re-train a classifier.
    Initially, the sample image of a vision impaired person will pop up, and it would be classified as non-dog object, return 01. Subsequently, three street views are being tested with SVM, and the results would be printed in the terminal.

## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format
