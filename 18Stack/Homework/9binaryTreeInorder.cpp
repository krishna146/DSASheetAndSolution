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
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        while (1)
        {
            if (root == NULL && st.empty())
                break;
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            root = temp->right;
        }

        return ans;
    }
};
int main()
{
}