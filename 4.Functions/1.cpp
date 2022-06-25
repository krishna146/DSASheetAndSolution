//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void printEven(int n){
    int count = 2;
    while(count <= n){
        cout << count << " ";
        count += 2;
    }
}
int main(){
    int n = 50;
    printEven(n);
}