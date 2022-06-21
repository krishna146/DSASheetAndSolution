//Problem Link - https://practice.geeksforgeeks.org/problems/quick-sort/1/#
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int partitionSubbarao(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left;
    for(int j = i + 1 ; j <= right ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
        
    }
    swap(arr[left], arr[i]);
    return i;
}
int partitionLoveBabbar(int arr[], int left , int right){
    int pivot = arr[left];
    int count = 0;
    for(int i = left + 1 ; i <= right ; i++){
        if(arr[i] <= pivot)
            count++;
    }
    int pivotIndex = left + count;
    swap(arr[left], arr[pivotIndex]);
    while(left < pivotIndex && right > pivotIndex){
        if(arr[left] < pivot){
            left++;
        }
        else if(arr[right] > pivot)
        {
            right--;
        }
        else{
            swap(arr[left], arr[right]);
        }
    }
    return pivotIndex;

}

void quickSort(int arr[], int left, int right){
    if(left  >= right){
        return;
    }
    int pIndex = partitionSubbarao(arr, left, right);
    quickSort(arr, left ,pIndex -1);    
    quickSort(arr, pIndex + 1, right);

}
int main(){
    int arr1[] = {3, 5, 7,7, 9, 11, 1, 11, 2};
    int n1 = sizeof(arr1) / sizeof(int);
    quickSort(arr1, 0, n1 - 1);
    for(int i = 0 ; i < n1 ; i++){
        cout << arr1[i] << " ";
    }
}