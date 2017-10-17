#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Classifier.hpp"  

void init(){
	std::string dogPath = ("../expSamples/dog/");	
	std::string loadDogPath = ("../classifier.yml");
	Classifier classifierDog(1,loadDogPath);
	classifierDog.imgInit(dogPath);
	
}

int main()
{
    init();
    return 0;
}
