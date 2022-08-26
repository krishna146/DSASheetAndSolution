// Problem Link - https://leetcode.com/problems/rotting-oranges/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int time = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        pair<int, int> marker = {15, 0};
        q.push(marker);
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front == marker)
            {
                if (!q.empty())
                {
                    time++;
                    q.push(marker);
                }
            }
            else
            {
                if (front.first + 1 < rowCount && grid[front.first + 1][front.second] == 1)
                {
                    grid[front.first + 1][front.second] = 2;
                    q.push({front.first + 1, front.second});
                }
                if (front.first - 1 >= 0 && grid[front.first - 1][front.second] == 1)
                {
                    grid[front.first - 1][front.second] = 2;
                    q.push({front.first - 1, front.second});
                }
                if (front.second + 1 < colCount && grid[front.first][front.second + 1] == 1)
                {
                    grid[front.first][front.second + 1] = 2;
                    q.push({front.first, front.second + 1});
                }
                if (front.second - 1 >= 0 && grid[front.first][front.second - 1] == 1)
                {
                    grid[front.first][front.second - 1] = 2;
                    q.push({front.first, front.second - 1});
                }
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};