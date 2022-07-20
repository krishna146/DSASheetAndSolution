// Problem Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
//Recursive TC = O(N) SC = O(height)
class Approach1{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left , p, q);
        else if(p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right , p, q);
        else
            return root;
         
    }
};
//iterative TC = O(N) SC = O(1)
class Approach2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }

        return root;
    }
};