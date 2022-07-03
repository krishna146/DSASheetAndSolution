// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size)
    {
        this->arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }
    void push(int el)
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = el;
            return;
        }
        if ((rear + 1) % size == front)
        {
            cout << "overflow" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = el;
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "underflow" << endl;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        arr[front] = - 1;
        front = (front + 1) % size;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }
    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
    int getSize()
    {
        return rear - front;
    }
};
int main()
{
    CircularQueue q(5);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(11);
    q.pop();
    cout << "front element is : " << q.getFront() << endl;
    q.push(13);
    cout << "front element is : " << q.getFront() << endl;
    // cout << "size of queue is " << q.getSize() << endl;
    cout << "empty or not " << q.isEmpty() << endl;
    cout << "printing all elements inside queue : " << endl;
    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
}