// AntOnACube.cpp : Defines the entry point for the application.
//

#include "AntOnACube.h"

int main()
{
	Graph *cube = new Graph();
	cube = cube->fillCube();
	Simulation* sim = new Simulation(100, cube, 0);
	sim->runSim();

	std::cout << "Total Sum: " << sim->totalSum << std::endl
		<< "Number Sims: " << sim->numSims << std::endl 
		<< "Average: " << (double)sim->totalSum / (double)sim->numSims << std::endl;
	return 0;
}
