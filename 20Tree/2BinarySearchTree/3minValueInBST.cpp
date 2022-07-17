// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
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
int minValue(Node *root)
{
    // Code here
    if (!root)
        return -1;
    if (!root->left)
        return root->data;
    return minValue(root->left);
}
int main()
{
}