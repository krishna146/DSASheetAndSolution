//Problem Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
private:
    TreeNode* solve(vector<int>& nums, int left , int right){
        if(left > right) return NULL; 
        int mid = left + (right - left) / 2;
        int data = nums[mid];
        TreeNode* root = new TreeNode(data);
        root -> left = solve(nums, left, mid - 1);
        root -> right = solve(nums, mid + 1, right);
        return root;
        
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};