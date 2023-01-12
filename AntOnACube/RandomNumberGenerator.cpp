#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(unsigned int seed) { 
	srand(seed);
	this->seed = seed;
}

void RandomNumberGenerator::getRandomNumber(int* ret) {
	*ret = std::rand() % 3;
}