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
int main(){
    int arr[10] = {3, 5, 7, 6, 9, 2};
    printArray(arr, 10);
    int newarr[10] = {1};
    printArray(newarr, 10);
    int arr2[] = {1, 3, 3 , 38 , 99};
    int sizeofArr2 = sizeof(arr2) / sizeof(int);
    cout << sizeofArr2 << endl;


    int z = 10;
    int *a = &z;
    cout << sizeof(a) << endl;

}
