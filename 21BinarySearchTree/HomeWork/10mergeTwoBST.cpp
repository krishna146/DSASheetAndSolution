// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// TC = O(N1 + N2) SC = O(N1 + N2) 
class Approach1
{
private:
    vector<int> storeInorder(Node *root)
    {
        vector<int> inorder;
        while (root)
        {
            if (!root->left)
            {
                inorder.push_back(root->data);
                root = root->right;
            }
            else
            {
                Node *pred = root->left;
                while (pred->right && pred->right != root)
                {
                    pred = pred->right;
                }
                if (pred->right)
                {
                    inorder.push_back(root->data);
                    root = root->right;
                    pred->right = NULL;
                }
                else
                {
                    pred->right = root;
                    root = root->left;
                }
            }
        }
        return inorder;
    }

public:
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> ans;
        vector<int> inorder1 = storeInorder(root1);
        vector<int> inorder2 = storeInorder(root2);
        int i = 0, j = 0;
        while (i < inorder1.size() && j < inorder2.size())
        {
            if (inorder1[i] < inorder2[j])
            {
                ans.push_back(inorder1[i]);
                i++;
            }
            else
            {
                ans.push_back(inorder2[j]);
                j++;
            }
        }
        while (i < inorder1.size())
        {
            ans.push_back(inorder1[i]);
            i++;
        }
        while (j < inorder2.size())
        {
            ans.push_back(inorder2[j]);
            j++;
        }
        return ans;
    }
};

// TC = O(N1 + N2) Sc = O(H1 + H2);
class Approach2
{
public:
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> ans;
        stack<Node *> st1;
        stack<Node *> st2;
        while ((root1 || !st1.empty()) && (root2 || !st2.empty()))
        {
            while (root1)
            {
                st1.push(root1);
                root1 = root1->left;
            }
            while (root2)
            {
                st2.push(root2);
                root2 = root2->left;
            }
            Node *top1 = st1.top();
            Node *top2 = st2.top();
            if (top1->data < top2->data)
            {
                ans.push_back(top1->data);
                st1.pop();
                root1 = top1->right;
            }
            else
            {
                ans.push_back(top2->data);
                st2.pop();
                root2 = top2->right;
            }
        }
        while (root1 || !st1.empty())
        {
            while (root1)
            {
                st1.push(root1);
                root1 = root1->left;
            }
            Node *top1 = st1.top();
            st1.pop();
            ans.push_back(top1->data);
            root1 = top1->right;
        }
        while (root2 || !st2.empty())
        {
            while (root2)
            {
                st2.push(root2);
                root2 = root2->left;
            }
            Node *top2 = st2.top();
            st2.pop();
            ans.push_back(top2->data);
            root2 = top2->right;
        }
        return ans;
    }
};