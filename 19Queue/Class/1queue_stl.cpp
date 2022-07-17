//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    queue<int> q;
    q.push(3);
    q.push(5);
    q.push(8);
    q.push(9);
    cout << "printing front element: " << q.front() << endl;
    q.pop();

    cout << "Size of queue " << q.size() << endl;
    cout << "Empty or not " << q.empty() << endl;
    cout << "Printing Queue: " ;
    while(!q.empty()){
        cout << q.front() << " " ;
        q.pop();
    }
}