#include "gtest/gtest.h"

#include "pointdistance.h"
#include "vehicle.h"

TEST(PointDistanceTests, sanityCheck) {
	EXPECT_FLOAT_EQ(pointDistance({0,0}, {1, 1}), sqrt(2.0));
}


TEST(VehicleTests, sanityCheck) {
	Vehicle v;
	ASSERT_TRUE(true);
}