#include "Simulation.h"

void Simulation::runSim() {

	for (unsigned long i = 0; i < this->numSims; i++) {
		Ant* ant = new Ant(graph->vertices[0], graph->vertices[6], this->graph);
		this->ants.push_back(ant);
		this->threadVector.emplace_back([&]() { ant->move(); });
	}
	for (auto& t : this->threadVector) {
		t.join();
	}

	for (Ant* ant : this->ants) {
		this->totalSum += ant->totalTimeTraveled;
	}
}
