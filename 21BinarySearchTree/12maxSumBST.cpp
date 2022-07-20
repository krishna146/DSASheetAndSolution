// Problem Link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
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
class Info
{
public:
    int mini;
    int maxi;
    int sum;
    int isBST;

public:
    Info()
    {
        mini = INT_MAX;
        maxi = INT_MIN;
        sum = 0;
        isBST = true;
    }
};
class Solution
{
private:
    Info solve(TreeNode *root, int &maxSum)
    {
        if (root == NULL)
        {
            Info curr;
            return curr;
        }
        Info curr;
        Info leftSubtree = solve(root->left, maxSum);
        Info rightSubtree = solve(root->right, maxSum);
        if (leftSubtree.isBST && rightSubtree.isBST && root->val > leftSubtree.maxi && root->val < rightSubtree.mini)
        {
            curr.mini = min(root->val, leftSubtree.mini);
            curr.maxi = max(root->val, rightSubtree.maxi);
            curr.sum = root->val + leftSubtree.sum + rightSubtree.sum;
            maxSum = max(curr.sum, maxSum);
        }
        else
        {
            curr.isBST = false;
        }
        return curr;
    }

public:
    int maxSumBST(TreeNode *root)
    {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};