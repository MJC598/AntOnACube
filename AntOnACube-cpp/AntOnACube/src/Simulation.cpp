#include "Simulation.h"

/// <summary>
/// Constructor for Simulation, creates thread pool and random number generator through seeding
/// </summary>
/// <param name="numSims"></param>
/// <param name="graph"></param>
/// <param name="seed"></param>
Simulation::Simulation(unsigned long numSims, Graph* graph, unsigned int seed) {
	this->threadPool = new ThreadPool();
	this->numSims = numSims;
	this->graph = graph;
	this->seed = seed;
	RandomNumberGenerator* rng = new RandomNumberGenerator(seed);
	totalSum = 0;
}

/// <summary>
/// Core Driver function to run the simulation
/// </summary>
void Simulation::runSim() {
	this->threadPool->start();
	for (unsigned long i = 0; i < this->numSims; i++) {
		Ant* ant = new Ant(graph->vertices[0], graph->vertices[6], this->graph, rand());
		this->ants.push_back(ant);
		this->threadPool->queueJob([&]() { ant->move(); });
	}
	this->threadPool->stop();

	for (Ant* ant : this->ants) {
		this->totalSum += ant->totalTimeTraveled;
	}
}

/// <summary>
/// Helper Function to Return the Mean
/// </summary>
/// <returns></returns>
double Simulation::getMean() {
	return (double)totalSum / (double)numSims;
}

/// <summary>
/// Helper Function to Return the Standard Deviation
/// </summary>
/// <returns></returns>
double Simulation::getStandardDeviation() {
	double sumUp = 0;
	double mean = getMean();
	for (Ant* ant : this->ants) {
		double variance = ant->totalTimeTraveled - mean;
		sumUp += pow(variance, 2);
	}
	return sumUp / (double)numSims;
}

Simulation::~Simulation() {
	delete(threadPool);
	delete(rng);
}
