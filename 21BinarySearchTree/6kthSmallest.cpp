// Problem Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//* By Krishna Kumar */
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
// Morris inorder traversal : TC = O(N) SC = O(1)
class Approach1
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans;
        while (root)
        {
            if (!root->left)
            {
                count++;
                if (count == k)
                    ans = root->val;
                root = root->right;
            }
            else
            {
                TreeNode *pred = root->left;
                while (pred->right && pred->right != root)
                    pred = pred->right;
                if (pred->right)
                {
                    count++;
                    pred->right = NULL;
                    if (count == k)
                        ans = root->val;
                    root = root->right;
                }
                else
                {
                    pred->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};
//Recursive TC = O(N) SC = O(height)
class Approach2
{

private:
    void solve(TreeNode *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, k, ans);
        k--;
        if (k == 0)
            ans = root->val;
        solve(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        solve(root, k, ans);
        return ans;
    }
};