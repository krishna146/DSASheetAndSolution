//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void rotate(int arr[], int n)
{
    int temp = arr[n - 1];
    for(int i = n - 1; i >=1 ; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    
}
void printArray(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {8, 9, 10, 13, 19, 25};
    int size = sizeof(arr) / sizeof(int);
    rotate(arr, size);
    printArray(arr, size);
}