// Problem Link - https://practice.geeksforgeeks.org/problems/burning-tree/1
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
class Solution
{
private:
    bool findPathRootToTarget(Node *root, stack<Node *> &st, int target)
    {
        if (root == NULL)
            return false;
        st.push(root);
        if (root->data == target)
            return true;
        bool left = findPathRootToTarget(root->left, st, target);
        if (left)
            return true;
        bool right = findPathRootToTarget(root->right, st, target);
        if (right)
            return true;
        st.pop();
        return false;
    }

private:
    int height(Node *node)
    {
        // code here
        if (node == NULL)
            return -1;
        return max(1 + height(node->left), 1 + height(node->right));
    }

public:
    int minTime(Node *root, int target)
    {
        stack<Node *> path;
        findPathRootToTarget(root, path, target);
        Node *temp = path.top();
        path.pop();
        int ans = height(temp);
        int nodeTime = 1;
        while (!path.empty())
        {
            Node *top = path.top();
            path.pop();
            if (top->left != temp)
            {
                int currAns = nodeTime + 1 + height(top->left);
                nodeTime++;
                temp = top;
                ans = max(currAns, ans);
            }
            else
            {
                int currAns = nodeTime + 1 + height(top->right);
                nodeTime++;
                temp = top;
                ans = max(currAns, ans);
            }
        }
        return ans;
    }
};