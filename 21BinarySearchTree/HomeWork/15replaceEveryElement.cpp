//Problem Link - https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int maxi = -1;
        for(int i = arr.size() - 1 ; i >= 0 ; i--){
            int temp = arr[i];
            arr[i] = maxi;
            maxi = max(temp, maxi);
        }
        return arr;
    }
};