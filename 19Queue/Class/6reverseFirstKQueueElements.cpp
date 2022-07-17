// Problem Link - https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    int n = q.size();
    stack<int> st;
    int temp = k;
    while (temp--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    temp = n - k;
    while (temp--)
    {
        int el = q.front();
        q.pop();
        q.push(el);
    }
    return q;
}
int main()
{
}