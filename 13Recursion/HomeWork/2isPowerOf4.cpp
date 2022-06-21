//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
//method1
bool solve(double n){
    if(n == 1.0)
    {
        return true;
        
    }
    if(n > 0 && n < 1) return false;
    return solve(n / 4);
}
//method2
bool solveOptimize(int n){
    if((n & n -1) == 0 && (n - 1) % 3 == 0){
        return true;
    }
    return false;
}
int main(){
    int n ;
    cin >> n;
    cout << solve(n) << endl;
    cout << solveOptimize(n);
}