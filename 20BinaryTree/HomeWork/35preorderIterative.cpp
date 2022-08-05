// Problem Link - https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1?page=1&curated[]=6&sortBy=accuracy
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
class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        // code here
        vector<int> ans;
        stack<Node *> st;
        while (!st.empty() || root)
        {
            while (root)
            {
                ans.push_back(root -> data);
                st.push(root);
                root = root->left;
            }
            Node *top = st.top();
            st.pop();
            root = top->right;
        }
        return ans;
    }
};