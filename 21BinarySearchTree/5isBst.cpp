// Problem Link - https://practice.geeksforgeeks.org/problems/check-for-bst/1
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
// store Inorder Traversal using morris or recursion and check it is sorted or not TC = O(N) SC = O(N)
class Approach1
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        // Your code here
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
        int temp = INT_MIN;
        for (auto el : inorder)
        {
            if (el > temp)
            {
                temp = el;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
//Morris Inorder Traversal and comparing with previoud element TC = O(N) SC = O(1)
class Approach2
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        // Your code here
        int prev = INT_MIN;
        while (root)
        {
            if (!root->left)
            {
                if (root->data < prev)
                    return false;
                else
                    prev = root->data;
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
                    if (root->data < prev)
                        return false;
                    else
                        prev = root->data;
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
        return true;
    }
};
//Recursion + comparting with previous element TC = O(N) SC = O(height)
class Approach3
{
    private:
    int prev = INT_MIN;
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        if(root == NULL){
            return true;
        }
        bool left = isBST(root -> left); 
        if(root -> data < prev) return false;
        else prev = root -> data;
        bool right = isBST(root -> right);
        return left && right;
        
    }
};
//Recursive + each node range TC = O(N) SC = O(N)
class Approach4
{
    private:
    bool solve(Node* root, int mini, int maxi){
        if(!root) return true;
        if(root -> data > mini && root -> data < maxi){
            bool left = solve(root -> left, mini, root -> data);
            bool right = solve(root -> right, root -> data, maxi);
            return left && right;
        }
        return false;
    }
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        
        return solve(root, INT_MIN, INT_MAX);
        
    }
};