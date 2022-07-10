// Problem Link - https://leetcode.com/problems/path-sum/
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
    bool solve(TreeNode * left , TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(left == NULL || right == NULL){
            return false;
        }
        if(left -> val != right -> val) return false;
        bool isLeftSymmetric = solve(left -> left, right -> right);
        bool isRightSymmetric = solve(left -> right , right -> left);
        return isLeftSymmetric && isRightSymmetric;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return solve(root -> left , root -> right);
        
        
    }
};
int main()
{
}