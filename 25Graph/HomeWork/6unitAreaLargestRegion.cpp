// Problem Link - https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        visited[row][col] = true;
        int count = 1;
        if (row + 1 < visited.size())
        {
            if (!visited[row + 1][col] && grid[row + 1][col] == 1)
            {
                count += dfs(row + 1, col, visited, grid);
            }
            if (col + 1 < grid[0].size() && !visited[row + 1][col + 1] && grid[row + 1][col + 1] == 1)
            {
                count += dfs(row + 1, col + 1, visited, grid);
            }
            if (col - 1 >= 0 && !visited[row + 1][col - 1] && grid[row + 1][col - 1] == 1)
            {
                count += dfs(row + 1, col - 1, visited, grid);
            }
        }
        if (row - 1 >= 0)
        {
            if (!visited[row - 1][col] && grid[row - 1][col] == 1)
            {
                count += dfs(row - 1, col, visited, grid);
            }
            if (col + 1 < grid[0].size() && !visited[row - 1][col + 1] && grid[row - 1][col + 1] == 1)
            {
                count += dfs(row - 1, col + 1, visited, grid);
            }
            if (col - 1 >= 0 && !visited[row - 1][col - 1] && grid[row - 1][col - 1] == 1)
            {
                count += dfs(row - 1, col - 1, visited, grid);
            }
        }
        if (col + 1 < visited[0].size() && grid[row][col + 1] == 1 && !visited[row][col + 1])
        {
            count += dfs(row, col + 1, visited, grid);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == 1 && !visited[row][col - 1])
        {
            count += dfs(row, col - 1, visited, grid);
        }
        return count;
    }

public:
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        int area = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (!visited[r][c] && grid[r][c] == 1)
                {
                    area = max(area, dfs(r, c, visited, grid));
                }
            }
        }
        return area;
    }
};