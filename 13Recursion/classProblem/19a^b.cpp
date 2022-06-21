//Problem Link - https://leetcode.com/problems/powx-n/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
double helper(double x, int n){
    if(n == 0) return 1;
    double ans = helper(x, n/2);
    if(n & 1)
        return x * ans * ans;
    return ans * ans;    
}
double myPow(double x, int n) {
    double ans = helper(abs(x), abs(n));
    
    if(n < 0){
        ans = 1.0/ans;
    }
    if(x < 0 && (n % 2 == -1 || n % 2 == 1)){
        ans = -1 * ans;
    }
    return ans;
    
}
int main(){
    double a;
    int b;
    cin >> a >> b;
    cout << myPow(a, b);
}