#include "collisionDetector.h"

namespace CollisionDetector {

	bool detectCollision(const Vehicle &vehicle1, const Vehicle &vehicle2, 
							const float crashThreshold, 
							const float timeWindow) {

		float currentDistance = vehicle1.distanceToVehicle(vehicle2);
		float currentTime = 0;

		while(currentDistance > crashThreshold && currentTime < timeWindow) {
			currentTime += 1;
		}

		return currentDistance <= crashThreshold;
	}
}
