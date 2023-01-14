#include "Ant.h"

/// <summary>
/// Constructor for Ant, sets initial location, goal, and graph to traverse
/// </summary>
/// <param name="start"></param>
/// <param name="goal"></param>
/// <param name="graph"></param>
/// <param name="seed"></param>
Ant::Ant(Vertex* start, Vertex* goal, Graph* graph, unsigned int seed) {
	this->location = start;
	this->goal = goal;
	this->graph = graph;
	totalTimeTraveled = 1;
	rng = new RandomNumberGenerator(seed);
}

/// <summary>
/// Movement function for an ant making a decision
/// </summary>
void Ant::move() {
	int pathChoice;
	rng->getRandomNumber(&pathChoice);
	location = (graph->adjacencyMatrix[location])->at(pathChoice);
	this->totalTimeTraveled++;
	if (location != goal) {
		move();
	}
}

Ant::~Ant() {
	delete(rng);
}