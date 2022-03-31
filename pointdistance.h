#pragma once

#include <utility>
#include <cmath>

// Calculate distance between 2 "points"
static float pointDistance(std::pair<float, float> point1, 
							std::pair<float, float> point2) {

	const auto dx = fabs(point1.first - point2.first);
	const auto dy = fabs(point1.second - point2.second);

	return sqrt(pow(dx, 2) + pow(dy, 2));
}