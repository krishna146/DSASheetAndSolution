//Problem Link - https://leetcode.com/problems/complement-of-base-10-integer/submissions/ 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int num, mask = 0;
    cin >> num;
    while(mask < num){
        mask = (mask << 1) | 1;
    }
    int ans = ~num & mask;
    cout << num;
}