// Problem Link - https://leetcode.com/problems/is-graph-bipartite/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int V;
    // Approach1: Checking given vertices can be divided on two sets based on edges using bfs
    bool isPartite(vector<bool> &isPresentInSet1, vector<bool> &isPresentInSet2, int src, vector<vector<int>> &adj)
    {
        vector<int> parent(V, -1);
        bool iscurrentSetSt1 = false;
        queue<int> q;
        q.push(src);
        isPresentInSet1[src] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int front = q.front();
                q.pop();
                if (iscurrentSetSt1)
                {
                    for (auto el : adj[front])
                    {
                        if (el != parent[front])
                        {
                            if (isPresentInSet1[el])
                            {
                                return false;
                            }
                            else
                            {
                                if (!isPresentInSet2[el])
                                {
                                    isPresentInSet2[el] = true;
                                    q.push(el);
                                }
                            }
                        }
                    }
                }
                else
                {
                    for (auto el : adj[front])
                    {
                        if (el != parent[front])
                        {
                            parent[el] = front;
                            if (isPresentInSet2[el])
                            {
                                return false;
                            }
                            else
                            {
                                if (!isPresentInSet1[el])
                                {
                                    isPresentInSet1[el] = true;
                                    q.push(el);
                                }
                            }
                        }
                    }
                }
            }
            if (iscurrentSetSt1)
                iscurrentSetSt1 = false;
            else
                iscurrentSetSt1 = true;
        }
        return true;
    }
    // Approach2:  Checking Graph is Two Colorable Or Not
    bool bfsTwoColorable(int src, vector<int> &color, vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int front = q.front();
                q.pop();
                for (auto neigh : adj[front])
                {
                    if (color[neigh] == -1)
                    {
                        color[neigh] = 1 - color[front];
                        q.push(neigh);
                    }
                    else
                    {
                        if (color[neigh] == color[front])
                            return false;
                    }
                }
            }
        }
        return true;
    }
    // Approach 3: dfs + TwoColorable
    bool dfsTwoColorable(int src, vector<int> &color, vector<vector<int>> &adj)
    {
        for (auto neigh : adj[src])
        {
            if (color[neigh] == -1)
            {
                color[neigh] = 1 - color[src];
                if (!dfsTwoColorable(neigh, color, adj))
                    return false;
            }
            else
            {
                if (color[neigh] == color[src])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        V = graph.size();
        // Approach 1: bfs + Checking given vertices can be divided on two sets based on edges using bfs
        //  vector<bool> isPresentInSet1(V, false);
        //  vector<bool> isPresentInSet2(V, false);
        //  for(int i = 0 ; i < V ; i++){
        //     if(isPresentInSet1[i] == false && isPresentInSet2[i] == false){
        //         if(!isPartite(isPresentInSet1, isPresentInSet2, i, graph)) return false;
        //     }
        //  }
        //  return true;

        // Approach2: bfs + using graph is two colorable or not
        //  vector<int> color(V, -1);
        //  for(int i = 0 ; i < V ; i++){
        //      if(color[i] == -1){
        //          if(!bfsTwoColorable(i, color, graph)) return false;
        //      }
        //  }
        //  return true;

        // Approach3: dfs + Two Colorable Property
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!dfsTwoColorable(i, color, graph))
                    return false;
            }
        }
        return true;
    }
};