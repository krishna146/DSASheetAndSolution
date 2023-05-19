//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int add(int a, int b){
    return a + b;
}
int main(){
    int (*fp)(int , int);
    fp = add;
    cout << fp(2, 3);
}