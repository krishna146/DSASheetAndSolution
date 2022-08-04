// Problem Link - https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void heapifyTop(vector<int> &arr, int index)
{
    int size = arr.size();
    while (index < size)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < size && arr[leftChild] < arr[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < size && arr[rightChild] < arr[smallest])
        {
            smallest = rightChild;
        }
        if (index != smallest)
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
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
    {
        heapifyTop(arr, i);
    }
    return arr;
}
