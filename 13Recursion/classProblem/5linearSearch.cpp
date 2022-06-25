//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int binarySearch(int *arr, int left, int right, int target){
    if(right < left) return false;
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) 
        return true;
    if(arr[mid] > target){
        return binarySearch(arr, left, mid - 1, target);
    }
    return binarySearch(arr, mid + 1, right, target);

}
int main(){
    int arr[] = {11, 13, 31, 55, 66, 78, 89, 889};
    int size = sizeof(arr) / sizeof(int);
    int target = 99;
    cout << binarySearch(arr, 0, size - 1, target) << endl; 
}