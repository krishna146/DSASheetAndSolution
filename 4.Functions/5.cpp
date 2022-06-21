//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void printArrayElement(int *arr, int size){
    int count = 0;
    while(count <= size - 1){
        cout << arr[count] << " ";
        count += 1;
    }
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    printArrayElement(arr, 5);
}