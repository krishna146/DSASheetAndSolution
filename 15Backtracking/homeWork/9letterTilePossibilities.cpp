//Problem Link - https://leetcode.com/problems/letter-tile-possibilities/
/* By Krishna Kumar */
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
void solve(string tiles, string &output, set<string> &ans, map<int, bool> &flag){
    if(output.size() == tiles.size()){
        return;
    }
    for(int i = 0; i < tiles.size() ; i++){
        if(flag[i] == false){
            flag[i] = true;
            output.push_back(tiles[i]);
            ans.insert(output);
            solve(tiles, output, ans, flag);
            output.pop_back();
            flag[i] = false;
        }

    
    }

}
int main(){
    string tiles = "AAB";
    set<string> ans;
    string output = "";
    map<int, bool> flag;
    solve(tiles, output, ans, flag );
    for(auto el : ans){
        cout << el << " ";
    }
}