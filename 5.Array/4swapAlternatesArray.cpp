//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void swapAlternate(int arr[], int size){
    int i = 0;
    while(i + 1 < size){
        swap(arr[i], arr[i+1]);
        i += 2;
    }
}
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << endl;
    }
}
int main(){
    int arr[] = {3, 5, 7, 6, 9};
    swapAlternate(arr, 5);
    printArray(arr, 5);;
}
