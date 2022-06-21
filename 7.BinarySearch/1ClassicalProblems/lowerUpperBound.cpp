//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {3, 3, 4, 4, 4, 7, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    //lower bound points to the first element which has a value >= x;
    cout << lower_bound(arr, arr + size, 4) - arr << endl;


    //upper bound points to the first element in the array which has a value > x;
    cout<< upper_bound(arr, arr + size, 4) - arr << endl;
}