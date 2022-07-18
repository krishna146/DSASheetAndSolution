// Problem Link 1-https://leetcode.com/problems/search-in-a-binary-search-tree/
// Problem Link 2-https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1
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
//Approach 1: Recursive : SC = O(N) TC = O(N)
class Recursive
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)
            return root;
        return val > root->val ? searchBST(root->right, val) : searchBST(root->left, val);
    }
};
//Approach 2: Iterative : SC = O(1) TC = O(N)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root -> val == val) return root;
            else if(val > root -> val) root = root -> right;
            else root = root -> left;
        }
        return NULL;
    }
};

int main()
{
}