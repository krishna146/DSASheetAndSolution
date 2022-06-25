//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int arr[], int size){
    bool flag = false;

   for(int i = 0 ; i < size - 1; i++){
       for(int j = 0 ; j < size - i - 1; j++){
           if(arr[j] > arr[j + 1]){
               swap(arr[j], arr[j-1]);
               flag = true;
           }
       }
       if(flag == false) return;
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
    bubbleSort(arr, size);
    printArray(arr, size);
}