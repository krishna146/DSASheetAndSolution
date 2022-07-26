// Problem Link - https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Data
{
public:
    int data;
    int row;
    int col;
    Data(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(Data a, Data b)
    {
        return a.data > b.data;
    }
};
class Solution
{

public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        // code here
        vector<int> ans;
        priority_queue<Data, vector<Data>, compare> minHeap;
        for (int i = 0; i < k; i++)
        {
            Data temp(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        while (minHeap.size() > 0)
        {
            Data temp = minHeap.top();
            minHeap.pop();
            int row = temp.row;
            int col = temp.col;
            col++;
            ans.push_back(temp.data);
            if (col < k)
            {
                Data temp(arr[row][col], row, col);
                minHeap.push(temp);
            }
        }
        return ans;
    }
};