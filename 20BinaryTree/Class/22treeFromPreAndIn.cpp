// Problem Link1 - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Problem Link2 - https://practice.geeksforgeeks.org/problems/construct-tree-1/1
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
    unordered_map<int, int> ump;

private:
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd)
    {
        if (preIndex == preorder.size() || inStart == inEnd + 1)
            return NULL;
        int val = preorder[preIndex++];
        TreeNode *node = new TreeNode(val);
        int valIndex = ump[val];
        node->left = solve(preorder, inorder, preIndex, inStart, valIndex - 1);
        node->right = solve(preorder, inorder, preIndex, valIndex + 1, inEnd);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            ump[inorder[i]] = i;
        }
        int preIndex = 0;
        return solve(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
};
int main()
{
}