// Problem Link - https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1?page=1&curated[]=6&sortBy=accuracy
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
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        stack<Node *> st;
        while (!st.empty() || root)
        {
            while (root)
            {
                ans.push_back(root -> data);
                st.push(root);
                root = root->right;
            }
            Node *top = st.top();
            st.pop();
            root = top-> left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};