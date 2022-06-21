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
int nCr(int n, int r){
    int ans = calcFactorial(n)/(calcFactorial(n - r) * calcFactorial(r));
    return ans;
}
int main(){
    int n = 5 ;
    int r = 2 ;
    cout << nCr(5, 2);
}