// Problem Link - https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    long long minimumDifference(vector<int> &a)
    {
        int N = a.size() / 3;
        vector<long long> prefixSum;
        vector<long long> suffixSum;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            maxHeap.push(a[i]);
            sum += a[i];
        }
        prefixSum.push_back(sum);
        for (int i = N; i < 2 * N; i++)
        {
            if (a[i] < maxHeap.top())
            {
                sum -= maxHeap.top();
                maxHeap.pop();
                sum += a[i];
                maxHeap.push(a[i]);
            }
            prefixSum.push_back(sum);
        }
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            minHeap.push(a[3 * N - 1 - i]); 
            sum += a[3 * N - 1 - i];
        }
        suffixSum.push_back(sum);

        for (int i = N; i < 2 * N; i++)
        {
            if (a[3 * N - 1 - i] > minHeap.top())
            {
                sum -= minHeap.top();
                minHeap.pop();
                sum += a[3 * N - 1 - i];
                minHeap.push(a[3 * N - 1 - i]);
            }
            suffixSum.push_back(sum);
        }
        cout << prefixSum.size() << suffixSum.size() ;
        long long ans = LLONG_MAX;
        for (int i = 0; i <  suffixSum.size(); i++)
        {
            long long diff = prefixSum[i] - suffixSum[suffixSum.size() - i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};