#include "vehicle.h"
#include "pointdistance.h"

#include <cmath>

using namespace std;

Vehicle::Vehicle(int16_t eastPosition, int16_t northPosition,
					int16_t _orientation, int16_t _speed) 
						: position(eastPosition, northPosition),
						orientation(_orientation),
						speed(_speed) {

}

Position Vehicle::calculateVehiclePositionInTime(float currentTime) const {
	
	const float radOrient = orientation / 180.0 * M_PI;

	const float dx = cos(radOrient) * speed * currentTime;
	const float dy = sin(radOrient) * speed * currentTime;

	return pair(position.first + dx, position.second + dy);
}

float Vehicle::distanceToPosition(const Position &toPosition) const {
	return pointDistance(position, toPosition);
}

float Vehicle::distanceToVehicle(const Vehicle &vehicle) const {
	return distanceToPosition(vehicle.position);
}