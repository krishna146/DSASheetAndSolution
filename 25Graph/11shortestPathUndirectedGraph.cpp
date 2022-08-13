// Problem Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1F
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }
    vector<int> findShortestPath(int source, int destination)
    {
        vector<int> path;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[source] = true;
        parent[source] = -1;
        q.push(source);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto neighbours : adjList[front])
            {
                if (!visited[neighbours])
                {
                    parent[neighbours] = front;
                    visited[neighbours] = true;
                    q.push(neighbours);
                }
            }
        }
        while (destination != source)
        {
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        return path;
    }
};
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    Graph *g = new Graph();
    for (auto edge : edges)
    {
        g->addEdge(edge.first, edge.second, false);
    }
    return g->findShortestPath(s, t);
}