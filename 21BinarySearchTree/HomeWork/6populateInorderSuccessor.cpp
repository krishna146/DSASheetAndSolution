// Problem Link - https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
class Solution
{
private:
    void solve(Node *root, Node *&prev)
    {
        if (!root)
            return;
        solve(root->left, prev);
        if (prev)
        {
            prev->next = root;
        }
        prev = root;
        solve(root->right, prev);
    }

public:
    void populateNext(Node *root)
    {
        // code here
        Node *prev = NULL;
        solve(root, prev);
    }
};