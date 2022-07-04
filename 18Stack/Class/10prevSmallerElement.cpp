// Problem Link -https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/
/* By Krishna Kumar */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> leftSmaller(int n, int a[])
{
    // code here
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() >= a[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(a[i]);
    }
    return ans;
}
int main()
{
}