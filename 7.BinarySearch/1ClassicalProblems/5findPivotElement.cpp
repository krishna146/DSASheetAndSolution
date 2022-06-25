//Problem Link - 
/* By Krishna Kumar */

//pivot Element: Given a sorted integer array which is rotated any number of times, find the pivot index i.e. index of the minimum element of the array.
//eg: arr[] = { 1, 2, 3, 7, 9} rotate it -> {7, 9, 1, 2, 3} this array is now rotated and sorted. in this rotated sorted array maxm element is know as pivot element
#include<iostream>
using namespace std;
int findPivotElementIndex(int arr[], int size){
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        /* code */
        mid = left + (right - left) / 2;
        if(mid < right && arr[mid] > arr[mid + 1]) return mid;
        else if(mid > 0 && arr[mid] < arr[mid - 1]) return mid - 1;
        else if (arr[mid] > arr[0]) left = mid + 1;
        else right = mid - 1;
   
    }
    return -1;
    

}
int main(){
    int arr[] = {28, 39, 42, 43, 8, 9, 17, 19 , 26};
    //Pivot element is that element which is smaller than and all its previous element in rotated and sorted array
    //Note : A pivote element divides the array in two sorted arrays
    int size = sizeof(arr) / sizeof(int);

    cout << arr[findPivotElementIndex (arr, size)];


}