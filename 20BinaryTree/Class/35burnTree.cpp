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
// Approach 1 (MY approach) TC = O(N)
class Approach1
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
// Approach2(Sir Approach)
class Solution
{
private:
    void mappingChildToParent(Node *child, Node *parent, unordered_map<Node *, Node *> &mapping)
    {
        if (child == NULL)
            return;
        mapping[child] = parent;
        mappingChildToParent(child->left, child, mapping);
        mappingChildToParent(child->right, child, mapping);
    }

private:
    Node *findTarget(Node *root, int target)
    {
        if (root == NULL)
            return NULL;
        if (root->data == target)
            return root;
        Node *left = findTarget(root->left, target);
        if (left)
            return left;
        Node *right = findTarget(root->right, target);
        return right;
    }

public:
    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parent;
        mappingChildToParent(root, NULL, parent);
        unordered_map<Node *, bool> visited;
        Node *targetNode = findTarget(root, target);
        queue<Node *> q;
        int ans = 0;
        q.push(targetNode);
        visited[targetNode] = true;
        q.push(NULL);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (!front)
            {
                if (!q.empty())
                {
                    ans++;
                    q.push(NULL);
                }
            }
            else
            {
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (parent[front] && !visited[parent[front]])
                {
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
            }
        }
        return ans;
    }
};
