#include <iostream>
#include <memory>
#include <vector>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include "sample1.hpp"  

int main()
{
    std::vector<cv::Mat> imageVec;
    boost::filesystem::path p("../expSamples/dog/");
    boost::filesystem::directory_iterator end_itr;
    
    for(boost::filesystem::directory_iterator itr(p); itr != end_itr; itr++){
    	cv::Mat img;
    	img = cv::imread(itr->path().string());
    	imageVec.push_back(img);


    }
    
    std::cout << "Vec size" << imageVec.size() << std::endl;
    return 0;
}
