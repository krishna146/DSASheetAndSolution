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
    void solve(TreeNode *root, map<int, map<int, vector<int>>> &mp)
    {
        // queue<pair<Node, pair<row, col >>>
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            // pair<Node, pair<row, col>>
            pair<TreeNode *, pair<int, int>> front = q.front();
            q.pop();
            int col = front.second.second;
            int row = front.second.first;
            mp[col][row].push_back(front.first->val);
            if (front.first->left)
            {
                q.push({front.first->left, {row + 1, col - 1}});
            }
            if (front.first->right)
            {
                q.push({front.first->right, {row + 1, col + 1}});
            }
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        // map<col, map<row, vector<int>>>
        map<int, map<int, vector<int>>> mp;
        solve(root, mp);
        for (auto col : mp)
        {
            vector<int> temp;
            for (auto row : col.second)
            {
                sort(row.second.begin(), row.second.end());
                for (auto el : row.second)
                {
                    temp.push_back(el);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
}