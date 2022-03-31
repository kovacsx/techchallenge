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

	ASSERT_FALSE(CollisionDetector::detectCollision(vehicle1, vehicle2));
}

/*
Static vehicle collision with driving vehicle
*/
TEST(DetectorTests, staticCollisionWithMovingVehicle) {
	Vehicle vehicle1 {200, 200, 0, 0};
	Vehicle vehicle2 {10, 10, 45, 10};

	ASSERT_TRUE(CollisionDetector::detectCollision(vehicle1, vehicle2));
}


/*
Static vehicle doe not collide with driving vehicle (close miss)
*/

/*
Static vehicle does collide with driving vehicle (because crashThreshold)
*/


/*
Vehicles from different directions (no collision)
*/

/*
Vehicles from different directions (with collision)
*/

