// Problem Link 1 - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Problem Link 2 - https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Info
{
public:
    int data;
    int row;
    int col;
    Info(int d, int r, int c)
    {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};
class Cmp
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<Info *, vector<Info *>, Cmp> minHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            int el = nums[i][0];
            Info *info = new Info(el, i, 0);
            maxi = max(maxi, el);
            mini = max(mini, el);
            minHeap.push(info);
        }
        int start = maxi;
        int end = mini;
        while (!minHeap.empty())
        {
            Info *temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
            if (temp->col + 1 < nums[temp->row].size())
            {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                Info *toPush = new Info(nums[temp->row][temp->col + 1], temp->row, temp->col + 1);
                minHeap.push(toPush);
            }
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};