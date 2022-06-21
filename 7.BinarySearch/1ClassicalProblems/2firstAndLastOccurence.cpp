//Problem Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int firstOccurence(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    int ans = -1;
    while(left <= right){
        int mid = left / 2 + right /2;
        //or , mid = left + (right - left) / 2

        //element found
        if(arr[mid] == target){
            ans = mid;
            right = mid - 1;
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
    return ans;;
}
int lastOccurence(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    int ans = -1;
    while(left <= right){
        int mid = left / 2 + right /2;
        //or , mid = left + (right - left) / 2

        //element found
        if(arr[mid] == target){
            ans = mid;
            left = mid + 1;
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
    return ans;;
}
int main(){
    int arr[] = {2, 3, 3, 3, 29 , 42, 91};
    int size = sizeof(arr) / sizeof(int);
    int target = 3;
    int leftMostIndex = firstOccurence(arr, size, target);
    int rightMostIndex = lastOccurence(arr, size, target);
    cout  << leftMostIndex  << endl;
    cout <<  rightMostIndex << endl; 
    cout<< "no of occurence : "<< rightMostIndex - leftMostIndex + 1<< endl;

}