#pragma once
#include <iostream>
#include <vector>
#include <map>

typedef int Vertex;

class Graph {
public:
	std::vector<Vertex*> vertices;
	std::map<Vertex*, std::vector<Vertex*>*> adjacencyMatrix;
	void addVertex(Vertex*);
	void addEdge(Vertex* v1, Vertex* v2);
	Graph* fillCube();
	void printGraph();
};