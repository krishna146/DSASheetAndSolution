// Problem Link - https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// for each value of BST 1 find target - root -> data value in BST 2 TC = O(N^2)
class Approach1
{
private:
    bool isTargetExists(Node *root, int target)
    {
        if (!root)
            return false;
        if (target == root->data)
            return true;
        if (target > root->data)
            return isTargetExists(root->right, target);
        return isTargetExists(root->left, target);
    }

public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        if (root1 == NULL)
            return 0;
        int target = x - root1->data;
        int flag = 0;
        if (target > 0)
            flag = isTargetExists(root2, target);
        return flag + countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
    }
};
class Approach2
{
private:
    unordered_map<int, bool> mapping;
    void hashBSTValue(Node *root)
    {
        if (!root)
            return;
        mapping[root->data] = true;
        hashBSTValue(root->left);
        hashBSTValue(root->right);
    }
    int countPair(Node *root, int &x)
    {
        if (!root)
            return 0;
        return mapping[x - root->data] + countPair(root->left, x) + countPair(root->right, x);
    }

public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        hashBSTValue(root2);
        return countPair(root1, x);
    }
};