#pragma once

#include <cstdint>
#include <utility>

/**

	Vehicle class that models basic vehicle data

*/

typedef std::pair<float, float> Position; // East / North position pair

struct Vehicle {

	Position position; // [Position] Vehicles initial position
	int16_t orientation; // [deg] direction the vehicle is currently going
	int16_t speed; // [m/s] vehicle speed in the direction of “orientation”

	// east [meters] vehicle position relative to a reference point in East (x) direction
	// north [meters] vehicle position relative to a reference point in North (y) direction

	Vehicle(int16_t east = 0, int16_t north = 0, int16_t orient = 0, int16_t speed = 0);

	// calculates vehicles position after currentTime seconds.
	//
	// currentTime : [sec] time from beginning of the movement in sec
	//
	// Returns: the vehicle expected position after currentTime seconds.(>= 0)
	//
	// Throws: std::invalid_argument
	//
	Position calculateVehiclePositionInTime(float currentTime) const;

	// calculate distance to other position
	float distanceToPosition(const Position &position) const;

	// calculate distance to other vehicle
	float distanceToVehicle(const Vehicle &vehicle) const;
};