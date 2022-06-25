//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//using sets
void storeCombinationSum(vector<int> &candidates, int target,int index, set<vector<int>> &ans, vector<int> &temp){
if(target == 0){
    vector<int> fans = {temp.begin(), temp.end()};
    sort(fans.begin(), fans.end());
    ans.insert(fans);
}
if(target < 0 || index == candidates.size()){
    return;
}
    temp.push_back(candidates[index]);
    storeCombinationSum(candidates, target-candidates[index], index + 1, ans, temp);
    temp.pop_back();
    storeCombinationSum(candidates , target, index + 1, ans, temp);

}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    set<vector<int>> ans;
    vector<int> temp;
    storeCombinationSum(candidates, target, 0, ans, temp);
    for(auto row : ans){
        for(auto el : row){
            cout << el << " ";
        }
        cout << endl;
    }
}