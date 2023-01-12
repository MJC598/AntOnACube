#pragma once
#include <thread>

#include "RandomNumberGenerator.h"
#include "Ant.h"


class Simulation {
private:
	unsigned int seed;
	RandomNumberGenerator* rng;
	Graph* graph;
	std::vector<std::thread> threadVector;
	std::vector<Ant*> ants;
public:
	unsigned long numSims;
	unsigned long long totalSum;
	Simulation(unsigned long numSims, Graph* graph, unsigned int seed);
	void runSim();

};