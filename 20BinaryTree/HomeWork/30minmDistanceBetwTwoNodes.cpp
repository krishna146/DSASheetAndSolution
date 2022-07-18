// Problem Link -https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
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
class Solution
{
private:
    void mapChildToParent(Node *child, Node *par, unordered_map<Node *, Node *> &parent)
    {
        if (!child)
            return;
        parent[child] = par;
        mapChildToParent(child->left, child, parent);
        mapChildToParent(child->right, child, parent);
    }

private:
    Node *findFirstNode(Node *root, int first)
    {
        if (root == NULL)
            return root;
        if (root->data == first)
            return root;
        Node *left = findFirstNode(root->left, first);
        if (left)
            return left;
        Node *right = findFirstNode(root->right, first);
        return right;
    }

public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        unordered_map<Node *, Node *> parent;
        mapChildToParent(root, NULL, parent);
        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        Node *first = findFirstNode(root, a);
        int dist = 0;
        q.push(first);
        visited[first] = true;
        q.push(NULL);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (!front)
            {
                if (!q.empty())
                {
                    dist++;
                    q.push(NULL);
                }
            }
            else
            {
                if (front->data == b)
                    return dist;
                if (front->left && !visited[front->left])
                {
                    visited[front->left] = true;
                    q.push(front->left);
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (parent[front] && !visited[parent[front]])
                {
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
        }
        return dist;
    }
};