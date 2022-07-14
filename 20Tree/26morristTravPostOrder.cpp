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
    vector<int> ans;

private:
    TreeNode *findPredecessor(TreeNode *root)
    {
        TreeNode *predecessor = root->right;
        while (predecessor->left && predecessor->left != root)
        {
            predecessor = predecessor->left;
        }
        return predecessor;
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        while (root)
        {
            if (!root->right)
            {
                ans.push_back(root->val);
                root = root->left;
            }
            else
            {
                TreeNode *pred = findPredecessor(root);
                if (pred->left)
                {
                    pred->left = NULL;
                    root = root->left;
                }
                else
                {
                    ans.push_back(root->val);
                    pred->left = root;
                    root = root->right;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}