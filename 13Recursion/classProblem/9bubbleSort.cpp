//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void bubbleSort(int arr[],int left, int right){
    bool flag = false;
    if(right == -1) return;
    if(left == right){
        bubbleSort(arr, 0, right - 1);
        return;
    }
    if(arr[left] > arr[left + 1]) swap(arr[left], arr[left + 1]);
    bubbleSort(arr, left + 1, right);

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
    bubbleSort(arr, 0, size - 1);
    printArray(arr, size);
}