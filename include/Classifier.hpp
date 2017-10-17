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
	cv::Mat streetView;
	std::string loadPath;
	std::string savePath; //Saving classifier
	std::string saveName;
	std::vector<cv::Mat>images;
	std::vector<float> primalSupportVector;
	unsigned pos_num;
	bool loadFlag;
	bool testSampleFlag;
	void imgDenoise();
	void extractHOGandTrain();
	void get_svm_detector();

	public:
		Classifier();
		Classifier(bool flag, bool flag2, std::string& path): loadFlag(flag),
															testSampleFlag(flag2),
															loadPath(path){};
		
		void imgInit(std::string&);		
		void setSavePath(std::string savepath){savePath = savepath;}
		void setSaveName(std::string savename){saveName = savename;}	
		bool predictImg(std::string);	
};