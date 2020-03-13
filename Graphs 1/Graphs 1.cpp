#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

class Graph
{
public:
	char type[50];
	int N, D, W, M, temp;
	vector<vector<int>> adjMatrix;
	vector<tuple<int, int, int>> listOfEdges;
	vector<vector<int>> adjacentList;
	vector<vector<pair<int, int>>> adjacentListW;

	void readGraph(string fileName) {
		ifstream in(fileName);
		in >> type;
		
		switch (*type)
		{
		case 'C':
			in >> N >> D >> W;
			for (int i = 0; i < N; i++) {
				adjMatrix.push_back(vector<int>());
				for (int j = 0; j < N; j++) {
					in >> temp;
					adjMatrix[i].push_back(temp);
				}
			}
			break;
		case'E':
			in >> N >> M >> D >> W;
			for (int i = 0; i < M; i++) {
				int from, to, weight;
				in >> from >> to;
				if (W == 0) weight = 1;
				else in >> weight;

				listOfEdges.push_back(make_tuple(from, to, weight));
			}
			break;
		case'L':
			in >> N >> D >> W;

			if (W == 0) {
				for (int i = 0; i < N; i++) {
					adjacentList.push_back(vector<int>());
					string line;

					while (getline(in, line)) {
						if (line.empty()) continue;
						istringstream iss(line);
						string num;

						while (getline(iss, num, ' ')) {
							adjacentList[i].push_back(stoi(num));
						}

						break;
					}
				}
			}
			else {
				for (int i = 0; i < N; i++) {
					adjacentListW.push_back(vector<pair<int, int>>());
					string line;

					while (getline(in, line)) {
						if (line.empty()) continue;
						istringstream iss(line);
						string num;

						while (getline(iss, num, ' ')) {
							adjacentList[i].push_back(stoi(num));
						}

						break;
					}
				}
			}
			break;
		default:
			break;
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
		if (adjMatrix.empty()) {
			for (int i = 0; i < N; i++) {
				adjMatrix.push_back(vector<int>());
				for (int j = 0; j < N; j++) {
					adjMatrix[i].push_back(0);
				}
			}
		}

		
		switch (*type)
		{
		case'E':
			for (int i = 0; i < M; i++) {
				adjMatrix[get<0>(listOfEdges[i]) - 1][get<1>(listOfEdges[i]) - 1] = get<2>(listOfEdges[i]);

				if (D == 0) {
					adjMatrix[get<1>(listOfEdges[i]) - 1][get<0>(listOfEdges[i]) - 1] = get<2>(listOfEdges[i]);
				}
			}
			break;
		case'L':
			break;
		default:
			break;
		}
		*type = 'C';
	}

	void transformToListOfEdges() {
		if (!listOfEdges.empty()) {
			listOfEdges = vector < tuple<int, int, int>>();
			M = 0;
		}
		switch (*type)
		{
		case'C':
			if (D == 0) {
				for (int i = 0; i < N; i++) {
					for (int j = i; j < N; j++) {
						if (adjMatrix[i][j] != 0) {
							listOfEdges.push_back(make_tuple(i + 1, j + 1, adjMatrix[i][j]));
							M++;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (adjMatrix[i][j] != 0) {
							listOfEdges.push_back(make_tuple(i + 1, j + 1, adjMatrix[i][j]));
							M++;
						}
					}
				}
			}


			break;
		case'L':
			break;
		default:
			break;
		}
		*type = 'E';
	}

	void writeGraph(string fileName) {
		ofstream fout;
		fout.open(fileName);

		switch (*type)
		{
		case'C':
			fout << type << " " << N << "\n" << D << " " << W;

			for (int i = 0; i < N; i++) {
				fout << "\n";
				for (int j = 0; j < N; j++) {
					fout << adjMatrix[i][j];
					if (j != N - 1)
						fout << " ";
				}
			}

			break;
		case'E':
			fout << type << " " << N << " " << M << "\n" << D << " " << W;


			for (int i = 0; i < M; i++) {
				fout << "\n";

				fout << get<0>(listOfEdges[i]) << " " << get<1>(listOfEdges[i]);
				if (W == 1) fout << " " << get<2>(listOfEdges[i]);
			}

			break;
		case'L':
			fout << type << " " << N << " " << "\n" << D << " " << W;

			if (W == 0) {
				for (int i = 0; i < N; i++) {
					fout << "\n";

				}
			}
			else {

			}
			break;
		default:
			break;
		}


		
		fout << "\n";
		fout.close();
	}
};


int main()
{
	Graph graph{};

	graph.readGraph("input.txt");
	graph.transformToAdjMatrix();
	graph.transformToListOfEdges();
	graph.writeGraph("output.txt");

}

