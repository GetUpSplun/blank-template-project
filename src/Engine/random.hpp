#ifndef MATH_RANDOM
#define MATH_RANDOM

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Random {
public:
	static int irange_random(int a, int b);

	static float frange_random(float a, float b);
};

#endif
