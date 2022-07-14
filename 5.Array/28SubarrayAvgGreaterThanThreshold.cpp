// Problem Link - https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        float avg = 0;
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            avg += arr[i];
        }
        avg = avg / k;
        count += avg >= threshold;
        int left = 0;
        for (int right = k; right < arr.size(); right++)
        {
            avg = (avg * k - arr[left] + arr[right]) / k;
            count += avg >= threshold;
            left++;
        }
        return count;
    }
};
int main()
{
}