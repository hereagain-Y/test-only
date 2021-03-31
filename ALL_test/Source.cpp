//struct Edge {
//	int src, dest, weight;
//	Edge(int _src, int _dest, int _weight) { src = _src; dest = _dest; weight = _weight; }
//};
//
//struct Node {
//    int vertex, weight;
//};
//
//class Graph {
//public:
//	int numVertices;
//	vector<vector<pair<int, int>>> adjList;
//	// e.g. 0: {1, 12}, {2, 4} -> the weight from vertex 0 to 1 is 12 
//	//                        and the weight from vertex 0 to 2 is 4
//
//	Graph(const vector<Edge>& edges, int vertices) {
//		numVertices = vertices;
//
//		adjList.resize(vertices);
//
//		for (auto& edge : edges) {
//			adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));
//		}
//	}
//};
//
//int minDistance(int dist[], bool sptSet[])
//{
//    // Initialize min value
//    int min = INT_MAX, min_index;
//
//    for (int v = 0; v < 7; v++)
//        if (sptSet[v] == false && dist[v] <= min)
//            min = dist[v], min_index = v;
//
//    return min_index;
//}
//
//// A utility function to print the constructed distance array
//int printSolution(int dist[], int n)
//{
//    printf("Vertex   Distance from Source\n");
//    for (int i = 0; i < 7; i++)
//        printf("%d tt %d\n", i, dist[i]);
//    return 0;
//}
//
//struct comp
//{
//    bool operator()(const Node& lhs, const Node& rhs) const {
//        return lhs.weight > rhs.weight;
//    }
//};
//
//bool ifAdj(const Graph& graph,int from,int to) {
//    for (int i = 0; i < graph.adjList.at(from).size(); i++) {
//        if (graph.adjList.at(from).at(i).first == to)
//            return true;
//    }
//    return false;
//}
//int getDis(const Graph& graph, int from, int to) {
//	for (int i = 0; i < graph.adjList[from].size(); i++) {
//		if(graph.adjList[from][i].first==to)
//			return graph.adjList.at(from).at(i).second;
//	}
//    return INT_MAX;
//}
//int findMin(set<int> my_set)
//{
//
//	int min_element;
//	if (!my_set.empty())
//		min_element = *my_set.begin();
//
//	return min_element;
//}
//
//vector<int> dijkstra(const Graph& graph, int src) {
//    // your code
//    vector<int> result;
//    set<int> s, vs;
//	const int size = 7;
//	int d[size], p[size];
//	d[src] = 0;
//	p[src] = src;
//	s.insert(src);
//	for (int i = 0; i < graph.numVertices; i++) {
//		if (i != src) {
//			vs.insert(i);
//		}
//	}
//	for (auto it : vs) {
//		p[it] = src;
//		if (ifAdj(graph, src, it))
//			d[it] = getDis(graph, src, it);
//		else
//			d[it] = INT_MAX;
//	}
//	while (!vs.empty()) {
//		auto temp = vs.begin();
//		int u = *temp;
//		for (auto it : vs) {
//			if (d[it] < d[u]) {
//				u = it;
//			}
//		}
//		vs.erase(u);
//		s.insert(u);
//		for (auto it : vs) {
//			if (ifAdj(graph, u, it)) {
//				if (d[u] + getDis(graph, u, it) < d[it]) {
//					d[it] = d[u] + getDis(graph, u, it);
//					p[it] = u;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < 7; i++) {
//		cout << "d[" << i << "] value is: " << d[i] << " "
//			<< "p[" << i << "] value is: " << p[i] << endl;
//	}
//    result.push_back(2);
//    return result;
//}

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
using namespace std;


class Graph
{
private:
    // Graph data structure here 
    set<int> v;
    map<int, vector<pair<int, int>>> adjList;
public:
    void insertEdge(int from, int to, int weight);
    int getWeight(int from, int to);
    vector<int> getAdjacent(int vertex);
    void printSums();
};
void Graph::insertEdge(int from, int to, int weight) {
    v.insert(from);
    v.insert(to);
    pair<int, int> temp;
    temp.first = to;
    temp.second = weight;
    adjList[from].push_back(temp);
    adjList[to].push_back(temp);
}

int Graph::getWeight(int from,int to) {
    for (int i = 0; i < adjList[from].size(); i++) {
        if (adjList[from][i].first == to)
            return adjList[from][i].second;
    }
    return -1;
}

vector<int> Graph::getAdjacent(int vertex) {
    vector<int> temp;
    for (int i = 0; i < adjList[vertex].size(); i++) {
        temp.push_back(adjList[vertex][i].first);
    }
    return temp;
}

void Graph::printSums() {
    for (auto it : v) {
        int sum = 0;
        for (int i = 0; i < adjList[it].size(); i++) {
            sum += adjList[it][i].second;
        }
        cout << it <<" "<<sum<< endl;
    }
}

int main()
{
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK

    int noOfLines, operation, vertex, to, fro, weight, source, j;
    vector<int> arr;
    int arrSize;
    Graph g;
    g.insertEdge(1, 2, 3);
    g.insertEdge(2, 3, 7);
    g.insertEdge(2, 4, 5);
    g.insertEdge(3, 4, 15);
    g.insertEdge(4, 1, 4);
    g.printSums();
    /*cin >> noOfLines;
    for (int i = 0; i < noOfLines; i++)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            cin >> fro;
            cin >> to;
            cin >> weight;
            g.insertEdge(fro, to, weight);
            break;
        case 2:
            cin >> fro;
            cin >> to;
            cout << g.getWeight(fro, to) << "\n";
            break;
        case 3:
            cin >> vertex;
            arr = g.getAdjacent(vertex);
            arrSize = arr.size();
            j = 0;
            while (j < arrSize)
            {
                cout << arr[j] << " ";
                j++;
            }
            cout << "\n";
            break;
        case 4:
            g.printSums();
            cout << "\n";
            break;
        }
    }*/
}