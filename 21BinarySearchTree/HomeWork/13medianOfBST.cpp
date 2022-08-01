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

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// using storing inorder TC = O(N) SC = O(N)
float findMedian(struct Node *root)
{
    // Code here
    vector<int> inorder;
    while (root)
    {
        if (!root->left)
        {
            inorder.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *pred = root->left;
            while (pred->right && pred->right != root)
            {
                pred = pred->right;
            }
            if (pred->right)
            {
                pred->right = NULL;
                inorder.push_back(root->data);
                root = root->right;
            }
            else
            {
                pred->right = root;
                root = root->left;
            }
        }
    }
    int size = inorder.size();
    if (size & 1)
    {
        return inorder[size / 2];
    }
    else
    {
        return (inorder[size / 2] + inorder[size / 2 - 1]) / 2.0;
    }
}
// Using Morris Traversal TC = O(2N) Sc = O(1);
float findMedian(struct Node *root)
{
    Node *curr = root;
    int count = 0;
    while (curr)
    {
        if (!curr->left)
        {
            count++;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right)
            {
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
            else
            {
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    curr = root;
    if (count & 1)
    {
        int median = count / 2 + 1;
        count = 0;
        while (curr)
        {
            if (!curr->left)
            {
                count++;
                if (median == count)
                {
                    return curr->data;
                }
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                if (pred->right)
                {
                    pred->right = NULL;
                    count++;
                    if (median == count)
                    {
                        return curr->data;
                    }
                    curr = curr->right;
                }
                else
                {
                    pred->right = curr;
                    curr = curr->left;
                }
            }
        }
    }
    int firstMedian = count / 2;
    int first;
    int second;
    int secondMedian = firstMedian + 1;
    count = 0;
    while (curr)
    {
        if (!curr->left)
        {
            count++;
            if (count == firstMedian)
            {
                first = curr->data;
            }
            if (count == secondMedian)
            {
                second = curr->data;
            }
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right)
            {
                pred->right = NULL;
                count++;
                if (count == firstMedian)
                {
                    first = curr->data;
                }
                if (count == secondMedian)
                {
                    second = curr->data;
                }
                curr = curr->right;
            }
            else
            {
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    return (first + second) / 2.0;
}