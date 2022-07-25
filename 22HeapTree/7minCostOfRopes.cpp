// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// from scratch
class Approach1
{
private:
    void heapifyTop(long long *arr, long long index, long long size)
    {
        while (index < size)
        {
            long long leftChild = 2 * index + 1;
            long long rightChild = 2 * index + 2;
            long long smallest = index;
            if (leftChild < size && arr[leftChild] < arr[smallest])
            {
                smallest = leftChild;
            }
            if (rightChild < size && arr[rightChild] < arr[smallest])
            {
                smallest = rightChild;
            }
            if (smallest != index)
            {
                swap(arr[smallest], arr[index]);
                index = smallest;
            }
            else
            {
                return;
            }
        }
    }

private:
    void buildHeap(long long *arr, long long size)
    {
        for (long long i = size / 2 - 1; i >= 0; i--)
        {
            heapifyTop(arr, i, size);
        }
    }

private:
    void heapifyBottom(long long *arr, long long size)
    {
        long long index = size - 1;
        while (index > 0)
        {
            long long parent = (index - 1) / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        long long ans = 0;
        buildHeap(arr, n);
        while (n > 1)
        {
            long long first = arr[0];
            arr[0] = arr[n - 1];
            n--;
            heapifyTop(arr, 0, n);
            long long second = arr[0];
            arr[0] = arr[n - 1];
            n--;
            heapifyTop(arr, 0, n);
            long long sum = first + second;
            ans += sum;
            arr[n] = sum;
            n++;
            heapifyBottom(arr, n);
        }
        return ans;
    }
};
// using c++ STL
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (long long i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }
        long long ans = 0;
        while (minHeap.size() > 1)
        {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            minHeap.push(first + second);
            ans += first + second;
        }
        return ans;
    }
};