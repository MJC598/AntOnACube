#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(unsigned int seed) { 
	srand(seed);
	this->seed = seed;
}

void RandomNumberGenerator::getRandomNumber(int* ret) {
	//mutex.lock();
	*ret = std::rand() % 3;
	//mutex.unlock();
}