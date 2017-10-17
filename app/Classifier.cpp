#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp> 
#include <opencv2/objdetect/objdetect.hpp>
#include "Classifier.hpp"

Classifier::Classifier(){
    this->savePath = "../classifier.yml";
    this->loadPath = "";
    this->loadFlag = 0;
    this->pos_num = 0;
}

void Classifier::imgDenoise(){
    cv::Mat GrayImg,denoised;
    for(auto& i : this->images){
        cv::GaussianBlur(i,denoised,cv::Size(3,3),1);
        cv::cvtColor(denoised,GrayImg, cv::COLOR_BGR2GRAY);
        i = GrayImg;
    }
    std::cout << "Denoise Process Completes" << std::endl;
}

void Classifier::extractHOGandTrain(){
    //Create the HOG samples
    cv::Mat sampleMatrix;
    std::vector<float>discriptor;
    std::cout << "HI" << std::endl;
    std::cout << "LOADFLAG" << this->loadFlag << std::endl;
    //Create Classifier
    if(!(this->loadFlag)){    
        std::cout << "HIHI" << std::endl;
        cv::HOGDescriptor hog(
        cv::Size(64,64), //WinSize
        cv::Size(8,8), //blocksize
        cv::Size(4,4), //blockStride
        cv::Size(8,8),//CellSize
                  9, //nbins,
                  1, //derivAper,
                 -1, //winSigma,
                  0, //histogramNormType,
                0.2, //L2HysThresh,
                  1,//gammal correction,
                  64,//nlevels=64
                  1);//Use signed gradients 
        hog.compute(images[0],discriptor);
        int featureSize = discriptor.size();
        int numberOfSamples = images.size();
        cv::Mat samples(numberOfSamples,featureSize,CV_32F);

        //Format the HOG samples
        for(int i = 0; i < numberOfSamples; i++){
            discriptor.clear();
            hog.compute(images[i],discriptor);
            for(int k = 0; k < featureSize; k++){
                samples.ptr<float>(i)[k] = discriptor[k];
            }
        } 

        std::cout<<"ExtractHOG completes" << std::endl;

        //Create positive and negative labels
        cv::Mat labels(numberOfSamples,1,CV_32S);
        labels.rowRange(0,this->pos_num) = 1.0;
        labels.rowRange(this->pos_num,numberOfSamples) = -1.0; 
        
        //Create SVM Classifier
        this->svm = cv::ml::SVM::create();
        this->svm->setType(cv::ml::SVM::C_SVC);
        this->svm->setKernel(cv::ml::SVM::LINEAR);
        cv::Ptr<cv::ml::TrainData> trainData = cv::ml::TrainData::create(
                                                samples,
                                                cv::ml::SampleTypes::ROW_SAMPLE,
                                                labels);
        this->svm->trainAuto(trainData);
        this->svm->save(this->savePath);

        std::cout<<"Training completes" << std::endl;
    }
    else{//Load classifier
        this->svm = cv::ml::SVM::create();
        this->svm->setType(cv::ml::SVM::C_SVC);
        this->svm->setKernel(cv::ml::SVM::LINEAR);
        this->svm = cv::ml::SVM::load(this->loadPath);
        std::cout<< "Load process completes" << std::endl;
    }
    
}

//void Classifier::predictImg(std::vector<cv::Mat>imgs){








//}


void Classifier::imgInit(std::string &trainPath){
    if (loadFlag){
        this->extractHOGandTrain();
    }
    else{

        this->images.clear();    
        this->pos_num = 0;
        cv::Mat img;
        boost::filesystem::path p(trainPath);
        boost::filesystem::directory_iterator end_itr;
        for(boost::filesystem::directory_iterator itr(p); itr != end_itr; itr++){
        	cv::Mat resizedImg;
            img = cv::imread(itr->path().string());
            cv::resize(img,resizedImg, cv::Size(64,64));
        	this->images.push_back(resizedImg);
            this->pos_num = this->pos_num + 1;
        }

        if (this->images.empty()){
            std::cout << "Error in loading postive samples"<<std::endl;
        }

        boost::filesystem::path p2("../expSamples/non_dog/");
        boost::filesystem::directory_iterator end_itr2;
        for(boost::filesystem::directory_iterator itr2(p2); itr2 != end_itr2; itr2++){
            
            img = cv::imread(itr2->path().string());
            this->images.push_back(img);
        }
        
        if (this->images.size()==this->pos_num){
            std::cout << "Error in loading negative samples" << std::endl;
        }

        std::cout << "Init completes" << std::endl;
        this->imgDenoise();
        this->extractHOGandTrain();
    }
}




