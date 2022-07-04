// Problem Link -https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/
/* By Krishna Kumar */
#include <iostream>
#include<vector>
#include <stack>
using namespace std;
vector<int> help_classmate(vector<int> arr, int n)
{
    // Your code goes here
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
}