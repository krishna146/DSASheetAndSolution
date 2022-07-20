// Problem Link - https://www.codingninjas.com/codestudio/problems/_893049?leftPanelTab=0
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the number of nodes in the BST.
*/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Reach to the key.
    while (root->data != key)
    {
        if (key > root->data)
        {
            predecessor = root->data;
            root = root->right;
        }
        else
        {
            successor = root->data;
            root = root->left;
        }
    }

    BinaryTreeNode<int> *rightSubtree = root->right;

    while (rightSubtree != NULL)
    {
        successor = rightSubtree->data;
        rightSubtree = rightSubtree->left;
    }

    BinaryTreeNode<int> *leftSubtree = root->left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree->data;
        leftSubtree = leftSubtree->right;
    }

    return {predecessor, successor};
}