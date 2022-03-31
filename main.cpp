#include <iostream>
#include "challenge.h"

using namespace std;

int main(int argc, char **argv) {

	cout << "Hello from main!" << endl;

	Challenge c;

	cout << "default output:" << c.doSomethingWithInt() << endl;
	cout << "output 21:" << c.doSomethingWithInt(21) << endl;
	cout << "output 20:" << c.doSomethingWithInt(20) << endl;

	return 0;
}