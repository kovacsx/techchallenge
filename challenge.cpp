#include "challenge.h"

int Challenge::doSomethingWithInt(int paramValue) {
	if(paramValue % 2 == 1) {
		return paramValue * 2;
	}
	return paramValue / 2;
}