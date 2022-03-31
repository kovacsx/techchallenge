#include "vehicle.h"

#include <cmath>

using namespace std;

Vehicle::Vehicle(int16_t _northPosition, int16_t _eastPosition, 
					int16_t _orientation, int16_t _speed) 
						: northPosition(_northPosition), 
						eastPosition(_eastPosition),
						orientation(_orientation),
						speed(_speed) {

}

std::pair<float, float> Vehicle::calculateVehiclePositionInTime(float currentTime) const {
	return pair(0, 0);
}

float Vehicle::distanceToPosition(const std::pair<float, float> position) const {

	const auto dx = fabs(position.first - northPosition);
	const auto dy = fabs(position.second - eastPosition);

	return sqrt(pow(dx, 2) + pow(dy, 2));
}

float Vehicle::distanceToVehicle(const Vehicle &vehicle) const {
	return distanceToPosition(pair(vehicle.northPosition, vehicle.eastPosition));
}