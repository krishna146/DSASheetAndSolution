//Problem Link - https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Using Recursion
int getFibonacciRecursion(int n){
    if(n <= 1) return n;
    return getFibonacciRecursion(n - 1) + getFibonacciRecursion(n - 2);
}
//Using Recursion + memorization
//step1 : create dp array
//step2 : store the ans in dp array
//step3 : check if dp array already has answer, if yes then return 
int getFibonacciDP(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = getFibonacciDP(n - 1, dp) + getFibonacciDP(n - 2, dp);
}
//Bottom-up approach
//step1: dp -array creation
//step2: Base  case analysis of REc code and update dp array accordingly
//step3: find the range for changing varibalbes and copy pase the logic in rec code according
int getFibonacciBottomUP(int n){
    //step 1
    vector<int> dp(n + 1, 0);
    //step 2
    dp[0] = 0;
    
    dp[1] = 1;
    //step3
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//Space Optimization
int getFibonacciSpaceOptimization(int n){
    if(n <= 1) return n;
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for(int i = 2 ; i <= n ; i++){
        curr = prev1 + prev2;
        int temp = prev2;
        prev2 = curr;
        prev1 = temp;
    }
    return curr;
}
int main(){
    int n;
    cin >> n;
    cout << getFibonacciRecursion(n) << endl;
    //step1 create dp array
    vector<int> dp(n + 1, -1);
    cout << getFibonacciDP(n, dp) << endl;
    cout << getFibonacciBottomUP(n) << endl;
    cout << getFibonacciRecursion(n) << endl;
    cout << getFibonacciSpaceOptimization(n) << endl;

}