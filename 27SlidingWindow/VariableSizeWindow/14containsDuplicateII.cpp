// Problem Link - https://leetcode.com/problems/contains-duplicate-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, bool> ump;
        int left = 0;
        int right = 0;

        
        for (int right = 0; right < nums.size();)
        {
            if (right - left > k)
            {
                ump[nums[left++]] = false;
            }
            else
            {
                if (ump[nums[right]])
                {
                    return true;
                }
                ump[nums[right++]] = true;
            }
        }
        return false;
    }
};