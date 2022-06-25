//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
void twoSum(int arr[], int size, int ftarget){
    sort(arr, arr + size);
    int left = 0;
    int right = size - 1;
    for(int i = 0 ; i < size-2 ; i++){
        left = i + 1;
        right = size - 1;
        int target = ftarget - arr[i];
        while(left < right){
            if(arr[left] + arr[right] == target){
                cout << arr[i] << " ";
                cout << arr[left] << " " << arr[right];
                cout << endl;
                left++;
            }
            else if(arr[left] + arr[right] > target){
                right--;
            }
            else if(arr[left] + arr[right] < target){
                left++;
            }
        }
    }

}
int main(){
    int arr[] = {3, 1, 4, 5, 9, 13, 11};
    int size = sizeof(arr) / sizeof(int);
    int target = 23;
    twoSum(arr, size, target);
}