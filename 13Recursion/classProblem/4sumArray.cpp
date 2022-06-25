//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int sumOfArray(int *arr, int size){
    if(size == 0) return 0;
    return arr[0] + sumOfArray(arr + 1, size - 1);
}
int main(){
    int arr[] = {3, 99, 31, 55, 66, 78, 89};
    int size = sizeof(arr) / sizeof(int);
    cout << sumOfArray(arr, size) << endl; 
}