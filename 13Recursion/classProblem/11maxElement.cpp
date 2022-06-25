//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int getMax(int arr[], int size){
    if(size == 1) return arr[0];
    return max(arr[0], getMax(arr + 1, size - 1));
}
int main(){
    int arr[] = {11, 19, 38, 99, 89};
    int size = sizeof(arr) / sizeof(int);
    cout << getMax(arr, size);
}