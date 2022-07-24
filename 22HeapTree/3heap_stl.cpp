// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    // max heap
    priority_queue<int> maxheap;
    maxheap.push(1);
    maxheap.push(2);
    maxheap.push(5);
    maxheap.push(5);
    maxheap.push(3);
    cout << maxheap.top() << endl;
    maxheap.pop();
    cout << maxheap.size() << endl;
    cout << maxheap.empty() << endl;
    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(1);
    minheap.push(2);
    minheap.push(5);
    minheap.push(5);
    minheap.push(3);
    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.size() << endl;
    cout << minheap.empty() << endl;
}