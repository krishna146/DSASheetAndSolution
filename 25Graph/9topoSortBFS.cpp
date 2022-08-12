// Problem Link - https://practice.geeksforgeeks.org/problems/topological-sort/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
class Graph
{
public:
    map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }
    void printADj()
    {
        for (auto vertices : adjList)
        {
            cout << vertices.first;
            for (auto adjacent : vertices.second)
            {
                cout << " -> " << adjacent;
            }
            cout << endl;
        }
    }
    void topoSort(int V)
    {
        unordered_map<int, int> indegree;
        queue<int> q;
        for (int i = 1; i <= V; i++)
        {
            indegree[i] = 0;
        }
        for (auto vertices : adjList)
        {
            for (auto neighbour : vertices.second)
            {
                indegree[neighbour]++;
            }
        }
        for (auto v : indegree)
        {
            if (v.second == 0)
            {
                q.push(v.first);
            }
        }
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (auto el : adjList[front])
            {
                indegree[el]--;
                if (indegree[el] == 0)
                {
                    q.push(el);
                }
            }
        }
    }
};
int main()
{
    Graph<int> *g = new Graph<int>();
    unordered_map<int, bool> visited;
    // component c1
    g->addEdge(1, 2, true);
    g->addEdge(1, 3, true);
    g->addEdge(2, 5, true);
    g->addEdge(3, 5, true);
    g->addEdge(5, 4, true);
    g->topoSort(5);
}