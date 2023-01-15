#pragma once
#include <thread>
#include<cmath>

#include "RandomNumberGenerator.h"
#include "Ant.h"
#include "ThreadPool.h"


class Simulation {
private:
	ThreadPool* threadPool;
	unsigned int seed;
	RandomNumberGenerator* rng;
	Graph* graph;
	std::vector<std::thread> threadVector;
public:
	std::vector<Ant*> ants;
	unsigned long numSims;
	unsigned long long totalSum;
	Simulation(unsigned long numSims, Graph* graph, unsigned int seed);
	void runSim();
	double getMean();
	double getStandardDeviation();
	~Simulation();

};