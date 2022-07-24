// Problem Link - https://leetcode.com/problems/first-unique-character-in-a-string/
// Problem Link -https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1/#
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
int firstUniqChar(string s) {
    int freq[26] = {};
    for(int i = 0 ; i < s.size() ; i++){
        freq[s[i] % 26]++;
    }
    for(int i = 0 ; i < s.size(); i++){
        if(freq[s[i] % 26] == 1){
            return i;
        }
    }
    return -1;
}
int main(){
    string s = "hello";
    firstUniqChar(s);
}