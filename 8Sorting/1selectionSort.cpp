//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int findMinmIndex(int arr[], int start , int size){
    int minIndex = start;
    for(int i = start + 1; i < size; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[], int size){
    for(int i = 0; i< size - 1; i++){
        int minIndex = findMinmIndex(arr, i, size);
        swap(arr[i], arr[minIndex]);
    }
}
void printArray(int arr[], int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {8, 3, 9, 1, 29, 33, 12, 18};
    int size = sizeof(arr) / sizeof(int);
    selectionSort(arr, size);
    printArray(arr, size);
}