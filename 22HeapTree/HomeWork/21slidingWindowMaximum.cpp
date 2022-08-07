// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Approach1 : using maxHeap TC = O(NLogN) SC = O(N)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            maxHeap.push({nums[i], i});
        }
        ans.push_back(maxHeap.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            while (!maxHeap.empty() && maxHeap.top().second <= i - k)
            {
                maxHeap.pop();
            }
            maxHeap.push({nums[i], i});
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};
// Approach2 : Using Dequeue TC = O(N) SC = O(K)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            if (!dq.empty() && (i - dq.front()) == k)
                dq.pop_front();
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};