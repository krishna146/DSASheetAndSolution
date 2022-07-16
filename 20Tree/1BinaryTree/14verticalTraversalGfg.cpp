// Problem Link - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Your code here
        map<int, vector<int>> mp;
        vector<int> ans;
        queue<pair<Node *, int>> q;
        q.push({root, 1});
        while (!q.empty())
        {
            pair<Node *, int> front = q.front();
            q.pop();
            mp[front.second].push_back(front.first->data);
            if (front.first->left)
            {
                q.push({front.first->left, front.second - 1});
            }
            if (front.first->right)
            {
                q.push({front.first->right, front.second + 1});
            }
        }
        for (auto vec : mp)
        {
            for (auto el : vec.second)
            {
                ans.push_back(el);
            }
        }
        return ans;
    }
};
int main()
{
}