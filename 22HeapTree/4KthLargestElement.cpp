// Problem Link - https://leetcode.com/problems/kth-largest-element-in-an-array/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Approach1: Uinsg MinHeap wihtout using stl TC = K + (N - K) * logk SC = O(1)
class Solution
{
private:
    void heapifyTop(vector<int> &nums, int index, int size)
    {
        while (index < size)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;
            if (leftChild < size && nums[leftChild] < nums[smallest])
            {
                smallest = leftChild;
            }
            if (rightChild < size && nums[rightChild] < nums[smallest])
            {
                smallest = rightChild;
            }
            if (index != smallest)
            {
                swap(nums[smallest], nums[index]);
                index = smallest;
            }
            else
            {
                return;
            }
        }
    }

private:
    void buildHeap(vector<int> &nums, int size)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyTop(nums, i, size);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        buildHeap(nums, k);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > nums[0])
            {
                nums[0] = nums[i];
                heapifyTop(nums, 0, k);
            }
        }
        return nums[0];
    }
};
//Approach2 using stl(priority queue) TC = K + (N - K) * logk SC = (K)