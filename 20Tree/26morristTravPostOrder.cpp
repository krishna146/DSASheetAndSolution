// Problem Link - https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    TreeNode *findPredecessor(TreeNode *root)
    {
        TreeNode *predecessor = root->left;
        while (predecessor->right && predecessor->right != root)
        {
            predecessor = predecessor->right;
        }
        return predecessor;
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            if (!root->left)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode *predecessor = findPredecessor(root);
                if (!predecessor->right)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    predecessor->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};
int main()
{
}