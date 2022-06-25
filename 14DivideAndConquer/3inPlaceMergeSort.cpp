//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
void merge(int arr[], int left, int right){
    int mid = left + (right - left)/2;
    int i = left;
    int j = mid + 1;
    while(i <= mid ){
        if(arr[i] <= arr[j]){
            i++;
        }
        else{
            swap(arr[i], arr[j]);
            i++;
            int tempIndex = j;
            for(int k = j + 1 ; k <= right ; k++){
                if(arr[k] < arr[tempIndex]){
                    swap(arr[tempIndex], arr[k]);
                    tempIndex++;
                }
                else{
                    break;
                }
            }
        }
    }

}
void mergeSort(int arr[], int left, int right){
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right);
}
int main(){
    int arr1[] = {3, 5, 7, 9, 11, 1, 2, 28 , 9, 6, 7};
    int n1 = sizeof(arr1) / sizeof(int);
    mergeSort(arr1, 0, n1 - 1);
    for(int i = 0 ; i < n1 ; i++){
        cout << arr1[i] << " ";
    }
}