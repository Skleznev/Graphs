#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class Graph
{
private:
	vector <vector <int> > graph;
public:
	void readGraph(string fileName) {
		char type[4];
		int N, D, W;

		ifstream in(fileName);

		in >> type >> N >> D >> W;


		if ('C') {
			int weight;
			cout << type;
			for (int i = 0; i < N; i++) {
				graph.push_back(vector<int>());
				for (int j= 0; j < N; j++) {
					graph[graph.size() - 1].push_back(0);
					in >> weight;
					addEdge(i, j, weight);
				}
			}
		}
	}

	void addEdge(int from, int to, int weight) {
		graph[from][to] = weight;
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

