 #include <opencv2/core/core.hpp>
 #include "sample1.hpp"


  int continuousTest(int a){
    	if (a == 1){
    		cv::Mat A;
            A.create(3,3,CV_32F);
    		if (A.isContinuous()){
    			return 1;
    		}
    		else{
    			return -1;
    		}
    	}
    	else{
    		return 0;
    	}
	}