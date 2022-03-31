#include <iostream>

#include "collisionDetector.h"

using namespace std;

int main(int argc, char **argv) {

	cout << "Collision Detection challenge:" << endl;

	Vehicle v1{10, 10, 20, 30};
	Vehicle v2{20, 20, 20, 30};
	Vehicle v3{30, 50, 20, 10};

	cout << "    v1 does collide with v2: " << CollisionDetector::detectCollision(v1, v2) << endl;
	cout << "    v2 does collide with v3: " << CollisionDetector::detectCollision(v2, v3) << endl;
	cout << "    v1 does collide with v3: " << CollisionDetector::detectCollision(v1, v3) << endl;

	cout << endl << "File transfer challenge: TBI" << endl;

	cout << endl << "Marshalling challenge: TBI" << endl;

	cout << endl << "License file challenge: TBI" << endl;

	cout << endl << "Data mining challenge: TBI" << endl;

	return 0;
}