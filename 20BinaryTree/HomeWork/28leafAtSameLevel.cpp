// Problem Link - https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
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
class Solution{
    private:
    int leafLevel = -1;
    private:
    bool solve(Node* root, int currLevel){
        if(root == NULL) return true;
        if(!root -> left && !root -> right){
            if(leafLevel == -1){
                leafLevel = currLevel;
                return true;
            }
            return leafLevel == currLevel;
        }
        return solve(root -> left, currLevel + 1) && solve(root -> right , currLevel + 1);
    }
    public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        return solve(root, 0);

    }
};