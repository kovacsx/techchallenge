
#include "collisionDetector.h"
#include "pointdistance.h"
#include <iostream>

using namespace std;	

namespace CollisionDetector {

	/*

	Function implements gradient descent type of search for distance minimum over time.

	*/

	bool detectCollision(const Vehicle &vehicle1, const Vehicle &vehicle2, 
							const float crashThreshold, 
							const float timeWindow) {

		const float minTimeStep = 0.001;

		float currentDistance = vehicle1.distanceToVehicle(vehicle2);
		float currentTime = 0;

		float timeStep = 1.0;

		int iters = 0;

		// cout << "iter: " << iters << ", distance: " << currentDistance << endl;

		while(currentDistance > crashThreshold && currentTime < timeWindow) {

			auto newTime = currentTime + timeStep;

			auto newPosition1 = vehicle1.calculateVehiclePositionInTime(newTime);
			auto newPosition2 = vehicle2.calculateVehiclePositionInTime(newTime);

			auto newDistance = pointDistance(newPosition1, newPosition2);

			// cout << "iter: " << iters << ", distance: " << newDistance << endl;

			if(newDistance >= currentDistance) {
				if(fabs(timeStep) > minTimeStep) {
					// cout << "timestep decrease (" << iters << "): " << timeStep << " -> " << timeStep / 2.0 << endl;
					timeStep /= 2.0;
				} else {
					// cout << "detectCollision iters: " << iters++ << ", collides: No" << endl;
					return false;
				}

				// check for overshoot/undershoot
				auto prevPosition1 = vehicle1.calculateVehiclePositionInTime(newTime - timeStep);
				auto prevPosition2 = vehicle2.calculateVehiclePositionInTime(newTime - timeStep);
				auto prevDistance = pointDistance(prevPosition1, prevPosition2);

				if(prevDistance < newDistance) {
					// cout << "Inv timestep: " << timeStep << " -> " << -timeStep << endl;
					timeStep = -timeStep;
				}
				continue;
			}

			iters++;
			currentTime = newTime;
			currentDistance = newDistance;
		}
		const bool willCollide = (currentDistance <= crashThreshold);
		// cout << "detectCollision iters: " << iters++ << ", collides: " << (willCollide ? "Yes!" : "No!") << endl;
		return willCollide;
	}
}
