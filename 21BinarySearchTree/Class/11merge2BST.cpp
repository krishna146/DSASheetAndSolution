// Problem Link - https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
class Solution
{
private:
    void solve(Node *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        solve(root->right, k, ans);
        k--;
        if (k == 0)
            ans = root->data;
        solve(root->left, k, ans);
    }

public:
    int kthLargest(Node *root, int K)
    {
        // Your code here
        int ans;
        solve(root, K, ans);
        return ans;
    }
};
class Solution
{
private:
    vector<int> storeInorder(Node *root)
    {
        vector<int> inorder;
        while (root)
        {
            if (!root->left)
            {
                inorder.push_back(root->data);
                root = root->right;
            }
            else
            {
                Node *pred = root->left;
                while (pred->right && pred->right != root)
                {
                    pred = pred->right;
                }
                if (pred->right)
                {
                    inorder.push_back(root->data);
                    root = root->right;
                    pred->right = NULL;
                }
                else
                {
                    pred->right = root;
                    root = root->left;
                }
            }
        }
        return inorder;
    }

public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> ans;
        vector<int> inorder1 = storeInorder(root1);
        vector<int> inorder2 = storeInorder(root2);
        int i = 0, j = 0;
        while (i < inorder1.size() && j < inorder2.size())
        {
            if (inorder1[i] < inorder2[j])
            {
                ans.push_back(inorder1[i]);
                i++;
            }
            else
            {
                ans.push_back(inorder2[j]);
                j++;
            }
        }
        while (i < inorder1.size())
        {
            ans.push_back(inorder1[i]);
            i++;
        }
        while (j < inorder2.size())
        {
            ans.push_back(inorder2[j]);
            j++;
        }
        return ans;
    }
};