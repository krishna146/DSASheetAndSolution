// Problem Link - https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1/
/* By Krishna Kumar */
#include <iostream>
#include <stack>
using namespace std;
int countRev(string s)
{
    // your code here
    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '{')
        {
            st.push('{');
        }
        else
        {
            if (st.empty())
            {
                count++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.size() & 1)
        return -1;
    return count + st.size() / 2;
}
int main()
{
}