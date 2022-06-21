//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
bool checkPalindrome(int arr[], int size){
    int i = 0;
    int right = size - 1;
    while(i < right){
        if(arr[i] != arr[right]){
            return false;
        }
        i++;
        right--;
    }
    return true;
}
int main(){
    int arr[] = {1, 2, 3, 3, 2, 5};
    cout << checkPalindrome(arr, 6);
}