// Problem Link - https://leetcode.com/problems/next-greater-element-i/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> findNextGreaterElement(vector<int> &nums2)
{
    vector<int> ans(nums2.size());
    stack<int> st;
    st.push(-1);
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        int item = nums2[i];
        while (st.top() != -1 && st.top() <= item)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(item);
    }
    return ans;
}
//Approach1
// timeComplexity = O(nums1 + nums2) spaceComplexity = O(nums2);
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums2NextSmaller = findNextGreaterElement(nums2);
    unordered_map<int, int> ump;
    for (int j = 0; j < nums2.size(); j++)
    {
        ump[nums2[j]] = nums2NextSmaller[j];
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(ump[nums1[i]]);
    }
    return ans;
}
//Approach2:
// timeComplexity = O(nums1*nums2) spaceComplexity = O(nums2);
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> nums2NextSmaller = findNextGreaterElement(nums2);
//     vector<int> ans;
//     for (int i = 0; i < nums1.size(); i++)
//     {
//         for (int j = 0; j < nums2.size(); j++)
//         {
//             if (nums1[i] == nums2[j])
//             {
//                 ans.push_back(nums2NextSmaller[j]);
//                 break;
//             }
//         }
//     }
//     return ans;
// }
int main()
{
}