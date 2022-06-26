//Problem Link - https://leetcode.com/problems/maximum-product-of-word-lengths/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
int maxProduct(vector<string>& words) {
    int maxpro = 0;
    for(int i = 0 ; i < words.size() - 1; i++){
        unordered_map <char, int > ump;
        for(auto el : words[i]){
            ump[el]++;
        }
        for(int j = i + 1; j < words.size(); j++){
            bool flag = true;
            for(auto el : words[j]){
                if(ump[el]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int candidate = words[i].size() * words[j].size();
                maxpro = max(candidate, maxpro);
            }
        }
    }
    return maxpro;
}
int main(){
    vector<string >words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << maxProduct(words);
}