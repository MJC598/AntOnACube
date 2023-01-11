#include "Ant.h"

void Ant::move() {
	//random choice gets vertex
	int pathChoice = rand() % 3;
	location = (graph->adjacencyMatrix[location])->at(pathChoice);
	path.push_back(location);
	this->totalTimeTraveled++;
	if (location != goal) {
		move();
	}
}