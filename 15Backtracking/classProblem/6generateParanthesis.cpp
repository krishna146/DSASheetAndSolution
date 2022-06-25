//Problem Link - https://leetcode.com/problems/generate-parentheses/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int &currOpen, int &currClose ,int &remOpen, int &remClose, string &output, vector<string> &ans){
    
    if(remClose == 0 && remClose == 0){
        ans.push_back(output);
        return;
    }
    //call for open bracket
    if(remOpen > 0){
        currOpen++;
        output.push_back('(');
        remOpen--;
        solve(currOpen , currClose, remOpen, remClose, output, ans);
        output.pop_back();
        currOpen--;
        remOpen++;
        
    }
    //call for close bracket
    if(remClose > 0 && currOpen > currClose){
        output.push_back(')');
        currClose++;
        remClose--;
        solve(currOpen , currClose, remOpen, remClose, output, ans);
        currClose--;
        remClose++;
        output.pop_back();
    }
    
    
    
}
vector<string> generateParenthesis(int n) {
    int currOpen = 1, currClose = 0;
    int remOpen = n - 1;
    int remClose = n;
    vector<string> ans;
    string output = "(";
    solve(currOpen, currClose, remOpen, remClose, output, ans);
    return ans;
}
int main(){
    vector<string> ans = generateParenthesis(3);
    for(auto el: ans){
        cout << el << endl;
    }
}