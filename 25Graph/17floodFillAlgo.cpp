// Problem Link - https://leetcode.com/problems/flood-fill/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rowCount = image.size();
        int colCount = image[0].size();
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        int startPixel = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        visited[sr][sc] = true;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            if (row + 1 < rowCount && image[row + 1][col] == startPixel && !visited[row + 1][col])
            {
                image[row + 1][col] = color;
                visited[row + 1][col] = true;
                q.push({row + 1, col});
            }
            if (row - 1 >= 0 && image[row - 1][col] == startPixel && !visited[row - 1][col])
            {
                image[row - 1][col] = color;
                visited[row - 1][col] = true;
                q.push({row - 1, col});
            }
            if (col + 1 < colCount && image[row][col + 1] == startPixel && !visited[row][col + 1])
            {
                image[row][col + 1] = color;
                visited[row][col + 1] = true;
                q.push({row, col + 1});
            }
            if (col - 1 >= 0 && image[row][col - 1] == startPixel && !visited[row][col - 1])
            {
                image[row][col - 1] = color;
                visited[row][col - 1] = true;
                q.push({row, col - 1});
            }
        }
        return image;
    }
};