//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int maxArrayElement(int arr[], int size){
    int maxi = INT_MIN;
    for(int i = 0 ; i < size ;i++){
        maxi = max(maxi, arr[i] );
    }
    return maxi;
}
int minArrayElement(int arr[], int size){
    int mini = INT_MAX;
    for(int i = 0 ; i < size ;i++){
        mini = min(mini, arr[i] );
    }
    return mini;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int arr[] = {3, 5, 7, 6, 9, 2};
   
    cout << maxArrayElement(arr, 6 ) << endl;
    cout << minArrayElement(arr, 6);
}
