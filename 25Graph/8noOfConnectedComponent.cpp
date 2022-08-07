// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-provinces/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Using DFS
class Approach1
{
private:
    void dfs(int src, vector<vector<int>> &adj, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (int i = 0; i < adj[src].size(); i++)
        {
            if (adj[src][i] && !visited[i])
            {
                dfs(i, adj, visited);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int ans = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                ans++;
            }
        }
        return ans;
    }
};
//Using DFS
class Solution
{
private:
    void bfs(int src, vector<vector<int>> &adj, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int i = 0; i < adj[front].size(); i++)
            {
                if (adj[front][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int ans = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(i, adj, visited);
                ans++;
            }
        }
        return ans;
    }
};