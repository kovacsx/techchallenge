
#include "collisionDetector.h"
#include "pointdistance.h"
#include <iostream>

using namespace std;	

namespace CollisionDetector {

	bool detectCollision(const Vehicle &vehicle1, const Vehicle &vehicle2, 
							const float crashThreshold, 
							const float timeWindow) {

		const float minTimeStep = 0.01;

		float currentDistance = vehicle1.distanceToVehicle(vehicle2);
		float currentTime = 0;

		float timeStep = 1.0;

		int iters = 0;

		while(currentDistance > crashThreshold && currentTime < timeWindow) {

			auto newTime = currentTime + timeStep;

			auto newPosition1 = vehicle1.calculateVehiclePositionInTime(newTime);
			auto newPosition2 = vehicle2.calculateVehiclePositionInTime(newTime);

			auto newDistance = pointDistance(newPosition1, newPosition2);

			if(newDistance >= currentDistance) {
				if(timeStep > minTimeStep) {
					timeStep /= 2.0;
					continue;
				} else {
					cout << "detectCollision iters: " << iters++ << ", collides: No" << endl;
					return false;
				}
			}

			iters++;
			currentTime = newTime;
			currentDistance = newDistance;
		}
		const bool willCollide = (currentDistance <= crashThreshold);
		cout << "detectCollision iters: " << iters++ << ", collides: " << (willCollide ? "Yes!" : "No!") << endl;
		return willCollide;
	}
}
