#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp> 
#include <opencv2/objdetect/objdetect.hpp>

class Classifier{
	cv::Ptr<cv::ml::SVM> svm;
	std::vector<cv::Mat> images;
	std::string loadPath;
	std::string savePath; //Saving classifier
    unsigned pos_num;
	bool loadFlag;

	public:
		Classifier();
		Classifier(int flag, std::string& path): loadFlag(flag),loadPath(path){};
		void imgDenoise();
		void extractHOGandTrain();
		void imgInit(std::string&);		
		void setSavePath(std::string& Name){savePath = Name;}
};