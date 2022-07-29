// Problem Link -
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
    void storeInorder(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (root == NULL)
            return;
        storeInorder(root->left, arr);
        arr.push_back(root);
        storeInorder(root->right, arr);
    }

private:
    TreeNode *buildBalancedBST(vector<TreeNode *> &arr, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *root = arr[mid];
        root->left = buildBalancedBST(arr, left, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, right);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> arr;
        storeInorder(root, arr);
        return buildBalancedBST(arr, 0, arr.size() - 1);
    }
};