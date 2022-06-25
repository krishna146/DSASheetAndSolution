//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
bool linearSearch(int *arr, int key, int size){
    for(int i = 0; i < size ; i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}
int main(){
    int arr[10] = {8, 9 , 13 , 18, 39, 3, 9 , 4 , 12, 10};
    int key;
    cin >> key;
    cout << linearSearch(arr, key, 10);
}