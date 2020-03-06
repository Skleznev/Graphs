#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class Graph
{
private:
	vector <vector <int> > graph;
	std::string type;
	int N, D, W;
public:
	void readGraph(string fileName) {
		

		ifstream in(fileName);

		in >> type >> N >> D >> W;


		if (type.compare("'C'")==0) {
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
		ofstream fout;
		fout.open(fileName);
		if (type.compare("'C'") == 0) {
			
			fout << type <<" " << N << "\n" << D << " " << W;

			for (int i = 0; i < N; i++) {
				fout << "\n";
				for (int j = 0; j < N; j++) {
					fout << graph[i][j];
					if(j!=N-1)
					fout << " ";
				}
			}
			
			
		}
		fout.close();
	}
};


int main()
{
	Graph graph{};

	graph.readGraph("input.txt");
	graph.writeGraph("output.txt");
}

