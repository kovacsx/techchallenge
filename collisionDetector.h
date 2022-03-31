#pragma once

#include "vehicle.h"


// Collision detector implements basic collision detection algorithm as per challenge description

namespace CollisionDetector {

	// v1 & v2 : [Vehicle] vehicles for which collision needs to be tested
	// crashThreshold : [m] At what distance vehicles are considered crashing [meters]
	// timeWindow : [sec] How far in the future collision detector should check
	bool detectCollision(const Vehicle &vehicle1, 
							const Vehicle &vehicle2, 
							const float crashThreshold = 0.5, 
							const float timeWindow = 600);
}