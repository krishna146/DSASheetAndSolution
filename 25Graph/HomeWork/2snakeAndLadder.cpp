// Problem Link - https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1
// Problem Link - https://leetcode.com/problems/snakes-and-ladders/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minThrow(int N, int arr[])
    {
        // code here
        int move = 0;
        queue<int> q;
        vector<bool> visited(31, false);
        unordered_map<int, int> ump;
        for (int i = 0; i <= 2 * N - 2; i = i + 2)
        {
            ump[arr[i]] = arr[i + 1];
        }
        visited[1] = true;
        q.push(1);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int src = q.front();
                q.pop();
                for (int result = 1; result <= 6; result++)
                {
                    int dest = src + result;
                    if (visited[dest])
                        continue;
                    visited[dest] = true;
                    if (dest < 30)
                    {
                        if (ump.find(dest) != ump.end())
                        {
                            dest = ump[dest];
                        }
                        q.push(dest);
                    }
                    if (dest == 30)
                    {
                        return move + 1;
                    }
                }
            }
            move++;
        }
        return -1;
    }
};