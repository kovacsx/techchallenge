#pragma once

#include <cstdint>
#include <utility>

struct Vehicle {
	int16_t northPosition; // [m] vehicle position relative to a reference point in North (y) direction
	int16_t eastPosition; // [m] vehicle position relative to a reference point in East (x) direction
	int16_t orientation; // [deg] direction the vehicle is currently going
	int16_t speed; // [m/s] vehicle speed in the direction of “orientation”

	// calculates vehicles position after currentTime seconds.
	std::pair<float, float> calculateVehiclePositionInTime(float currentTime);

	// calculate distance to other position
	float distanceToPosition(const std::pair<float, float> position);
};