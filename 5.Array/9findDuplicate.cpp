//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int findDuplicate(int arr[], int size){
    int sum = 0;
    for(int i = 0 ; i < size ; i++){
        sum += arr[i];
    }
    int n = size - 1;
    int ans = sum - n * (n + 1)/2;
    return ans; 
}
int main(){
    int n = 10;
    int arr[11] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 7, 10};
    cout << findDuplicate(arr, 11);
    
}