//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(3);
    dq.push_front(5);
    //
    dq.pop_back();
    dq.pop_back();
    cout << dq.empty() << endl;
    
}