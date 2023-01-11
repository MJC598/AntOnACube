#pragma once
#include "Ant.h"
#include <thread>

class Simulation {
private:
	unsigned int seed;
	Graph* graph;
	std::vector<std::thread> threadVector;
	std::vector<Ant*> ants;
public:
	unsigned long numSims;
	unsigned long long totalSum;
	Simulation(unsigned long numSims, Graph* graph, unsigned int seed) : numSims(numSims), graph(graph), seed(seed) {
		srand(seed);
		totalSum = 0;
	}
	void runSim();

};