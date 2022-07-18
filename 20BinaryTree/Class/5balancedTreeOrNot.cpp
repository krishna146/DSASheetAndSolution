// Problem Link - https://leetcode.com/problems/balanced-binary-tree/
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
    pair<bool, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {true, 0};
        }
        pair<bool, int> isLeftBalanced = solve(root->left);
        pair<bool, int> isRightBalanced = solve(root->right);
        int leftHeight = isLeftBalanced.second;
        int rightHeight = isRightBalanced.second;
        int currNodeBalanced = abs(rightHeight - leftHeight) <= 1;
        int currNodeHeight = 1 + max(leftHeight, rightHeight);
        return {isLeftBalanced.first && isRightBalanced.first && currNodeBalanced, currNodeHeight};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return solve(root).first;
    }
};
int main()
{
}