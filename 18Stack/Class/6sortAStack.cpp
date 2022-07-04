//Problem Link - https://practice.geeksforgeeks.org/problems/sort-a-stack/1
/* By Krishna Kumar */
#include<iostream>j
#include<stack>
using namespace std;
void sortedInsert(stack<int> &st, int &el){
    if(st.empty()){
        st.push(el);
        return;
    }
    if(st.top() > el){
        int temp = st.top();
        st.pop();
        sortedInsert(st, el);
        st.push(temp);
        return;
    }
    st.push(el);
    return;
}
void solve(stack<int> &st){
  if(st.empty()){
       return;
   }
   int temp = st.top();
   st.pop(); 
   solve(st);
   sortedInsert(st, temp);
}
int main(){
    
}