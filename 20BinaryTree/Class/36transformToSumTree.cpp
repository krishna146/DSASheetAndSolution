// Problem Link - https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
public:
    int solve(Node *node)
    {
        if (node == NULL)
            return 0;
        int leftSum = solve(node->left);
        int rightSum = solve(node->right);
        int sum = leftSum + rightSum + node->data;
        node->data = leftSum + rightSum;
        return sum;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};