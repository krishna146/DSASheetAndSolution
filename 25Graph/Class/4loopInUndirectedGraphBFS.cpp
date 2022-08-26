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
    bool isCyclePresent(int src, unordered_map<int, int> &visited)
    {
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto neighbour : adjList[front])
            {
                if (visited[neighbour] && neighbour != parent[front])
                {
                    return true;
                }
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = front;
                }
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
    g->addEdge(3, 4);
    unordered_map<int, int> visited;
    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            if (g->isCyclePresent(i, visited))
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