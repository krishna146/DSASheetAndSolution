// Problem Link - https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
} ;
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;
    findPreSuc(root->left, pre, suc, key);
    if (root->key < key)
    {
        pre = root;
    }
    else
    {
        if (!suc && root->key > key)
        {
            suc = root;
        }
    }
    if (pre && suc)
        return;
    findPreSuc(root->right, pre, suc, key);
}