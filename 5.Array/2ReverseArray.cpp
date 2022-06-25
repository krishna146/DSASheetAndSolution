//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void reverseArray(int arr[], int size){
    int i = 0;
    int j = size - 1;
    while(i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << endl;
    }
}
int main(){
    int arr[] = {3, 5, 7, 6, 9, 2};
    reverseArray(arr, 6);
    printArray(arr, 6);;
}
