// Problem Link - https://leetcode.com/problems/russian-doll-envelopes/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++)
        {
            int height = envelopes[i][1];
            if (height > temp.back())
            {
                temp.push_back(height);
            }
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), height);
                *it = height;
            }
        }
        return temp.size();
    }
};