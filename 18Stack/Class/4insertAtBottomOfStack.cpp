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
int main(){
    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(8);
    int el = 14;
    insertAtBottom(st, el);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
}