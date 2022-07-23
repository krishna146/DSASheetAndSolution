// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void heapifyBottome(vector<int> &arr)
{
}
void heapifyTop(vector<int> &arr, int index, int size)
{
    while (index < arr.size())
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if (leftChild < size && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
        if (rightChild < size && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            index = largest;
        }
        else
        {
            return;
        }
    }
}
void buildHeap(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyTop(arr, i, size);
    }
}
void heapSort(vector<int> &arr)
{
    buildHeap(arr);
    int size = arr.size();
    while (size > 1)
    {
        swap(arr[size - 1], arr[0]);
        heapifyTop(arr, 0, size - 1);
        size--;
    }
}
int main()
{
    vector<int> arr = {7, 5, 2, 3, 9, 8, 11, 12};
    heapSort(arr);
    for (auto el : arr)
    {
        cout << el << " ";
    }
}