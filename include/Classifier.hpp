#include <iostream>
#include <vector>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#pragma once
class Classifier{
	cv::CascadeClassifier classifier;
	std::vector<cv::Mat> images;

	public:
		Classifier();
		void imgInit(std::string&);
		void imgDenoise();
		void train();
		cv::CascadeClassifier getClassifier(){return classifier;}
};