//Problem Link - https://www.interviewbit.com/problems/valid-bst-from-preorder/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution{
    public:
    int solve(vector<int> &a);
};
void solveAns(vector<int> &arr, int &index, int N, int mini, int maxi){
      if(index >= N) return;
      if(arr[index] > mini && arr[index] < maxi){
          int data = arr[index++];
          solveAns(arr, index, N, mini, data);
          solveAns(arr, index, N, data, maxi);
      }
      return;
      
  }
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int index = 0;
    solveAns(A, index, n, INT_MIN, INT_MAX);
    if(index == n) return 1;
    return 0;
}