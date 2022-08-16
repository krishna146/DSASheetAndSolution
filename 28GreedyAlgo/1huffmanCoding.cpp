// Problem Link - https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int freq;
    Node *left;
    Node *right;
    Node(int freq)
    {
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};
class Solution
{
private:
    void encodeChar(vector<string> &ans, Node *root, string &temp)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back('0');
        encodeChar(ans, root->left, temp);
        temp.pop_back();
        temp.push_back('1');
        encodeChar(ans, root->right, temp);
        temp.pop_back();
    }

public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        vector<string> ans;
        string temp;
        priority_queue<Node *, vector<Node *>, cmp> minHeap;
        for (int i = 0; i < S.size(); i++)
        {
            Node *node = new Node(f[i]);
            minHeap.push(node);
        }
        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();
            Node *right = minHeap.top();
            minHeap.pop();
            Node *parent = new Node(left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            minHeap.push(parent);
        }
        encodeChar(ans, minHeap.top(), temp);
        return ans;
    }
};