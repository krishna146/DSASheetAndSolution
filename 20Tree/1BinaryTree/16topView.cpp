// Problem Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        //<col, firstTopElement>
        map<int, int> mp;
        //<Node, col>
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            pair<Node *, int> front = q.front();
            q.pop();
            int col = front.second;
            if (mp.find(col) == mp.end())
            {
                mp[col] = front.first->data;
            }
            if (front.first->left)
            {
                q.push({front.first->left, col - 1});
            }
            if (front.first->right)
            {
                q.push({front.first->right, col + 1});
            }
        }
        for (auto el : mp)
        {
            ans.push_back(el.second);
        }
        return ans;
    }
};
int main()
{
}