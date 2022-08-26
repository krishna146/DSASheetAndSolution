// Problem Link - https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class graph
{
private:
    unordered_map<int, list<pair<int, int>>> adjList;

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
        vector<int> distTo(n + 1, INT_MAX);
        distTo[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto vertex : adjList)
            {
                for (auto neighbour : vertex.second)
                {
                    if (distTo[vertex.first] != INT_MAX && distTo[vertex.first] + neighbour.second < distTo[neighbour.first])
                    {
                        distTo[neighbour.first] = distTo[vertex.first] + neighbour.second;
                    }
                }
            }
        }
        for (auto vertex : adjList)
        {
            for (auto neighbour : vertex.second)
            {
                if (distTo[vertex.first] != INT_MAX && distTo[vertex.first] + neighbour.second < distTo[neighbour.first])
                {
                    distTo[neighbour.first] = distTo[vertex.first] + neighbour.second;
                    cout << "Graph contain negative weight cycle and calculated distance is wrong " << endl;
                    break;
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
