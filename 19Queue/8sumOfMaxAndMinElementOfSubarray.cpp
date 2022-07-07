// Problem Link - https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    // Write your code here.
    deque<int> maxi;
    deque<int> mini;
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && nums[i] >= nums[maxi.back()])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && nums[i] <= nums[mini.back()])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    long long sum = nums[maxi.front()] + nums[mini.front()];
    ;
    for (int i = k; i < n; i++)
    {
        if (!maxi.empty() && i - maxi.front() == k)
        {
            maxi.pop_front();
        }
        if (!mini.empty() && i - mini.front() == k)
        {
            mini.pop_front();
        }
        while (!maxi.empty() && nums[i] >= nums[maxi.back()])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && nums[i] <= nums[mini.back()])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        sum += nums[maxi.front()] + nums[mini.front()];
    }
    return sum;
}
int main()
{
}