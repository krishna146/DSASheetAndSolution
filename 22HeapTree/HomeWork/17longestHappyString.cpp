// Problem Link - https://leetcode.com/problems/longest-happy-string/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        priority_queue<pair<int, char>> maxHeap;
        if (a != 0)
            maxHeap.push({a, 'a'});
        if (b != 0)
            maxHeap.push({b, 'b'});
        if (c != 0)
            maxHeap.push({c, 'c'});
        pair<int, char> block = {0, '$'};
        while (!maxHeap.empty())
        {
            pair<int, char> curr = maxHeap.top();
            maxHeap.pop();
            // if Curr char having more occurence than previous one i.e block then we need to finish it quickly so -2
            if (curr.first >= 2 && curr.first >= block.first)
            {
                ans.push_back(curr.second);
                ans.push_back(curr.second);
                curr.first -= 2;
            }
            // if curr char having less occurence having previous one i.e blocked character then we need to save it so - 1
            else
            {
                ans.push_back(curr.second);
                curr.first -= 1;
            }
            if (block.first > 0)
            {
                maxHeap.push(block);
            }
            block = curr;
        }
        return ans;
    }
};