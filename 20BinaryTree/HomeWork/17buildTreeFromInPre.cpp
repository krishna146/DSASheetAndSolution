// Problem Link - https://practice.geeksforgeeks.org/problems/construct-tree-1/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
private:
    int findIndex(int *inorder, int inStart, int inEnd, int target)
    {
        for (int i = inStart; i < inEnd; i++)
        {
            if (inorder[i] == target)
            {
                return i;
            }
        }
    }

private:
    Node *solve(int *inorder, int *preorder, int inStart, int inEnd, int &preStart, int &size)
    {
        if (preStart == size || inEnd + 1 == inStart)
            return NULL;
        int data = preorder[preStart++];
        Node *root = new Node(data);
        int index = findIndex(inorder, inStart, inEnd, data);
        root->left = solve(inorder, preorder, inStart, index - 1, preStart, size);
        root->right = solve(inorder, preorder, index + 1, inEnd, preStart, size);
        return root;
    }

public:
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int preStart = 0;
        return solve(in, pre, 0, n - 1, preStart, n);
    }
};