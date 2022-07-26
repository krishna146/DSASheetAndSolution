// Problem Link - https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
}; 
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    BinaryTreeNode *curr = root;
    vector<int> inorder;
    while (curr)
    {
        if (!curr->left)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            BinaryTreeNode *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right)
            {
                pred->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    curr = root;
    int index = 0;
    while (curr)
    {
        if (!curr->left)
        {
            curr->data = inorder[index++];
            curr = curr->right;
        }
        else
        {
            BinaryTreeNode *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right)
            {
                pred->right = NULL;
                curr = curr->right;
            }
            else
            {
                pred->right = curr;
                curr->data = inorder[index++];
                curr = curr->left;
            }
        }
    }
    return root;
}