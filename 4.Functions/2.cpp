//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void printSquare(int n){
    int count = 1;
    while(count <= n){
        cout << count * count << " ";
        count += 1;
    }
}
int main(){
    int n = 6;
    printSquare(n);
}