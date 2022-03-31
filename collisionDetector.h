#pragma once

#include "vehicle.h"


// Collision detector implements basic collision detection algorithm as per challenge description

namespace CollisionDetection {

	// v1 & v2 : [Vehicle] vehicles for which collision needs to be tested
	// crashThreshold : [m] At what distance vehicles are considered crashing [meters]
	bool detectCollision(const Vehicle &v1, const Vehicle &v2, float crashThreshold = 0.5);
}