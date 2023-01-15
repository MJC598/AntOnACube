#pragma once
#include "Graph.h"
#include "RandomNumberGenerator.h"

class Ant {
public:
	Graph* graph;
	int totalTimeTraveled;
	Vertex* location;
	Vertex* goal;
	RandomNumberGenerator* rng;

	Ant(Vertex* start, Vertex* goal, Graph* graph, unsigned int seed);
	~Ant();
	void move();
};