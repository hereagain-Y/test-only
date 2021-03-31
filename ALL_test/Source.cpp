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
