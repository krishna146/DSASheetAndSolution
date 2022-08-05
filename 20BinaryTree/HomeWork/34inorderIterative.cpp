// Problem Link - https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1?page=1&curated[]=6&sortBy=accuracy
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        // code here
        vector<int> ans;
        stack<Node *> st;
        while (!st.empty() || root)
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            Node *top = st.top();
            st.pop();
            ans.push_back(top->data);
            root = top->right;
        }
        return ans;
    }
};