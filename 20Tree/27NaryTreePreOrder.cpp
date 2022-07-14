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
private:
    vector<int> ans;

public:
    vector<int> preorder(Node *root)
    {
        if (!root)
        {
            return ans;
        }
        ans.push_back(root->val);
        for (auto el : root->children)
        {
            preorder(el);
        }
        return ans;
    }
};