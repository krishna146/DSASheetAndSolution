// Problem Link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//level order traversal(each node visited two times) TC = O(2*N)
class Approcah1
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (!front)
            {
                if (!q.empty())
                {
                    Node *temp = q.front();
                    q.pop();
                    int size = q.size();
                    while (size--)
                    {
                        Node *tempNext = q.front();
                        q.pop();
                        temp->next = tempNext;
                        q.push(temp);
                        temp = tempNext;
                    }
                    q.push(temp);
                    q.push(NULL);
                }
            }
            else
            {
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        return root;
    }
};