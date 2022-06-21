//Problem Link - 
/* By Krishna Kumar */

//pivot Element: Given a sorted integer array which is rotated any number of times, find the index of target element
//eg: arr[] = { 1, 2, 3, 7, 9} rotate it -> {7, 9, 1, 2, 3} this array is now rotated and sorted array
#include<iostream>
using namespace std;
int searchRotatedAndSortedArray(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        /* code */
        mid = left + (right - left) / 2;
        if(arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1]){
            return mid;
        }
        else if(arr[mid] <= arr[0]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return mid;
    

}
int main(){
    int arr[] = {28, 39, 43, 42, 8, 9, 17, 19 , 26};
    //Pivot element is that element which is smaller than and all its previous element in rotated and sorted array
    //Note : A pivote element divides the array in two sorted arrays
    int size = sizeof(arr) / sizeof(int);
    int target;
    cin >> target;
    cout << searchRotatedAndSortedArray(arr, size, target);


}