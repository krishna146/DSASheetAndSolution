// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-provinces/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
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