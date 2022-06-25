//Problem Link - https://leetcode.com/problems/permutations/submissions/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printPermutation(string &str, vector<int> marked, string output){
    if(output.size() == str.size()){
        cout << output << " ";
        return;
    }
    for(int i = 0; i < str.size() ; i++){
        bool flag = true;
        for(int j = 0; j < marked.size(); j++){
            if(i == marked[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            marked.push_back(i);
            printPermutation(str, marked, output + str[i]);
            marked.pop_back();
        }
    }
}
int main(){
    string str = "abc";
    vector<int> marked;
    printPermutation(str, marked, "");
}