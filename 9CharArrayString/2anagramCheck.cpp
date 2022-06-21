//Problem Link - https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
/* By Krishna Kumar */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool checkAnagram(string a, string b){
    int arr[26] = {0};
    for(int i = 0 ; i < a.size(); i++){
        arr[a[i] - 'a'] ++;
    }
    for(int i = 0 ; i < b.size(); i++){
        arr[b[i] - 'a'] --;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(arr[i] != 0)
            return false;
    }
    return true;
}
bool checkAnagramUsingMap(string a, string b){
    unordered_map <char, int> freq;
    for(auto ch: a){
        freq[ch]++;
    }
    for(auto ch : b){
        freq[ch]--;
    }
    for(auto ch: freq){
        if(ch.second != 0)
            return false;
    }
    return false;
}
int main(){
    string a = "babbar";
    string b = "raabb";
    //a is said to be anagram of b if both contain type of characters

    cout << checkAnagram(a, b) << endl;



}