// Problem Link 1-https://leetcode.com/problems/delete-node-in-a-bst/
// Problem Link 2-https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
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
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            // 2 child
            if (root->left && root->right)
            {
                TreeNode *predecessor = root->left;
                while (predecessor->right)
                    predecessor = predecessor->right;
                root->val = predecessor->val;
                root->left = deleteNode(root->left, predecessor->val);
                return root;
            }
            // 1 child
            else if (root->left || root->right)
            {
                TreeNode *temp;
                if (root->left)
                {
                    temp = root->left;
                }
                else
                {
                    temp = root->right;
                }
                delete root;
                return temp;
            }
            // 0 child
            else
            {
                delete root;
                return NULL;
            }
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};