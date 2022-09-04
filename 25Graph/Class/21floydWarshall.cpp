// Problem Link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code her
        int v = matrix.size();
        for (int k = 0; k < v; k++)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (matrix[i][k] != -1 && matrix[k][j] != -1)
                    {
                        if (matrix[i][j] != -1)
                            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                        else
                        {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                }
            }
        }
    }
};