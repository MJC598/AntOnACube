// AntOnACube.cpp : Defines the entry point for the application.

#include "AntOnACube.h"

/// <summary>
/// User Interface Function to prompt for number of simulations
/// </summary>
/// <param name="numSims"></param>
/// <param name="seed"></param>
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

/// <summary>
/// User Interface Function to display the results of a simulation
/// </summary>
/// <param name="sim"></param>
void displayResults(Simulation* sim) {
	std::cout << "Total Sum: " << sim->totalSum << std::endl
		<< "Number Sims: " << sim->numSims << std::endl
		<< "Average: " << sim->getMean() << std::endl
		<< "Standard Deviation: " << sim->getStandardDeviation() << std::endl << std::endl;
}

/// <summary>
/// User Interface Function to provide a basic terminal menu
/// </summary>
/// <returns></returns>
int menuResult() {
	int choice;
	
	std::cout << "What would you like to do [1-5]:" << std::endl
		<< "1. Run a Simulation" << std::endl
		<< "2. View Past Simulation Results" << std::endl
		<< "3. Clear Past Simulation Results" << std::endl
		<< "4. Save A Simulation to a File" << std::endl
		<< "5. Exit" << std::endl;
	std::cin >> choice;
	if (choice != 1 && 
		choice != 2 && 
		choice != 3 && 
		choice != 4 &&
		choice != 5) {
		std::cout << "Please make a valid selection: 1, 2, 3, 4, or 5" << std::endl;
		std::cin >> choice;
	}
	return choice;
}

/// <summary>
/// User Interface Function to display previous sims run
/// </summary>
/// <param name="simulations"></param>
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

/// <summary>
/// User Interface Function to prompt user for a filename to save to
/// </summary>
/// <param name="simChoice"></param>
/// <returns></returns>
std::string getFileNameFromUser(int* simChoice) {
	std::string filename;
	std::cout << "Please Enter a File Name: ";
	std::cin >> filename;
	std::cout << "Please Enter the Simulation Number to Save: ";
	std::cin >> *simChoice;
	return filename;
}

/// <summary>
/// Helper Function used to write a simulation to a file
/// </summary>
/// <param name="filename"></param>
/// <param name="sim"></param>
void writeSimToFile(std::string filename, Simulation* sim) {
	std::ofstream MyFile(filename);
	MyFile << "Mean StdDev" << std::endl;
	MyFile << sim->getMean() << " " << sim->getStandardDeviation() << std::endl;
	MyFile << "Ant Times" << std::endl;
	for (Ant* ant : sim->ants) {
		MyFile << ant->totalTimeTraveled << " ";
	}
	MyFile.close();
	std::cout << "File Written Successfully!" << std::endl;
}

/// <summary>
/// Main Driving Function, entry point for program
/// </summary>
/// <returns></returns>
int main()
{
	Graph *cube = new Graph();
	cube = cube->fillCube();
	int numSims = 100;
	int seed = 0;
	std::vector<Simulation*> simulations;
	Simulation* sim;
	int simChoice = 0;
	std::string filename;

	int choice = menuResult();

	while (choice != 5) {
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
		case 4:
			simChoice = 0;
			filename = getFileNameFromUser(&simChoice);
			if (simulations.size() > (simChoice - 1)) {
				writeSimToFile(filename, simulations[simChoice - 1]);
			}
			break;
		default:
			break;
		}
		
		choice = menuResult();
	}
	return 0;
}
