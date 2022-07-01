// Problem Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
private:
    vector<int> nextSmallest(vector<int> arr)
    {
        // Your code goes here
        stack<int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = arr.size();
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

private:
    vector<int> prevSmallest(vector<int> &arr)
    {
        // code here
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < arr.size(); i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> ns = nextSmallest(heights);
        vector<int> ps = prevSmallest(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < ns.size(); i++)
        {
            int area = heights[i] * (ns[i] - ps[i] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
int main()
{
}