// Problem Link - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int size = nums.size();
        int swap = 0;
        int countEqualOne = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 1)
                countEqualOne++;
        }
        for (int i = 0; i < countEqualOne; i++)
        {
            if (nums[i] == 0)
                swap++;
        }
        int left = 0;
        int iter = 0;
        int ans = swap;
        for (int right = countEqualOne; (right < size && iter == 0) || right < countEqualOne - 1; right = (right + 1) % size)
        {
            if (nums[right] == 0)
                swap++;
            if (nums[left] == 0)
                swap--;
            left++;
            ans = min(ans, swap);
            if (right == size - 1)
            {
                iter = 1;
            }
        }
        return ans;
    }
};
int main()
{
}