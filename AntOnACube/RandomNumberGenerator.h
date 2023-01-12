#pragma once
#include <mutex>
#include <random>

class RandomNumberGenerator {
public:
	unsigned int seed;
	void getRandomNumber(int* ret);
	RandomNumberGenerator(unsigned int seed);
};