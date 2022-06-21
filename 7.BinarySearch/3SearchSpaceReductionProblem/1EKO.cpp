//Problem Link -https://www.spoj.com/problems/EKO/ 
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
bool isPossibleSolution(int arr[], int size, int currHeight, int target){
    int sum = 0;
    for(int i = 0; i < size; i++){
        int diff = 0;
        if(arr[i] > currHeight){
            diff = arr[i] - currHeight;
        }
        sum += diff;
    }
    return (sum >= target) ? true : false;
}
int getMaxHeightOfSaw(int arr[], int size, int target){
    int maxi = INT_MIN;
    for(int i = 0; i < size; i++){
        maxi = max(arr[i], maxi);
    }
    int down = 0;
    int ans ;
    int up = maxi;
    while(down <= up){
        int midHeight = down + (up - down) / 2;
        if(isPossibleSolution(arr, size, midHeight, target)){
            ans = midHeight;
            down = midHeight + 1;
        }
        else{
            up = midHeight - 1;
        }
    }
    return ans;
}
int main(){
    int n = 4;
    int target = 30;
    int arr[] = {15, 8, 18, 6};
    int size = sizeof(arr) / sizeof(int);
    cout << getMaxHeightOfSaw(arr,size, target);
}