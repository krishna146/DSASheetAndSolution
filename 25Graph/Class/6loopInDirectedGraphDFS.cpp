// Problem Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
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
    }
    bool isCyclePresent(int src,unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                bool isCycle = isCyclePresent(src, visited, dfsVisited);
                if(isCycle) return true;
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[src] = false;
        return false;
    }
};
int main()
{
    Graph *g = new Graph();
    g -> addEdge(1, 2);;
    g -> addEdge(2, 3);
    g -> addEdge(2, 4);
    g -> addEdge(3, 7);
    g -> addEdge(3, 8);
    g -> addEdge(4, 5);
    g -> addEdge(5, 6);
    g -> addEdge(6, 4);
    g -> addEdge(8, 7);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < 9; i++)
    {
        if (!visited[i])
        {
            if (g->isCyclePresent(i, visited, dfsVisited))
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