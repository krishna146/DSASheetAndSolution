// Problem Link -https://leetcode.com/problems/implement-queue-using-stacks/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//why queue using two stack -> to exploit multithreading i.e one stack for eqnueue and other stack for dequeue
class MyQueue
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int el = st2.top();
        st2.pop();
        return el;
    }

    int peek()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int el = st2.top();
        return el;
    }

    bool empty()
    {
        if (st1.empty() && st2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main()
{
}