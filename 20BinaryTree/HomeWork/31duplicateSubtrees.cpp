// Problem Link - https://leetcode.com/problems/find-duplicate-subtrees/
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
    unordered_map<string, int> ump;
    vector<TreeNode *> ans;

private:
    string solve(TreeNode *root)
    {
        if (root == NULL)
            return "N";
        string left = solve(root->left);
        string right = solve(root->right);
        string fString = left + " " + right + +" " + to_string(root->val);
        ump[fString]++;
        if (ump[fString] == 2)
            ans.push_back(root);
        return fString;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};