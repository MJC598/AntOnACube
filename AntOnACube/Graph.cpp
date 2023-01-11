#include "Graph.h"

void Graph::addVertex(Vertex* vertex) {
	if (adjacencyMatrix.find(vertex) != adjacencyMatrix.end()) {
		std::cout << "\nVertex Already Exists" << std::endl;
		return;
	}
	std::vector<Vertex*>* newVector = new std::vector<Vertex*>();
	adjacencyMatrix[vertex] = newVector;
	return;
}

void Graph::addEdge(Vertex* v1, Vertex* v2) {
	if (adjacencyMatrix.find(v1) == adjacencyMatrix.end() ||
		adjacencyMatrix.find(v2) == adjacencyMatrix.end()) {
		std::cout << "\nA Specified Vertex Does Not Exist, Edge Not Added!" << std::endl;
		return;
	}
	adjacencyMatrix[v1]->push_back(v2);
	adjacencyMatrix[v2]->push_back(v1);
}

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

	//this->addEdge(vertices[1], vertices[0]);
	this->addEdge(vertices[1], vertices[2]);
	this->addEdge(vertices[1], vertices[5]);

	//this->addEdge(vertices[2], vertices[1]);
	this->addEdge(vertices[2], vertices[3]);
	this->addEdge(vertices[2], vertices[6]);

	//this->addEdge(vertices[3], vertices[0]);
	//this->addEdge(vertices[3], vertices[2]);
	this->addEdge(vertices[3], vertices[7]);

	//this->addEdge(vertices[4], vertices[0]);
	this->addEdge(vertices[4], vertices[5]);
	this->addEdge(vertices[4], vertices[7]);

	//this->addEdge(vertices[5], vertices[1]);
	//this->addEdge(vertices[5], vertices[4]);
	this->addEdge(vertices[5], vertices[6]);

	//this->addEdge(vertices[6], vertices[2]);
	//this->addEdge(vertices[6], vertices[5]);
	this->addEdge(vertices[6], vertices[7]);

	//this->addEdge(vertices[7], vertices[3]);
	//this->addEdge(vertices[7], vertices[4]);
	//this->addEdge(vertices[7], vertices[6]);

	return this;
}

void Graph::printGraph() {
	for (auto i : this->adjacencyMatrix) {
		std::cout << i.first << i.second << std::endl;

	}
}