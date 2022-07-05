// Problem Link - https://leetcode.com/problems/online-stock-span/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class StockSpanner
{
private:
    stack<pair<int, int>> st;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        pair<int, int> p;
        p.first = price;
        p.second = 1;
        while (!st.empty() && st.top().first <= price)
        {
            p.second += st.top().second;
            st.pop();
        }
        st.push(p);
        return p.second;
    }
};

int main()
{
}