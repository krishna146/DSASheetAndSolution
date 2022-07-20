// Problem Link -
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

Node *solve(int *postorder, int mini, int maxi, int &index)
{
    if (index == -1)
        return NULL;
    if (postorder[index] > mini && postorder[index] < maxi)
    {
        Node *node = new Node(postorder[index--]);
        node->right = solve(postorder, node->data, maxi, index);
        node->left = solve(postorder, mini, node->data, index);
        return node;
    }
    return NULL;
}
Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return solve(post, INT_MIN, INT_MAX, index);
}