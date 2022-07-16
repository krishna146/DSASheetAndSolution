// Problem Link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/
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
        left = right = NULL;
    }
};
class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
            return 0;
        return max(1 + height(node->left), 1 + height(node->right));
    }
};
int main()
{
}