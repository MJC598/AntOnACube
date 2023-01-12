#include "Simulation.h"

Simulation::Simulation(unsigned long numSims, Graph* graph, unsigned int seed) {
	this->threadPool = new ThreadPool();
	this->numSims = numSims;
	this->graph = graph;
	this->seed = seed;
	RandomNumberGenerator* rng = new RandomNumberGenerator(seed);
	totalSum = 0;
}

void Simulation::runSim() {
	this->threadPool->Start();
	for (unsigned long i = 0; i < this->numSims; i++) {
		Ant* ant = new Ant(graph->vertices[0], graph->vertices[6], this->graph, rand());
		this->ants.push_back(ant);
		this->threadPool->QueueJob([&]() { ant->move(); });
		//this->threadVector.emplace_back([&]() { ant->move(this->rng); });
	}
	this->threadPool->Stop();
	/*for (auto& t : this->threadVector) {
		t.join();
	}*/

	for (Ant* ant : this->ants) {
		this->totalSum += ant->totalTimeTraveled;
	}
}

double Simulation::getMean() {
	return (double)totalSum / (double)numSims;
}

double Simulation::getStandardDeviation() {
	double sumUp = 0;
	double mean = getMean();
	for (Ant* ant : this->ants) {
		double variance = ant->totalTimeTraveled - mean;
		sumUp += pow(variance, 2);
	}
	return sumUp / (double)numSims;
}

