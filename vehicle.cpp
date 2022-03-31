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
	return pair(0, 0);
}

float Vehicle::distanceToPosition(const Position &toPosition) const {

	return pointDistance(position, toPosition);
}

float Vehicle::distanceToVehicle(const Vehicle &vehicle) const {
	return distanceToPosition(vehicle.position);
}