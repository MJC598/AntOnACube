#include "Graph.h"

/// <summary>
/// Function to add veritices to the graph
/// </summary>
/// <param name="vertex"></param>
void Graph::addVertex(Vertex* vertex) {
	if (adjacencyMatrix.find(vertex) != adjacencyMatrix.end()) {
		std::cout << "\nVertex Already Exists" << std::endl;
		return;
	}
	std::vector<Vertex*>* newVector = new std::vector<Vertex*>();
	adjacencyMatrix[vertex] = newVector;
	return;
}

/// <summary>
/// Function to add edges to the graph
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
void Graph::addEdge(Vertex* v1, Vertex* v2) {
	if (adjacencyMatrix.find(v1) == adjacencyMatrix.end() ||
		adjacencyMatrix.find(v2) == adjacencyMatrix.end()) {
		std::cout << "\nA Specified Vertex Does Not Exist, Edge Not Added!" << std::endl;
		return;
	}
	adjacencyMatrix[v1]->push_back(v2);
	adjacencyMatrix[v2]->push_back(v1);
}

/// <summary>
/// Helper function used to return a cube graph
/// </summary>
/// <returns></returns>
Graph* Graph::fillCube() {
	this->adjacencyMatrix.clear();
	for (int i = 0; i < 8; i++) {
		int* j = new int();
		*j = i + 1;
		this->addVertex(j);
		vertices.push_back(j);
	}

	this->addEdge(vertices[0], vertices[1]);
	this->addEdge(vertices[0], vertices[3]);
	this->addEdge(vertices[0], vertices[4]);

	this->addEdge(vertices[1], vertices[2]);
	this->addEdge(vertices[1], vertices[5]);

	this->addEdge(vertices[2], vertices[3]);
	this->addEdge(vertices[2], vertices[6]);

	this->addEdge(vertices[3], vertices[7]);

	this->addEdge(vertices[4], vertices[5]);
	this->addEdge(vertices[4], vertices[7]);

	this->addEdge(vertices[5], vertices[6]);

	this->addEdge(vertices[6], vertices[7]);

	return this;
}

/// <summary>
/// Helper function to print the graph to terminal
/// </summary>
void Graph::printGraph() {
	for (auto i : this->adjacencyMatrix) {
		std::cout << i.first << i.second << std::endl;

	}
}