//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int reverseNum(int num, int ans){
    if(num == 0) return ans;
    int digit = num % 10;
    num = num / 10;
    ans = ans * 10 + digit;
    return reverseNum(num, ans);
}
int main(){
    cout << reverseNum(4545, 0);
}