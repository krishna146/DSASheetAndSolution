// Problem Link - https://leetcode.com/problems/path-sum-iii/
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
    int count;

private:
    void solve(TreeNode *root, int &targetSum, unordered_map<long long, int> &ump, long long &pSum)
    {
        if (root == NULL)
            return;
        pSum += root->val;
        if (ump.find(pSum - targetSum) != ump.end())
        {
            count += ump[pSum - targetSum];
        }
        ump[pSum]++;
        solve(root->left, targetSum, ump, pSum);
        solve(root->right, targetSum, ump, pSum);
        ump[pSum]--;
        pSum -= root->val;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> ump;
        ump[0] = 1;
        long long pSum = 0;
        solve(root, targetSum, ump, pSum);
        return count;
    }
};
int main()
{
}