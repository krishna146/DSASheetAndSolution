//Problem Link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
#include<string>
string removeOccurrences(string s, string part) {
    
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.size());
    }
    return s;
}
int main(){
    cout << removeOccurrences("krishnakrishna", "na");
}