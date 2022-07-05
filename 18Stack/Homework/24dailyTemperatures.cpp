// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            pair<int, int> p;
            p.first = temperatures[i];
            p.second = 1;
            while (!st.empty() && st.top() <= temperatures[i])
            {
                p.second += st.top().second;
                st.pop();
            }
            if (st.empty())
            {
                p.second = 0;
            }
            st.push(p);
            ans[i] = p.second;
        }
        return ans;
    }
};
int main()
{
}