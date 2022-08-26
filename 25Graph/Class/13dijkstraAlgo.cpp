// Problem Link -https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
class Graph
{
public:
    map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v, int weight, bool direction)
    {
        adjList[u].push_back({v, weight});
        if (!direction)
        {
            adjList[v].push_back({u, weight});
        }
    }
    void printADj()
    {
        for (auto vertices : adjList)
        {
            cout << vertices.first;
            for (auto adjacent : vertices.second)
            {
                cout << " -> "
                     << "[" << adjacent.first << ", " << adjacent.second << "]";
            }
            cout << endl;
        }
    }
    // Using Set Data Structure TC = O((V + E)logv) SC = O(V)
    vector<int> dijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src});
        while (!st.empty())
        {
            auto top = *st.begin();
            st.erase(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            for (pair<int, int> neighbour : adjList[node])
            {
                if (nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    // find old recordd
                    auto record = st.find({dist[neighbour.first], neighbour.first});
                    /// if record is found , ersase it
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    // push new record
                    st.insert({dist[neighbour.first], neighbour.first});
                }
            }
        }
        return dist;
    }
    //Using Heap Data Structure TC = O((V + E)LogV) SC = O(V)
    vector<int> dijkstraUsingHeap(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        dist[src] = 0;
        minHeap.push({0, src});
        while (!minHeap.empty())
        {

            int vertex = minHeap.top().second;
            int distToVertex = minHeap.top().first;
            minHeap.pop();
            for (pair<int, int> neighbour : adjList[vertex])
            {
                if (distToVertex + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = distToVertex + neighbour.second;
                    minHeap.push({dist[neighbour.first], neighbour.first});
                }
            }
        }
        return dist;
    }
};
int main()
{
    Graph<int> *g = new Graph<int>();
    g->addEdge(0, 1, 5, false);
    g->addEdge(0, 2, 8, false);
    g->addEdge(1, 3, 2, false);
    g->addEdge(1, 2, 9, false);
    g->addEdge(2, 3, 6, false);
    cout << "printing adjaceny list : " << endl;
    g->printADj();
    vector<int> distance = g->dijkstra(0, 4);
    for (auto dist : distance)
    {
        cout << dist << " ";
    }cout << endl;
    vector<int> ans = g -> dijkstraUsingHeap(0, 4);
    for(auto dist: ans){
        cout << dist << " ";
    }
}