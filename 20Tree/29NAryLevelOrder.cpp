// Problem Link - https://leetcode.com/problems/n-ary-tree-preorder-traversal/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front == NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                temp.push_back(front->val);
                for (auto el : front->children)
                {
                    q.push(el);
                }
            }
        }
        return ans;
    }
};