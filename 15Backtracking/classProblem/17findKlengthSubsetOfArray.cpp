//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
void findKLengthSubset(vector<int> &arr, vector<vector<int>> &ans, int index, vector<int> &temp, int &k){
    if(index == arr.size()){
        if(temp.size()){
            ans.push_back(temp);
        }
        return;
    }

    findKLengthSubset(arr, ans, index + 1, temp, k);
    temp.push_back(arr[index]);
    findKLengthSubset(arr, ans, index + 1, temp, k);
    temp.pop_back();

}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    int k = 2;
    findKLengthSubset(arr, ans, index, temp, k);
    for(auto array : ans){
        for(auto el: array){
            cout << el << " ";
        }
        cout << endl;
    }
    cout << ans.size();
}