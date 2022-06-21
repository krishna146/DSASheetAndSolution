//Problem Link - https://www.geeksforgeeks.org/number-flips-make-binary-string-alternate/
/* By Krishna Kumar */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char flip(char expected){
    if(expected == '0') return '1';
    else return '0';
}
int getFlips(string str, char expected){
    int countFlips = 0;
    for(int i = 0; i < str.size() ; i++){
        if(str[i] != expected)
            countFlips++;
        expected = flip(expected);
    }
    return countFlips;
}
int main(){
    string str = "101000";
    int ans = getFlips(str, '0');
    int ans1 = getFlips(str, '1');
    cout << min(ans, ans1);
}