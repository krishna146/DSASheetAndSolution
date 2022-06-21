//Problem Link - https://leetcode.com/problems/reverse-integer/
/* By Krishna Kumar */
#include<iostream>
#include<limits.h>
using namespace std;
int reverseInt(int n){
      int ans = 0;
    while(n != 0){
        int rem = n % 10;
        if(ans > INT_MAX / 10 || ans < INT_MIN / 10){
            return 0;
        }
        ans = ans * 10 + rem;
        n = n / 10;
    }
    return ans;
}
int main(){
    int n; 
    cin >> n;
    cout << reverseInt(n) << endl;
   
    
}
