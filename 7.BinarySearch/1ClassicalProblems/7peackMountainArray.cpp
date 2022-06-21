//Problem Link - https://leetcode.com/problems/peak-index-in-a-mountain-array/
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int findPeakElement(int arr[], int size){
        int left = 0, mid;
        int right = size - 1;
            mid = left + (right - left) / 2 ;
            if(mid != 0 && mid != size - 1){
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                    return mid;
                }
                else if(arr[mid] > arr[mid - 1]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else{
                 if(mid==0 && arr[mid]>arr[mid+1])
                    return mid;
                else
                    return mid+1;
                if(mid==size-1 && arr[mid]>arr[mid-1])
                    return mid;
                else
                    return mid-1;
                }
        return mid;
}
int main(){
    int arr[] = {3, 5, 3, 2, 0};
    int size = sizeof(arr) / sizeof(int);
    cout << findPeakElement(arr, size) << endl;;
    cout << arr[findPeakElement(arr, size)] << endl;

    
   

}