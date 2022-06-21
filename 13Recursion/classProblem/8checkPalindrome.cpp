//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(string &str,int start,  int end){
    if(start >= end) return true;
    if(str[start] == str[end])
        return checkPalindrome(str, start + 1 , end - 1);
    return false;

}
int main(){
    string str = "abccba";
    cout << checkPalindrome(str, 0, str.size() - 1);
}