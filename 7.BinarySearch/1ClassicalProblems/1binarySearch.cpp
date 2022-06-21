//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int binarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        // int mid = left / 2 + right /2; -> it can lead to infinite loop hence don't use it
        int mid = left + (right - left) / 2;

        //element found
        if(arr[mid] == target){
            return mid;
        }

        //neglect right part
        else if(target < arr[mid]){
            right = mid - 1;
        }

        //neglect left part
        else{
            left = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {-1,0,3,5,9,12};
    int size = sizeof(arr) / sizeof(int);
    int target = 2;

    
    // cout << binary_search(arr, arr + size, target) << endl;



    cout  << binarySearch(arr, size, target ) ;

}