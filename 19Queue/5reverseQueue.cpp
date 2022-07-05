// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int el = q.front();
    q.pop();
    solve(q);
    q.push(el);
}
queue<int> rev(queue<int> q)
{
    // add code here.
    solve(q);
    return q;
}
int main()
{
}