// Problem Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
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
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    if(ans.size() == level){
        ans.push_back(root -> data);
    }
    solve(root -> left, ans, level + 1);
    solve(root -> right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
}