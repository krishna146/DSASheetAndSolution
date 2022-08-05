// Problem Link - https://leetcode.com/problems/remove-stones-to-minimize-the-total/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> maxHeap;
        int stonesCount = 0;
        for (auto pile : piles)
        {
            maxHeap.push(pile);
        }
        while (k--)
        {
            int top = maxHeap.top();
            maxHeap.pop();
            top = ceil(top / 2.0);
            maxHeap.push(top);
        }
        while (!maxHeap.empty())
        {
            stonesCount += maxHeap.top();
            maxHeap.pop();
        }
        return stonesCount;
    }
};