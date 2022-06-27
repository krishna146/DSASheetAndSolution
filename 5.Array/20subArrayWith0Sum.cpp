//problem link -> https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
#include <unordered_map>
#include <iostream>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    // Your code here
    unordered_map<int, bool> ump;
    int sum = 0;
    ump[sum] = true;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (ump[sum])
        {
            return true;
        }
        ump[sum] = true;
    }
    return false;
}