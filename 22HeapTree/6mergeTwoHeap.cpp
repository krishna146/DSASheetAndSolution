// Problem Link - https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    void heapifyTop(vector<int> &ans, int index)
    {
        while (index < ans.size())
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;
            if (leftChild < ans.size() && ans[leftChild] > ans[largest])
            {
                largest = leftChild;
            }
            if (rightChild < ans.size() && ans[rightChild] > ans[largest])
            {
                largest = rightChild;
            }
            if (largest != index)
            {
                swap(ans[index], ans[largest]);
                index = largest;
            }
            else
            {
                return;
            }
        }
    }

private:
    void buildHeap(vector<int> &ans)
    {
        for (int i = ans.size() / 2 - 1; i >= 0; i--)
        {
            heapifyTop(ans, i);
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // your code here
        vector<int> ans;
        for (auto el : a)
        {
            ans.push_back(el);
        }
        for (auto el : b)
        {
            ans.push_back(el);
        }
        buildHeap(ans);
        return ans;
    }
};