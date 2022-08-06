// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Graph
{
private:
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool isCyclePresent(int src, int parent, unordered_map<int, int> &visited)
    {
        visited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                bool cycleDetectd =  isCyclePresent(neighbour, src, visited);
                if(cycleDetectd) return true;
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph *g = new Graph();
    g->addEdge(0, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 4);
    g->addEdge(2, 3);
    // g->addEdge(3, 4);
    unordered_map<int, int> visited;
    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            if (g->isCyclePresent(i, -1 , visited))
            {
                cout << "loop found";
                break;
            }
            else
            {
                cout << "no loop found ";
            }
        }
    }
}