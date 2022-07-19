// Problem Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
class Solution
{
private:
    void solve(Node *root, int &k, int &ans)
    {
        if (root == NULL)
            return;
        solve(root->right, k, ans);
        k--;
        if (k == 0)
            ans = root->data;
        solve(root->left, k, ans);
    }

public:
    int kthLargest(Node *root, int K)
    {
        // Your code here
        int ans;
        solve(root, K, ans);
        return ans;
    }
};
int main()
{
}