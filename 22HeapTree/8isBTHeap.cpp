// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Approach
{
private:
    int countNodes(Node *root)
    {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    bool isCompleteBT(Node *root, int index, int n)
    {
        if (root == nullptr)
            return true;
        if (index >= n)
            return false;
        return isCompleteBT(root->left, 2 * index + 1, n) && isCompleteBT(root->right, 2 * index + 2, n);
    }

private:
    bool heapOrNot(Node *root)
    {
        if (!root)
            return true;
        bool curr = false;
        if (root->left && root->right)
        {
            if (root->data > root->left->data && root->data > root->right->data)
            {
                curr = true;
            }
        }
        else if (root->left)
        {
            if (root->data > root->left->data)
            {
                curr = true;
            }
        }
        else
        {
            curr = true;
        }
        return curr && isHeap(root->left) && isHeap(root->right);
    }

public:
    bool isHeap(struct Node *root)
    {
        // code here
        int n = countNodes(root);
        if (isCompleteBT(root, 0, n))
        {
            return heapOrNot(root);
        }
        return false;
    }
};