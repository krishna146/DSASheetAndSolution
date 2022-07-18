// Problem Link - https://practice.geeksforgeeks.org/problems/sum-tree/1#
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
private:
    pair<bool, int> solve(Node *root)
    {
        if (root == NULL)
        {
            return {true, 0};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {true, root->data};
        }
        pair<bool, int> isLeftAnsPossible = solve(root->left);
        pair<bool, int> isRightAnsPossible = solve(root->right);
        int sum = isLeftAnsPossible.second + isRightAnsPossible.second;
        bool currentNodeAnsPossible = sum == root->data;
        return {isLeftAnsPossible.first && isRightAnsPossible.first && currentNodeAnsPossible, sum + root->data};
    }

public:
    bool isSumTree(Node *root)
    {
        // Your code here
        return solve(root).first;
    }
};
int main()
{
}