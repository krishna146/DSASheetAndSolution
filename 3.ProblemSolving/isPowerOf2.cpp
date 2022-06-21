//Problem Link - https://leetcode.com/problems/power-of-two/submissions/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int main(){
    int num;
    cin >> num;
    if(num <=0)
        return;
    else{
        if(!(num & num -1))
        {
            cout << "power of 2";
        }
    }
}