#pragma once

#include <cstdint>
#include <utility>

/**

	Vehicle class that models basic vehicle data

*/
struct Vehicle {
	int16_t northPosition; // [m] vehicle position relative to a reference point in North (y) direction
	int16_t eastPosition; // [m] vehicle position relative to a reference point in East (x) direction
	int16_t orientation; // [deg] direction the vehicle is currently going
	int16_t speed; // [m/s] vehicle speed in the direction of “orientation”

	Vehicle(int16_t north = 0, int16_t east = 0, int16_t orient = 0, int16_t speed = 0);

	// calculates vehicles position after currentTime seconds.
	//
	// currentTime : [sec] time from beginning of the movement in sec
	//
	// Returns: the vehicle expected position after currentTime seconds.(>= 0)
	//
	// Throws: std::invalid_argument
	//
	std::pair<float, float> calculateVehiclePositionInTime(float currentTime) const;

	// calculate distance to other position
	float distanceToPosition(const std::pair<float, float> position) const;

	// calculate distance to other vehicle
	float distanceToVehicle(const Vehicle &vehicle) const;
};