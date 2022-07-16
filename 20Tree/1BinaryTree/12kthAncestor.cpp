// Problem Link - https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/
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
void solve(Node *root, int &k , int &node, int &ans, bool &isFound){
    if(root == NULL){
        return;
    }
    if(root -> data == node){
        isFound = true;
        k--;
        return;
    }
    solve(root -> left , k, node, ans, isFound);
    if(isFound){
        if(k == 0){
            ans = root -> data;
        }
        k--;
        return;
    }
    solve(root -> right , k, node, ans, isFound);
    if(isFound){
        if(k == 0){
            ans = root -> data;
        }
        k--;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    bool isFound = false;
    solve(root , k ,  node, ans, isFound);
    return ans;
    
}