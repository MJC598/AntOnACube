#pragma once
#include "Graph.h"

class Ant {
public:
	Graph* graph;
	std::vector<Vertex*> path;
	int totalTimeTraveled;
	Vertex* location;
	Vertex* goal;

	Ant(Vertex* start, Vertex* goal, Graph* graph) : location(start), goal(goal), graph(graph) {
		totalTimeTraveled = 1; 
		path.push_back(start);
	}

	void move();

};