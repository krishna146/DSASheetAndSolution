//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int min(int a, int b){
    return (a < b) ? a : b;
}

int countLessThanK(int arr[], int n, int k){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= k){
            count++;
        }
    }
    return count;
}
int minSwap(int arr[], int n, int k) {
    // Complet the function
    int lessThanK = countLessThanK(arr, n, k);
    int badSwap = 0;
    for(int i = 0 ; i < lessThanK ; i++){
        if(arr[i] > k){
            badSwap++;
        }
    }
    int ans = badSwap;
    int j = 0;
    for(int i = lessThanK ; i < n ; i++){
        if(arr[i] > k) 
            badSwap++;
        if(arr[j] > k){
            badSwap--;
        }
        ans = min(badSwap, ans);
        j++;
    }
    return ans;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
int main(){
    int arr[] = {2, 1, 5, 6, 3};
    int size = sizeof(arr) / sizeof(int);
    int k = 3;
    cout << minSwap(arr, size, k);
}