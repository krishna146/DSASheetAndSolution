//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
bool isSorted(int arr[], int size){
    if(size == 0 || size == 1) return true;
    if(arr[0] < arr[1]){
        return isSorted(arr + 1, size - 1);
    }
    return false;

}
int main(){
    int arr[7] = {3, 99, 31, 55, 66, 78, 89};
    int size = sizeof(arr) / sizeof(int);
    cout << isSorted(arr, size) << endl;
}