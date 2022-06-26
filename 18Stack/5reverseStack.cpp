//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&st ,int &el){
    if(st.empty()){
        st.push(el);
        return;
    }
    int val = st.top();
    st.pop();
    insertAtBottom(st, el);
    st.push(val);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int val = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,val);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(14);
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
}