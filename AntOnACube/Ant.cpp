#include "Ant.h"

Ant::Ant(Vertex* start, Vertex* goal, Graph* graph) {
	this->location = start;
	this->goal = goal;
	this->graph = graph;
	totalTimeTraveled = 1;
	path.push_back(start);
}

void Ant::move(RandomNumberGenerator* rng) {
	int pathChoice;
	rng->getRandomNumber(&pathChoice);
	location = (graph->adjacencyMatrix[location])->at(pathChoice);
	path.push_back(location);
	this->totalTimeTraveled++;
	if (location != goal) {
		move(rng);
	}
}