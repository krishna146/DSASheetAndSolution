#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, int> p = {2, 10};
    pair<int, int> q = {7, 11};
    pair<int, int> r = {4, 16};
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    pq.push(p);
    pq.push(q);
    pq.push(r);
    cout << pq.top().first ;

}
