// Problem Link - https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
};

    /*You are required to complete below method */
    bool solve(Node *root, int mini, int maxi)
{
    if (!root)
        return false;
    if (mini == 1 && maxi - mini == 1)
        return true;
    if (mini != 1 && maxi - mini == 2)
        return true;
    bool left = solve(root->left, mini, root->data);
    bool right = solve(root->right, root->data, maxi);
    return left || right;
}
bool isDeadEnd(Node *root)
{
    // Your code here
    return solve(root, 1, 200);
}