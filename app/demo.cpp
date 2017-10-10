#include <opencv2/core/core.hpp>
#include <iostream>
#include <memory>
#include "sample1.hpp"
  

int main()
{
	auto A = std::make_shared<cv::Mat>(3,3,CV_32F);
	int a = continuousTest(A);

	std::cout << "a value is" << a << std::endl; 
    return 0;
}
