// Problem Link 1 - https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
// Problem Link 2 - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec
{
private:
    string str;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            str.push_back('N');
            return str;
        }
        str += to_string(root->val);
        str.push_back(',');
        serialize(root->left);
        str.push_back(',');
        serialize(root->right);
        return str;
    }

private:
    TreeNode *solve(string &data, int &index)
    {
        if (index == data.size() || data[index] == 'N')
        {
            index = index + 2;
            return nullptr;
        }
        int count = 0;
        string temp;
        while (data[index] != ',')
        {
            temp += data[index];
            index++;
        }
        index++;
        int val = stoi(temp);
        TreeNode *root = new TreeNode(val);
        root->left = solve(data, index);
        root->right = solve(data, index);
        return root;
    }

public:
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int index = 0;
        return solve(data, index);
    }
};
