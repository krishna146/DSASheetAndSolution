//Problem Link -  https://leetcode.com/problems/diameter-of-binary-tree/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
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
//approach1: O(N)
class Solution {
private:
   pair<int, int> diameter(TreeNode* root){
        if(root == NULL){
           return {0, 0};
        }
        pair<int, int> option1 = diameter(root -> left);
        pair<int, int> option2= diameter(root -> right);
        int leftHeight = option1.second;
        int rightHeight = option2.second;
        int option3 = leftHeight + rightHeight;       
        int currNodeHeight = 1 + max(leftHeight, rightHeight);
        return {max(option1.first, max(option2.first, option3)), currNodeHeight};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        pair<int,int> ans = diameter(root);
        return ans.first;
        
    }
};
int main(){
    
}