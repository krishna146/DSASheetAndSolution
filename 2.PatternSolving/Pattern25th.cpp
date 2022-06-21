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
    int n;
    cin >> n;
    for(int row = 1; row <= n ; row ++){
        //for each fow 
        for(int col = 1; col <= row ; col++){
            cout << nCr(row - 1, col - 1) << " ";
        }
        //after each row
        cout << endl;
    }
}