#include "random.hpp"

int Random::irange(int a, int b) {
	return (rand()%b)+a;
}

float Random::frange(float a, float b) {
	std::random_device rd;
	std::uniform_real_distribution<float> dist(a,b);
	auto resault = dist(rd);
	return resault;
}
