#pragma once
#include <mutex>
#include <random>

class RandomNumberGenerator {
public:
	unsigned int seed;
	std::mutex mutex;
	void getRandomNumber(int* ret);
	RandomNumberGenerator(unsigned int seed);
};