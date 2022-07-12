// Problem Link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
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
class Solution {
private:
    void leftNode(Node* root, vector<int> &ans){
        if(!root) return;
        if(!root -> left  && !root -> right) return;
        ans.push_back(root -> data);
        if(root -> left)
            leftNode(root -> left, ans);
        else
            leftNode(root -> right, ans);
    }
private:
    void leafNode(Node* root, vector<int> &ans){
        if(!root) return;
        if(!root -> left && !root -> right){
            ans.push_back(root -> data);
            return;
        }
        leafNode(root -> left, ans);
        leafNode(root -> right, ans);
    }
private:
    void rightNode(Node* root, vector<int> &ans){
        if(root == NULL) return;
        if(!root -> left && !root -> right) return;
        if(root -> right){
            rightNode(root -> right, ans);
        }else{
            rightNode(root -> left, ans);
        }
        ans.push_back(root -> data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root -> data);
        leftNode(root -> left, ans);
        leafNode(root -> left, ans);
        leafNode(root -> right, ans);
        rightNode(root -> right , ans);
        return ans;
    }
};
int main()
{
}