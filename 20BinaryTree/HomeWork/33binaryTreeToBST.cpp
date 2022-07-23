// Problem Link - https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


    class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        vector<int> inorder;
        Node *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                if (pred->right)
                {
                    inorder.push_back(curr->data);
                    pred->right = NULL;
                    curr = curr->right;
                }
                else
                {
                    pred->right = curr;
                    curr = curr->left;
                }
            }
        }
        sort(inorder.begin(), inorder.end());
        int index = 0;
        curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                curr->data = inorder[index++];
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                if (pred->right)
                {
                    curr->data = inorder[index++];
                    pred->right = NULL;
                    curr = curr->right;
                }
                else
                {
                    pred->right = curr;
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};