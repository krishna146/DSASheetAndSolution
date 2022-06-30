// Problem Link - https://leetcode.com/problems/valid-parentheses/
/* By Krishna Kumar */
#include <iostream>
#include <stack>
using namespace std;
bool match(char close, char open)
{
    if (close == ')' && open == '(')
        return true;
    else if (close == ']' && open == '[')
        return true;
    else if (close == '}' && open == '{')
        return true;
    return false;
}

bool isValid(string s)
{
    if (s.length() & 1)
        return false;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                if (match(ch, st.top()))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}
int main()
{
}