// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include<stack>
using namespace std;
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool isRedundant = true;
            while (st.top() != '(')
            {
                char curr = st.top();
                if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
                {
                    isRedundant = false;
                }
                st.pop();
            }
            st.pop();
            if (isRedundant)
                return true;
        }
    }
    return false;
}

int main()
{
}