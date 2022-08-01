// Problem Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
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
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root -> left;
            }
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top -> val);
            root = top -> right;
            
        }

        return ans;
    }
};
