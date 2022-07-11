// Problem Link - https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#
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
void solve(Node *root, int slope, map<int, vector<int>> &ump)
{
    if (root == NULL)
    {
        return;
    }
    ump[slope].push_back(root->data);
    solve(root->left, slope + 1, ump);
    solve(root->right, slope, ump);
}

vector<int> diagonal(Node *root)
{
    // your code here
    map<int, vector<int>> ump;
    vector<int> ans;
    solve(root, 1, ump);
    for (auto vec : ump)
    {
        for (auto el : vec.second)
        {
            ans.push_back(el);
        }
    }
    return ans;
}
int main()
{
}