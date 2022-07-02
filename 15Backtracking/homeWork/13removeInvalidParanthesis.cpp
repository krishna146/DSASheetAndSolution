// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    void solve(string &s, int count, set<string> &ans, int index)
    {
        if (count == 0)
        {
            if (isValidExpression(s))
                ans.insert(s);
            return;
        }
        for (int i = index; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                char ch = s[i];
                s.erase(s.begin() + i);
                solve(s, count - 1, ans, i);
                s.insert(s.begin() + i, ch);
            }
        }
    }

private:
    bool isValidExpression(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    return false;
                }
                else if (st.top() == ')')
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }

private:
    int countInvalidBrackets(string &s)
    {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    count++;
                }
                else if (st.top() == ')')
                {
                    count++;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return count + st.size();
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        int count = countInvalidBrackets(s);
        set<string> uniqAns;
        vector<string> ans;
        solve(s, count, uniqAns, 0);
        for (auto el : uniqAns)
        {
            ans.push_back(el);
        }
        return ans;
    }
};
int main()
{
}
