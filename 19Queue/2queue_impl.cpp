//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Queue{
    private:
        int *arr;
        int front;
        int rear;
        int size;
    public:
        Queue(int size){
            this->arr = new int[size];
            front = 0;
            rear = 0;
            this -> size = size;
        }
        void push(int el){
            if(rear == size){
                cout << "overflow" << endl;
            }
            arr[rear] = el;
            rear++;

        }
        void pop(){
            if(front == rear){
                cout << "underflow" << endl;
            }
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
        bool isEmpty(){
            if(front == rear) return true;
            return false;
        }
        int getFront(){
            if(front == rear){
                return -1;
            }
            return arr[front];
        }
        int getSize(){
            return rear - front;
        }
};
int main(){
    Queue q(5);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    cout << "front element is : " << q.getFront() << endl;
    q.pop();
    cout << "front element is : " << q.getFront() << endl;
    cout << "size of queue is " << q.getSize() << endl;
    cout << "empty or not "<< q.isEmpty() << endl;
    cout << "printing all elements inside queue : " << endl;
    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.pop();

    }

}