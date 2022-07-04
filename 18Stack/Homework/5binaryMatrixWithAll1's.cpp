//Problem Link 1 - https://leetcode.com/problems/maximal-rectangle/
//Problem Link 2 - https://practice.geeksforgeeks.org/problems/max-rectangle/1/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
private:
    vector<int> findPreviousSmallerElement(vector<int> &heights)
    {
        vector<int> ans(heights.size());
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < heights.size(); i++)
        {
            int item = heights[i];
            while (st.top() != -1 && heights[st.top()] >= item)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

private:
    vector<int> findNextSmallerElement(vector<int> &heights)
    {
        vector<int> ans(heights.size());
        stack<int> st;
        st.push(-1);
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            int item = heights[i];
            while (st.top() != -1 && heights[st.top()] >= item)
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = heights.size();
            else
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

private:
    int findAreaOfHistogram(vector<int> &heights)
    {
        vector<int> ps = findPreviousSmallerElement(heights);
        vector<int> ns = findNextSmallerElement(heights);
        int maxArea = INT_MIN;
        for (int index = 0; index < heights.size(); index++)
        {
            int breadth = ns[index] - ps[index] - 1;
            int currArea = breadth * heights[index];
            maxArea = max(currArea, maxArea);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> heights(n, 0);
        int maxArea = INT_MIN;
        for (int col = m - 1; col >= 0; col--)
        {
            for (int row = 0; row <= n - 1; row++)
            {
                if (matrix[row][col] == '0')
                {
                    heights[row] = 0;
                }
                else
                {
                    heights[row] += 1;
                }
               
            }
            int currArea = findAreaOfHistogram(heights);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};
int main()
{
}