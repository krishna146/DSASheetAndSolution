// Problem Link - https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> ans;

private:
    TreeNode *findPredecessor(TreeNode *curr)
    {
        TreeNode *pred = curr->left;
        while (pred->right && pred->right != curr)
        {
            pred = pred->right;
        }
        return pred;
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        while (root)
        {
            if (!root->left)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode *pred = findPredecessor(root);
                if (pred->right)
                {
                    pred->right = NULL;
                    root = root->right;
                }
                else
                {
                    pred->right = root;
                    ans.push_back(root->val);
                    root = root->left;
                }
            }
        }
        return ans;
    }
};
int main()
{
}