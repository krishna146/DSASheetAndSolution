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
    bool isCyclePresent(int V)
    {
        unordered_map<int, int> indegree;
        queue<int> q;
        for(auto el: adjList){
            indegree[el.first] = 0;
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
        for(auto el: indegree){
            if(el.second != 0) return false;
        }
        return true;
    }
};
int main()
{

    Graph<int> *g = new Graph<int>();
    g->addEdge(1, 2, true);
    g->addEdge(2, 3, true);
    g->addEdge(2, 4, true);
    g->addEdge(3, 7, true);
    g->addEdge(3, 8, true);
    g->addEdge(4, 5, true);
    g->addEdge(5, 6, true);
    g->addEdge(6, 4, true);
    g->addEdge(8, 7, true);
    unordered_map<int, int> indegree;
    if (g->isCyclePresent(8))
    {
        cout << "loop found";
    }
    else
    {
        cout << "no loop found ";
    }
}