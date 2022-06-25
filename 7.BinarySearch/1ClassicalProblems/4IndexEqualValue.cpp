//Problem Link - https://www.codingninjas.com/codestudio/problems/fixed-point_1264949
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int IndexEqualVaue(int arr[], int size){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        // int mid = left / 2 + right /2;
        int mid = left + (right - left) / 2;

        //element found
        if(arr[mid] == mid){
            return mid;
        }

        //neglect right part
        else if(arr[mid] > mid){
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
    int arr[] = {-11, -1, 2, 8, 9, 12, 13};
    int size = sizeof(arr) / sizeof(int);
    cout << IndexEqualVaue(arr, size) << endl;

    
   

}