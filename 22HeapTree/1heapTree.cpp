// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[250];
    int size;
    Heap()
    {
        size = 0;
    }
    void insertIntoHeap(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index != 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletFromHeap()
    {
        if (size == 0)
        {
            cout << "heap underflow" << endl;
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        int index = 1;
        int largest = index;
        while (index <= size)
        {
            int leftChild = 2 * index;
            if (leftChild <= size && arr[leftChild] > arr[largest])
            {
                largest = leftChild;
            }
            int rightChild = 2 * index + 1;
            if (rightChild <= size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }
            if (index != largest)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }
    void heapify(int arr[], int n , int i){
        while(index <= ){

        }
    }
};
int main()
{
    Heap maxHeap;
    maxHeap.insertIntoHeap(2);
    maxHeap.insertIntoHeap(6);
    maxHeap.insertIntoHeap(8);
    maxHeap.insertIntoHeap(3);
    maxHeap.insertIntoHeap(7);
    maxHeap.print();
    maxHeap.deletFromHeap();
    maxHeap.print();
}