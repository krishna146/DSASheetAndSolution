// Problem Link - https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/#
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
// Approach 1 : Recursive Approach -> TC = O(N) SC = O(N)
class Approach1
{
private:
    pair<Node *, Node *> solve(Node *root)
    {
        if (!root->left && !root->right)
        {
            return {root, root};
        }
        bool isLeftExists = false;
        bool isRightExists = false;
        pair<Node *, Node *> left;
        pair<Node *, Node *> right;
        if (root->left)
        {
            isLeftExists = true;
            left = solve(root->left);
        }
        if (root->right)
        {
            isRightExists = true;
            right = solve(root->right);
        }
        if (isLeftExists && isRightExists)
        {
            root->left = NULL;
            root->right = left.first;
            left.second->right = right.first;
            return {root, right.second};
        }
        else if (isLeftExists)
        {
            root->left = NULL;
            root->right = left.first;
            return {root, left.second};
        }
        return {root, right.second};
    }

public:
    void flatten(Node *root)
    {
        // code here
        solve(root);
    }
};
// Approach 2: Morris Traversal -> TC = O(N) SC = O(1)
class Approach2
{
private:
    Node *findPredecessor(Node *root)
    {
        Node *predecessor = root->left;
        while (predecessor->right && predecessor->right != root)
        {
            predecessor = predecessor->right;
        }
        return predecessor;
    }

public:
    void flatten(Node *root)
    {
        while (root)
        {
            if (!root->left)
            {
                root = root->right;
            }
            else
            {
                Node *predecessor = findPredecessor(root);
                if (!predecessor->right)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    Node *temp = root->right;
                    root->right = root->left;
                    root->left = NULL;
                    predecessor->right = temp;
                    root = temp;
                }
            }
        }
    }
};
//Approach3: Morris Traversal -> TC = O(N) SC = O(1)
class Approach3
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr){
            if(curr -> left ){
                Node* pred = curr -> left;
                while(pred -> right){
                    pred = pred -> right;
                }
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
                
            }
            curr = curr -> right;
        }
        
    }
};
