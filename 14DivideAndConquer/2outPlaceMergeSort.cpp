//Problem Link - https://practice.geeksforgeeks.org/problems/merge-sort/1/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void merge(int arr[], int left, int right){
    int mid = left + (right - left)/2;
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int *leftArray = new int[leftLength];
    int *rightArray = new int[rightLength];
    int originalIndex = left;
    for(int i = 0 ; i < leftLength ; i++){
        leftArray[i] = arr[originalIndex];
        originalIndex++;
    }
    originalIndex = mid + 1;
    for(int i = 0 ; i < rightLength ; i++){
        rightArray[i] = arr[originalIndex];
        originalIndex++;
    }
    originalIndex = left;
    int leftIndex = 0;
    int rightIndex = 0;
    while(leftIndex < leftLength && rightIndex < rightLength){
        if(leftArray[leftIndex] <= rightArray[rightIndex]){
            arr[originalIndex] = leftArray[leftIndex];
            originalIndex++;
            leftIndex++;
        }
        else{
            arr[originalIndex] = rightArray[rightIndex];
            originalIndex++;
            rightIndex++;
        }
    }
    while(leftIndex < leftLength){
        arr[originalIndex] = leftArray[leftIndex];
        leftIndex++;
        originalIndex++;
    }
    while(rightIndex < rightLength){
        arr[originalIndex] = rightArray[rightIndex];
        originalIndex++;
        rightIndex++;
    }
    delete []leftArray;
    delete []rightArray;

}
void mergeSort(int arr[], int left, int right){
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right);
}
int main(){
    int arr1[] = {3, 5, 7, 9, 11, 1, 2, 28 , 9, 6, 7};
    int n1 = sizeof(arr1) / sizeof(int);
    mergeSort(arr1, 0, n1 - 1);
    for(int i = 0 ; i < n1 ; i++){
        cout << arr1[i] << " ";
    }
}