//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
void dummy(int *arr, int size){
    cout << sizeof(arr) << endl;
}
int main(){
    // int a = 10;
    // int *p = &a;
    // cout << sizeof(p) << endl;
    // int *z = 0;
    // cout << z;
    int arr[] = {1, 2, 3};
    cout << arr << endl;
    cout << &arr << endl;
    for(int i = 0 ; i < 3 ; i++){
        // cout << *(arr + i) << endl;
        cout << i[arr] << endl;
    }
    cout << endl << endl << endl;
    dummy(arr, 3);




}