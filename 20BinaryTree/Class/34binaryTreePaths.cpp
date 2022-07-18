// Problem Link - https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> ans;

private:
    void solve(TreeNode *root, string temp)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            temp += to_string(root->val);
            ans.push_back(temp);
        }
        temp = temp + to_string(root->val) + "->";
        solve(root->left, temp);
        solve(root->right, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        solve(root, "");
        return ans;
    }
};
int main()
{
}