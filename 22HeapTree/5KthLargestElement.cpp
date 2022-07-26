// Problem Link - https://leetcode.com/problems/kth-largest-element-in-an-array/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Approach1: Uinsg MinHeap wihtout using stl TC = K + (N - K) * logk SC = O(1)
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
// Approach2 using stl(priority queue) TC = K + (N - K) * logk SC = (K)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < k; i++)
        {
            minHeap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
// Approach3 Using Selection Proceedure TC = O(N)[Best case] TC = O(N^2) [Worst Case]
class Solution
{
private:
    int findRightPosition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left;
        for (int j = left + 1; j <= right; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i], nums[left]);
        return i;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int pivotIndex = findRightPosition(nums, left, right);
            cout << pivotIndex << " ";
            if (k == pivotIndex)
                return nums[pivotIndex];
            else if (k > pivotIndex)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }
        return 0;
    }
};