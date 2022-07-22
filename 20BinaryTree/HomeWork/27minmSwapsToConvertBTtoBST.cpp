// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0?page=1&sortBy=newest&query=page1sortBynewest
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int minSwapsToSort(vector<int> &arr)
    {
        int n = arr.size();
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }
        sort(arrPos, arrPos + n);

        vector<bool> vis(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] || arrPos[i].second == i)
                continue;
            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;

                j = arrPos[j].second;
                cycle_size++;
            }

            if (cycle_size > 0)
            {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

public:
    int minSwaps(vector<int> &A, int n)
    {
        stack<int> st;
        vector<int> inorder;
        int index = 0;
        while (index < A.size() || st.empty() == false)
        {
            while (index < A.size())
            {
                st.push(index);
                index = 2 * index + 1;
            }
            index = st.top();
            st.pop();
            inorder.push_back(A[index]);
            index = 2 * index + 2;
        }
        return minSwapsToSort(inorder);
    }
};