#include <gtest/gtest.h>
#include "sample1.hpp"
TEST(dummy, should_pass) {
  EXPECT_EQ(1, 1);
}

TEST(ContinuousTEST,should_pass2){
	EXPECT_EQ(1, continuousTest(1));
}
