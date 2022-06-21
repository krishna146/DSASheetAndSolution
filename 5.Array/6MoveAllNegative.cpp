//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void moveAllNegativeOneSide(int arr[], int size){
    int nextIndex = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < 0){
            swap(arr[i], arr[nextIndex]);
            nextIndex++;
        }
    }
}   
int main(){
    int arr[] = {2, 3, -1 , 8 , 9 , -11 , -3, -9};
    int size = sizeof(arr) / sizeof(int);
    moveAllNegativeOneSide(arr, size);
    printArray(arr, size);
    return 0;
}