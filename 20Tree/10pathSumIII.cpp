//Problem Link - https://leetcode.com/problems/path-sum-iii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int count;
private:
    void solve(TreeNode* root, long long targetSum){
        if(root == NULL) return ;
        if(root -> val == targetSum){
            count++;
        }
        solve(root -> left, targetSum - root -> val);
        solve(root -> right, targetSum - root -> val) ;   
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        solve(root, targetSum);
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        return count;
       
    }
};
int main()
{
}