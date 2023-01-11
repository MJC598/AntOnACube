// AntOnACube.cpp : Defines the entry point for the application.
//

#include "AntOnACube.h"

void promptUser(int* numSims, int* seed) {
	std::cout << "Enter the desired number of simulations (default is 100): ";
	std::cin >> *numSims;
	while (*numSims <= 0) {
		std::cout << "A positive number of simulations is required: ";
		std::cin >> *numSims;
	}
	std::cout << "\nEnter random number seed (default is 0): ";
	std::cin >> *seed;
}

void displayResults(Simulation* sim) {
	std::cout << "Total Sum: " << sim->totalSum << std::endl
		<< "Number Sims: " << sim->numSims << std::endl
		<< "Average: " << (double)sim->totalSum / (double)sim->numSims << std::endl;
}

int main()
{
	Graph *cube = new Graph();
	cube = cube->fillCube();
	int numSims = 100;
	int seed = 0;

	promptUser(&numSims, &seed);
	Simulation* sim = new Simulation(numSims, cube, seed);
	sim->runSim();
	displayResults(sim);
	
	return 0;
}
