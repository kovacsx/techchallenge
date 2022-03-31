#pragma once

#include <cstdint>

struct Vehicle {
	int16_t northPosition; // [m] vehicle position relative to a reference point in North (y) direction
	int16_t eastPosition; // [m] vehicle position relative to a reference point in East (x) direction
	int16_t orientation; // [deg] direction the vehicle is currently going
	int16_t speed; // [m/s] vehicle speed in the direction of “orientation”
};