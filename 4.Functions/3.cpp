//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int calcFactorial(int n){
    int count = 1;
    int fact = 1;;
    while(count <= n){
        fact = fact * count;
        count ++;
    }
    return fact;
}
int main(){
    int n = 6;
    cout << calcFactorial(12);
}