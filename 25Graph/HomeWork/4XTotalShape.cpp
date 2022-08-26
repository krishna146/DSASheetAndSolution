// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = true;
        if (row + 1 < visited.size() && grid[row + 1][col] == 'X' && !visited[row + 1][col])
        {
            dfs(row + 1, col, visited, grid);
        }
        if (row - 1 >= 0 && grid[row - 1][col] == 'X' && !visited[row - 1][col])
        {
            dfs(row - 1, col, visited, grid);
        }
        if (col + 1 < visited[0].size() && grid[row][col + 1] == 'X' && !visited[row][col + 1])
        {
            dfs(row, col + 1, visited, grid);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == 'X' && !visited[row][col - 1])
        {
            dfs(row, col - 1, visited, grid);
        }
    }
    void bfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row + 1 < visited.size() && grid[row + 1][col] == 'X' && !visited[row + 1][col])
            {
                visited[row + 1][col] = true;
                q.push({row + 1, col});
            }
            if (row - 1 >= 0 && grid[row - 1][col] == 'X' && !visited[row - 1][col])
            {
                visited[row - 1][col] = true;
                q.push({row - 1, col});
            }
            if (col + 1 < visited[0].size() && grid[row][col + 1] == 'X' && !visited[row][col + 1])
            {
                visited[row][col + 1] = true;
                q.push({row, col + 1});
            }
            if (col - 1 >= 0 && grid[row][col - 1] == 'X' && !visited[row][col - 1])
            {
                visited[row][col - 1] = true;
                q.push({row, col - 1});
            }
        }
    }

public:
    // Function to find the number of 'X' total shapes.
    int count = 0;
    int xShape(vector<vector<char>> &grid)
    {
        // Code here
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (!visited[r][c] && grid[r][c] == 'X')
                {
                    count++;
                    bfs(r, c, visited, grid);
                }
            }
        }
        return count;
    }
};