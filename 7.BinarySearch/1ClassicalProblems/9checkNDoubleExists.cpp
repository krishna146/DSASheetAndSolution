//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int binarySearch(int arr[], int start, int size, int target){
    int s = start;
    int e = size - 1;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(arr[mid] > )

    }
}
int * checkNDoubleExists(int arr[], int size){
    sort(arr, arr + size);
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > 0){
            binarySearch(arr, i + 1, size, 2*arr[i]);
        }
        else{
            binarySearch(arr, i + 1 , size, arr[i] / 2);
        }
    }
}
int main(){
    int arr[] = {10, 3, 5, 12, 6, 12};
    int size = sizeof(arr) / sizeof(int);
    checkNDoubleExists(arr, size);

}