// Problem Link -
/* By Krishna Kumar */
#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] == data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
            return;
        }
        top--;
    }
    bool isEmpty(){
        if(top == -1)
            return 0;
        return 1;
    }
    int getTop()
    {

        return arr[top];
    }
    int getSize()
    {
        return this->top;
    }
};
int main()
{
    Stack st(5);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(9);
    st.push(10);
    cout << st.getSize() << endl;
    cout << st.getTop() << endl;
}