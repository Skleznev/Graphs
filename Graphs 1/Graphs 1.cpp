#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Graph
{
public:
	void readGraph(string fileName) {
		char type[50];
		int N, D, W;

		ifstream in(fileName);

		in >> type >> N >> D >> W;


		if ('C') {
			cout << type;

		}

	}

	void addEdge(int from, int to, int weight) {

	}

	void removeEdge(int from, int to) {

	}

	int changeEdge(int from, int to, int newWeight) {

	}

	void transformToAdjList() {

	}

	void transformToAdjMatrix() {

	}

	void transformToListOfEdges() {

	}

	void writeGraph(string fileName) {

	}
};


int main()
{
	Graph graph{};

	graph.readGraph("input.txt");
}

