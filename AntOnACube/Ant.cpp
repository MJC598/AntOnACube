#include "Ant.h"

Ant::Ant(Vertex* start, Vertex* goal, Graph* graph, unsigned int seed) {
	this->location = start;
	this->goal = goal;
	this->graph = graph;
	totalTimeTraveled = 1;
	rng = new RandomNumberGenerator(seed);
}

void Ant::move() {
	int pathChoice;
	rng->getRandomNumber(&pathChoice);
	location = (graph->adjacencyMatrix[location])->at(pathChoice);
	this->totalTimeTraveled++;
	if (location != goal) {
		move();
	}
}