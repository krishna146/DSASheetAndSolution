// Problem Link - https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int row = grid.size();
        priority_queue<int> pq;
        int col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int length = 1;
                pq.push(grid[i][j]);
                while (true)
                {
                    bool flag = false;
                    int temp = length;
                    int tempRow = i;
                    int tempCol = j;
                    int tempSum = 0;
                    for (int l = 1; l <= temp; l++)
                    {
                        if (tempRow + 1 < row)
                        {
                            tempRow++;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        if (tempCol - 1 >= 0)
                        {
                            tempCol--;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        tempSum += grid[tempRow][tempCol];
                    }
                    if (flag)
                        break;
                    for (int l = 1; l <= temp; l++)
                    {
                        if (tempRow + 1 < row)
                        {
                            tempRow++;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        if (tempCol + 1 < col)
                        {
                            tempCol++;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        tempSum += grid[tempRow][tempCol];
                    }
                    if (flag)
                        break;
                    for (int l = 1; l <= temp; l++)
                    {
                        if (tempRow - 1 >= 0)
                        {
                            tempRow--;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        if (tempCol + 1 < col)
                        {
                            tempCol++;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        tempSum += grid[tempRow][tempCol];
                    }
                    if (flag)
                        break;
                    for (int l = 1; l <= temp; l++)
                    {
                        if (tempRow - 1 >= 0)
                        {
                            tempRow--;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        if (tempCol - 1 >= 0)
                        {
                            tempCol--;
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                        tempSum += grid[tempRow][tempCol];
                    }
                    if (flag)
                        break;
                    pq.push(tempSum);
                    length++;
                }
            }
        }
        vector<int> ans;
        int prev = -1;
        int count = 0;
        while (count != 3 && !pq.empty())
        {
            if (pq.top() != prev)
            {
                prev = pq.top();
                ans.push_back(pq.top());
                count++;
            }
            pq.pop();
        }
        return ans;
    }
};