// Problem Link - https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        int dir[8][2] = {{2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
        int step = 0;
        q.push({KnightPos[0], KnightPos[1]});
        visited[KnightPos[0]][KnightPos[1]] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int X = q.front().first;
                int Y = q.front().second;
                q.pop();
                if (X == TargetPos[0] && Y == TargetPos[1])
                    return step;
                for (int i = 0; i < 8; i++)
                {
                    int x = X + dir[i][0];
                    int y = Y + dir[i][1];
                    if (x >= 1 && x <= N && y >= 1 && y <= N && !visited[x][y])
                    {
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};