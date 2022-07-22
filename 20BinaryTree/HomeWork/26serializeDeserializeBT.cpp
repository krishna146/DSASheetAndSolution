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
// using Preorder
class CodecApproach1
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
// Using Level Order
class CodecLevelOrder
{
private:
    string str;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str;
        if (root == NULL)
            return str;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == nullptr)
            {
                str += "N,";
            }
            else
            {
                str += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return str;
    }

public:
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode *> q;
        int index = 0;
        string temp;
        while (data[index] != ',')
        {
            temp.push_back(data[index]);
            index++;
        }
        index++;
        TreeNode *root = new TreeNode(stoi(temp));
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            string left, right;
            while (data[index] != ',')
            {
                left.push_back(data[index]);
                index++;
            }
            index++;
            while (data[index] != ',')
            {
                right.push_back(data[index]);
                index++;
            }
            index++;
            if (left == "N")
            {
                front->left = nullptr;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(left));
                front->left = leftNode;
                q.push(leftNode);
            }
            if (right == "N")
            {
                front->right = nullptr;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(right));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};