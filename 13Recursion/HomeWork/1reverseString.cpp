//Problem Link - https://leetcode.com/problems/reverse-string/submissions/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<char> &s, int i){
    if(i >= s.size() / 2){
        return;
    }
    swap(s[i], s[s.size() - i - 1]);
    reverse(s, i + 1);
}
int main(){
    vector<char> ch = {'a', 'b', 'c', 'd', 'e','f'};
    reverse(ch, 0);
    for(auto el : ch){
        cout << el << " ";
    }
}