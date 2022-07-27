// Problem Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
class Solution
{
private:
    TreeNode *solve(vector<int> &preorder, int &index, int mini, int maxi)
    {
        if (index == preorder.size())
        {
            return NULL;
        }
        if (preorder[index] > mini && preorder[index] < maxi)
        {

            TreeNode *root = new TreeNode(preorder[index++]);
            root->left = solve(preorder, index, mini, root->val);
            root->right = solve(preorder, index, root->val, maxi);
            return root;
        }
        return NULL;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return solve(preorder, index, INT_MIN, INT_MAX);
    }
};