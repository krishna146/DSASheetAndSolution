//Problem Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
bool subsetSumExists(int set[], int target ,int size){
    if(target == 0)
    {
        return true;
    }
    if(target < 0) return false;
    if(size == 0){
        return false;
    }
    return subsetSumExists(set + 1, target - set[0], size - 1) || subsetSumExists(set + 1, target, size - 1);
}
int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 37;
    int size = sizeof(set) / sizeof(set[0]);
    cout << subsetSumExists(set, sum, size);
}