// Problem Link - https://leetcode.com/problems/number-of-islands/F
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    void bfs(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> q;
        int rowCount = grid.size();
        int colCount = grid[0].size();
        visited[row][col] = true;
        q.push({row, col});
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            if (row + 1 < rowCount && grid[row + 1][col] == '1' && !visited[row + 1][col])
            {
                visited[row + 1][col] = true;
                q.push({row + 1, col});
            }
            if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col])
            {
                visited[row - 1][col] = true;
                q.push({row - 1, col});
            }
            if (col + 1 < colCount && grid[row][col + 1] == '1' && !visited[row][col + 1])
            {
                visited[row][col + 1] = true;
                q.push({row, col + 1});
                
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1])
            {
                visited[row][col - 1] = true;
                q.push({row, col - 1});
            }
        }
    }
    void dfs(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> q;
        int rowCount = grid.size();
        int colCount = grid[0].size();
        visited[row][col] = true;
        if (row + 1 < rowCount && grid[row + 1][col] == '1' && !visited[row + 1][col])
        {
            dfs(grid, row + 1, col, visited);
        }
        if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col])
        {
            dfs(grid, row - 1, col, visited);
        }
        if (col + 1 < colCount && grid[row][col + 1] == '1' && !visited[row][col + 1])
        {
            dfs(grid, row, col + 1, visited);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1])
        {
            dfs(grid, row, col - 1, visited);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int rowCount = grid.size();
        int colCount = grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int row = 0; row < rowCount; row++)
        {
            for (int col = 0; col < colCount; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(grid, row, col, visited);
                }
            }
        }
        return count;
    }
};
