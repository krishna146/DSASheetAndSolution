//Problem Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
#include<string>
string removeDuplicates(string s) {
    int i = 0;
    int right = s.size() - 1;
    while(i < right ){
        if(s[i] == s[i + 1]){
            s.erase(i, 2);
            right = right - 2;
            if(i > 0)
                i--;
        }
        else
            i++;
    
    }
    return s;
}
int main(){
    cout << removeDuplicates("abbaca") << endl;
}