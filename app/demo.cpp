#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include "Classifier.hpp"  

void init(){
	std::string dogPath = ("../expSamples/dog/");	
	Classifier classifierDog;
	classifierDog.imgInit(dogPath);
}

int main()
{
    init();
    return 0;
}
