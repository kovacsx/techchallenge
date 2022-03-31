#include "gtest/gtest.h"

#include "collisionDetector.h"

/*
Is vehicle colliding with "itself"
*/
TEST(DetectorTests, sanityCheck) {
	Vehicle vehicle {10, 10, 0, 10};

	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle, vehicle));
}


/*
Is vehicle collision threshold working
*/
TEST(DetectorTests, distanceThreshhold) {
	Vehicle vehicle1 {10, 10, 0, 0};
	Vehicle vehicle2 {10, 11, 0, 0};

	ASSERT_FALSE(CollisionDetector::detectCollision(vehicle1, vehicle2, 0.5));
	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle1, vehicle2, 1));
}

/*
Same direction, first overtakes second vehicle
*/
TEST(DetectorTests, goingSameDirectionOvertakes) {
	Vehicle vehicle1 {10, 10, 0, 10};
	Vehicle vehicle2 {10, 40, 0, 5};

	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle1, vehicle2));
}

/*
Same direction, first never reaches second vehicle
*/
TEST(DetectorTests, goingSameDirectionNeverCollides) {
	Vehicle vehicle1 {10, 10, 0, 5};
	Vehicle vehicle2 {10, 40, 0, 10};

	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle1, vehicle2));
}


/*
Will Static vehicle collides with driving vehicle (must collide)
*/


/*
Will Static vehicle collides with driving vehicle (must not collide)
*/


/*
Vehicles from different directions (no collision)
*/

/*
Vehicles from different directions (with collision)
*/

