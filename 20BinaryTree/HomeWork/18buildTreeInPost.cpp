// Problem Link - https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
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
int findTarget(int *inorder, int inStart, int inEnd, int target)
{
    for (int i = inStart; i < inEnd; i++)
    {
        if (inorder[i] == target)
            return i;
    }
}
Node *solve(int *inorder, int *postorder, int inStart, int inEnd, int &postEnd)
{
    if (postEnd == -1 || inEnd + 1 == inStart)
        return NULL;
    int data = postorder[postEnd--];
    Node *root = new Node(data);
    int index = findTarget(inorder, inStart, inEnd, data);
    root->right = solve(inorder, postorder, index + 1, inEnd, postEnd);
    root->left = solve(inorder, postorder, inStart, index - 1, postEnd);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int postEnd = n - 1;
    return solve(in, post, 0, n - 1, postEnd);
}