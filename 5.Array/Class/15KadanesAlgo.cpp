//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int max(int a, int b){
    return (a > b) ? a : b;
}
int longestContinuousSubarraySum(int arr[], int size){

    //kadane's Algo

    int maxSoFar = INT_MIN;
    int start = 0 , right = 0, left = 0;
    int maxEnding = 0;
    int sum = 0;
    for(int i = 0 ; i < size ; i++){
        maxEnding += arr[i];
        // maxSoFar = max(maxEnding, maxSoFar);
        if(maxEnding > maxSoFar){
            maxSoFar = maxEnding;
            left = start;
            right = i;

        }
        if(maxEnding < 0){
            maxEnding = 0;
            start = i + 1;
        }

        }
        cout << "SubArray is : ";
        for(int i = start ; i <= right; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "sum = ";


    //Approach2:

    // int maxSoFar = INT_MIN;
    // for(int i = 0 ; i < size ; i++){
    //     for(int j = i ; j < size; j++){
    //         int sum = 0;
    //         for(int k = i; k <= j ; k++){
    //             sum += arr[k];
    //         }
    //         maxSoFar = max(maxSoFar, sum);
    //     }
    // }
    return maxSoFar;
}
int main(){
    int arr[] = {-1, 2, -1, 3, 2, -1, 4, -1, -3, 8, -1};
    int size = sizeof(arr) / sizeof(int);
    cout << longestContinuousSubarraySum(arr, size);

}