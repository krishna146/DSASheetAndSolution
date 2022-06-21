//Problem Link - https://leetcode.com/problems/search-a-2d-matrix/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
bool binarySearch(int arr[][3], int row , int col, int intendedRow, int target){

    int start = 0;
    int end = col -1 ;
    while(start <= end){
        int mid = start  + (end - start)/2;
        if(arr[intendedRow][mid] == target)
        {
            return true;
        }
        else if(target > arr[intendedRow][mid]) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return true;
}
bool findElement(int arr[][3], int row, int col, int target){

    //find row
    int start = 0;
    int end = row - 1;
    int intendedRow ;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(target >= arr[mid][0] && target <= arr[mid][col - 1]){
            bool ans = binarySearch(arr, row, col, mid, target);
            return ans;
        }
        //check upper part
        else if(target > arr[mid][col-1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
   
    return false;

}
//driver code
int main(){
    int arr[][3]= {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int row = 3;
    int col = 3;
    int target = 14;
    cout << findElement(arr, row, col, target) << endl;


}