//Problem Link - https://leetcode.com/problems/combination-sum-iii/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
void storeAns(int k , int n, vector<vector<int>> &ans, vector<int> &temp, int num){
    if(k == 0 && n == 0){
        ans.push_back(temp);
    }
    for(int i = num ; i <= 9 ; i++){
        if(n < i) break;
        temp.push_back(i);
        storeAns(k - 1, n - i, ans, temp, i + 1);
        temp.pop_back();
    }
}
int main(){
    int k = 3;
    int n = 9;
    vector<int> temp;
    vector<vector<int>> ans;
    storeAns(k, n, ans, temp, 1);    
    for(auto row : ans){
        for(auto el : row){
            cout << el << " ";
        }
        cout << endl;
    }
    
}