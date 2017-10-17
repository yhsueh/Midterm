# C++ Boilerplate
[![Build Status](https://travis-ci.org/yhsueh/Midterm.svg?branch=master)](https://travis-ci.org/yhsueh/Midterm)

[![Coverage Status](https://coveralls.io/repos/github/yhsueh/Midterm/badge.svg?branch=master)](https://coveralls.io/github/yhsueh/Midterm?branch=master)
---

## Sprint Planning Google Spreadsheet
https://docs.google.com/spreadsheets/d/1WPp6IvV1L7NysiTNfeEvrVmxwbvYig_B03FKdd1seJg/edit?usp=sharing

## Overview



## Standard install via command-line
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

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.


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
