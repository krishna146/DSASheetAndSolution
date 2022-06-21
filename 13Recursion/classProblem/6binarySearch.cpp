//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int binarySearch(int *arr, int left, int right, int target){
    if(left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) return binarySearch(arr, left , mid - 1 , target);
    return binarySearch(arr, mid + 1, right, target);

}
int main(){
    int arr[] = {5, 9 , 14 , 16 , 74};
    int size = sizeof(arr)/sizeof(int);
    int target = 10;
    cout << binarySearch(arr, 0, size - 1, target);
}