//Problem Link - https://www.geeksforgeeks.org/counting-inversions/ 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int modifiedMerge(int arr[], int left, int right){
    int mid = left + (right - left)/2;
    int lLength = mid - left + 1;
    int rLength = right - mid;
    int *leftArray = new int[lLength];
    int *rightArray = new int[rLength];
    int originalIndex = left;
    for(int i = 0 ; i < lLength ; i++){
        leftArray[i] = arr[originalIndex];
        originalIndex++;
    }
    originalIndex = mid + 1;
    for(int i = 0 ; i < rLength ; i++){
        rightArray[i] = arr[originalIndex];
        originalIndex++;
    }
    int lIndex = 0;
    int rIndex = 0;
    originalIndex = left;
    int count = 0;
    while(lIndex < lLength && rIndex < rLength){
        if(leftArray[lIndex] <= rightArray[rIndex]){
            arr[originalIndex] = leftArray[lIndex];
            originalIndex++;
            lIndex++;
        }else{
            count = count +  (lLength - 1 - lIndex + 1);
            arr[originalIndex] = rightArray[rIndex];
            originalIndex++;
            rIndex++;
        }
    }
    while(lIndex < lLength){
        arr[originalIndex] = leftArray[lIndex];
        lIndex++;
        originalIndex++;
    }
    while(rIndex < rLength){
        arr[originalIndex] = rightArray[rIndex];
        originalIndex++;
        rIndex++;
    }
    delete []leftArray;
    delete []rightArray;
    return count;
}
int mergeSort(int arr[], int left, int right){
    if(left >= right){
        return 0;
    }
    int mid = left + (right - left) / 2;
    int leftCount = mergeSort(arr, left, mid);
    int rightCount = mergeSort(arr, mid + 1, right);
    int cInversion= leftCount + rightCount + modifiedMerge(arr, left , right);
    return cInversion;
}
int main(){
    int arr1[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    int n1 = sizeof(arr1) / sizeof(int);
    cout << mergeSort(arr1, 0, n1 - 1) << endl;
        for(int i = 0 ; i < n1 ; i++){
        cout << arr1[i] << " ";
    }
    
}