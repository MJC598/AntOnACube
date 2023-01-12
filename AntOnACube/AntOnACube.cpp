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
		<< "Average: " << sim->getMean() << std::endl
		<< "Standard Deviation: " << sim->getStandardDeviation() << std::endl << std::endl;
}

int menuResult() {
	int choice;
	
	std::cout << "What would you like to do [1-4]:" << std::endl
		<< "1. Run a Simulation" << std::endl
		<< "2. View Past Simulation Results" << std::endl
		<< "3. Clear Past Simulation Results" << std::endl
		<< "4. Exit" << std::endl;
	std::cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		std::cout << "Please make a valid selection: 1, 2, 3, or 4" << std::endl;
		std::cin >> choice;
	}
	return choice;
}

void displayPrevSims(std::vector<Simulation*> simulations) {
	std::cout << "-----------------------------" << std::endl;
	if (simulations.empty()) {
		std::cout << "There are no previous simulations!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		return;
	}
	for (int i = 0; i < simulations.size(); i++) {
		std::cout << "Simulation " << i+1 << std::endl;
		displayResults(simulations[i]);
		std::cout << "-----------------------------" << std::endl;
	}
}


int main()
{
	Graph *cube = new Graph();
	cube = cube->fillCube();
	int numSims = 100;
	int seed = 0;
	std::vector<Simulation*> simulations;
	Simulation* sim;

	int choice = menuResult();

	while (choice != 4) {
		switch (choice) {
		case 1:
			promptUser(&numSims, &seed);
			sim = new Simulation(numSims, cube, seed);
			sim->runSim();
			displayResults(sim);
			simulations.push_back(sim);
			break;
		case 2:
			displayPrevSims(simulations);
			break;
		case 3:
			simulations.clear();
			break;
		default:
			break;
		}
		
		choice = menuResult();
	}
	return 0;
}
