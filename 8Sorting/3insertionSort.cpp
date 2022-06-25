//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;

void insertionSort(int arr[], int size){
    int j;
    for(int i = 1; i< size ; i++){
        int temp = arr[i];
        for(j = i - 1 ; j >= 0 ; j--){
            if(arr[j] > temp){
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j + 1] = temp;
        
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
    insertionSort(arr, size);
    printArray(arr, size);
}