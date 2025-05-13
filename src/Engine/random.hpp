#ifndef MATH_RANDOM
#define MATH_RANDOM

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Random {
public:
	static int irange(int a, int b);

	static float frange(float a, float b);
};

#endif
