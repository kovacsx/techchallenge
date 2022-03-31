#include "gtest/gtest.h"

#include "collisionDetector.h"

/*

Is vehicle colliding with "itself"

*/
TEST(DetectorTests, sanityCheck) {
	Vehicle vehicle;

	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle, vehicle));
}