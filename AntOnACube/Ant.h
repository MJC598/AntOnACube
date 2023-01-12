#pragma once
#include "Graph.h"
#include "RandomNumberGenerator.h"

class Ant {
public:
	Graph* graph;
	std::vector<Vertex*> path;
	int totalTimeTraveled;
	Vertex* location;
	Vertex* goal;

	Ant(Vertex* start, Vertex* goal, Graph* graph);
	void move(RandomNumberGenerator* rng);
};