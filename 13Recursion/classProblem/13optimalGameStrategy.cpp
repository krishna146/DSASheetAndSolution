//Problem Link - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/
/* By Krishna Kumar */
#include<iostream>
#include<algorithm>
using namespace std;
int optimalGameStrategy(int arr[], int i , int j){
    if(i > j){
        return 0;
    }
    int choice1 = arr[i] + min(optimalGameStrategy(arr, i + 2, j), optimalGameStrategy(arr, i+ 1, j - 1));
    int choice2 = arr[j] + min(optimalGameStrategy(arr, i, j - 2), optimalGameStrategy(arr, i+ 1, j - 1));
    return max(choice1, choice2);
}
int main(){
    int arr[] = {5,3,7,10};
    cout << optimalGameStrategy(arr, 0, 3);
}