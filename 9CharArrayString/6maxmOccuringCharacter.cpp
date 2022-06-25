//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
char getMaxOccuringChar(string str)
{
    // Your code here
    int arr[26] ={};
    for(auto ch : str){
        arr[ch - 97]++;
    }
    int maxIndex = 0;
    for(int i = 1 ; i < 26; i++){
        if(arr[i] > arr[maxIndex]){
            maxIndex = i;
        }
    }
    char ans = maxIndex + 97;
    return ans;
    
}
int main(){
    cout << getMaxOccuringChar("krishnasushma");
}