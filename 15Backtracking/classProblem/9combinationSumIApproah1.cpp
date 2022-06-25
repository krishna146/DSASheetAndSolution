//Problem Link - https://leetcode.com/problems/combination-sum/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
#include<vector>
void storeCombinationSum(vector<int> &candidates, int target,int index, vector<vector<int>> &ans, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
    }
    if(target < 0) return;
    for(int i = index; i < candidates.size(); i++){
        temp.push_back(candidates[i]);
        storeCombinationSum(candidates, target - candidates[i], i, ans, temp);
        temp.pop_back();
    }
}
int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> temp;
    storeCombinationSum(candidates, target, 0, ans, temp);
    for(auto row : ans){
        for(auto el : row){
            cout << el << " ";
        }
        cout << endl;
    }
}