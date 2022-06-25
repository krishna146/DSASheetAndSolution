//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
void sayDigits(int num, string *arr){
    if(num == 0)
        return;
    sayDigits(num / 10, arr);
    cout << arr[num % 10 ] << " ";
}
int main(){
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};

    sayDigits(243, arr);
}