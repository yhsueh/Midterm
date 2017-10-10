#include <gtest/gtest.h>
#include <opencv2/core/core.hpp>
#include <memory>
#include "sample1.hpp"
TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}

TEST(ContinuousTEST,should_pass2){
	auto A = std::make_shared<cv::Mat>(3,3,CV_32F);
	EXPECT_EQ(1, continuousTest(A));
}
