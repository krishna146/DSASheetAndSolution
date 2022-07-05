// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        int temp = nums[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > temp)
            {
                st.push(nums[i]);
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int item = nums[i];
            while (!st.empty() && st.top() <= item)
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(item);
        }
        return ans;
    }
};
int main()
{
}