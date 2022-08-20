// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class graph
{
private:
    unordered_map<int, list<pair<int, int>>> adjList;
    void findTopoSortSequence(int src, vector<int> &topoSequence, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            int vertex = neighbour.first;
            if (!visited[vertex])
            {
                findTopoSortSequence(vertex, topoSequence, visited);
            }
        }
        topoSequence.push_back(src);
    }

public:
    void addEdge(int u, int v, int wt)
    {
        adjList[u].push_back({v, wt});
    }
    void printAdj()
    {
        for (auto vertex : adjList)
        {
            cout << vertex.first;
            for (auto neighbour : vertex.second)
            {
                cout << " -> "
                     << "[" << neighbour.first << ", " << neighbour.second << "]";
            }
            cout << endl;
        }
    }
    vector<int> findShortestPath(int src, int n)
    {
        // step1: find Topo Sort Sequence;
        unordered_map<int, bool> visited;
        vector<int> topoSequence;
        vector<int> distTo(n + 1, INT_MAX);
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i])
            {
                findTopoSortSequence(i, topoSequence, visited);
            }
        }
        reverse(topoSequence.begin(), topoSequence.end());
        distTo[src] = 0;
        for (auto vertex : topoSequence)
        {
            for (auto neighbour : adjList[vertex])
            {
                if (distTo[vertex] != INT_MAX && distTo[vertex] + neighbour.second < distTo[neighbour.first])
                {
                    distTo[neighbour.first] = distTo[vertex] + neighbour.second;
                }
            }
        }
        return distTo;
    }
};
int main()
{
    graph *g = new graph();
    g->addEdge(0, 1, 5);
    g->addEdge(0, 2, 3);
    g->addEdge(1, 2, 2);
    g->addEdge(1, 3, 6);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 4, 4);
    g->addEdge(2, 5, 2);
    g->addEdge(3, 4, -1);
    g->addEdge(4, 5, -2);
    g->printAdj();
    vector<int> toDist = g->findShortestPath(1, 5);
    for (auto dist : toDist)
    {
        cout << dist << " ";
    }
}