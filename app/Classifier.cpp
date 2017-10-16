#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp> 
#include <opencv2/objdetect/objdetect.hpp>
#include "Classifier.hpp"

Classifier::Classifier(){}

void Classifier::imgInit(std::string &trainPath){	
	std::vector<cv::Mat> imageVec;
    boost::filesystem::path p(trainPath);
    boost::filesystem::directory_iterator end_itr;
    
    for(boost::filesystem::directory_iterator itr(p); itr != end_itr; itr++){
    	cv::Mat img;
    	img = cv::imread(itr->path().string());
    	images.push_back(img);
    }
    std::cout << "IMG SIZE: "<< images.size() << std::endl;
}

void Classifier::imgDenoise(){


}

void Classifier::train(){


}

