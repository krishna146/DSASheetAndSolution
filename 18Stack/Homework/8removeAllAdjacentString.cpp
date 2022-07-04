// Problem Link -https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans(st.size(), '0');
        for (int i = st.size() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
int main()
{
}