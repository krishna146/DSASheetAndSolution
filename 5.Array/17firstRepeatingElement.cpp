//Problem Link - https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/
/* By Krishna Kumar */
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int firstRepeated(int arr[], int n) {
    // code here
    unordered_map<int, int> freq;
    int minIndex = INT_MAX;
    for(int i = 0; i < n ; i++){
        if(freq[arr[i]] != 0){
            minIndex = min(minIndex, freq[arr[i]]);
        }
        freq[arr[i]] = i + 1;
    }
    return (minIndex == INT_MAX)? -1 : minIndex;
}
int main(){
    int arr[] = { 1, 5, 2, 7, 6, 1, 4, 2, 3, 2, 2, 1, 6, 8, 5, 7, 6, 1, 8, 9, 2, 7, 9, 5, 4, 3, 1};
    int size = sizeof(arr) / sizeof(int);
    cout << firstRepeated(arr, size);
}