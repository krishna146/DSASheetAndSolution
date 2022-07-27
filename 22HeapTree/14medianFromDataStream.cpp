// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

public:
    MedianFinder()
    {
    }

    void addNum(int el)
    {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
        {
            maxHeap.push(el);
            median = el;
            return;
        }
        if (maxHeap.size() > minHeap.size())
        {
            if (el < maxHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(el);
            }
            else
            {
                minHeap.push(el);
            }
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() < minHeap.size())
        {
            if (el > minHeap.top())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(el);
            }
            else
            {
                maxHeap.push(el);
            }
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            if (el < maxHeap.top())
            {
                maxHeap.push(el);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(el);
                median = minHeap.top();
            }
        }
    }

    double findMedian()
    {
        return median;
    }
};