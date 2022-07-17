// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
bool findPathRootToTarget(Node *root, stack<Node *> &st, int target)
{
    if (root == NULL)
        return false;
    st.push(root);
    if (root->data == target)
        return true;
    bool left = findPathRootToTarget(root->left, st, target);
    if (left)
        return true;
    bool right = findPathRootToTarget(root->right, st, target);
    if (right)
        return true;
    st.pop();
    return false;
}
int main()
{
    Node* root = NULL;
    stack<Node *> path;
    int target = 3;
    findPathRootToTarget(root, path, target);
    while (!path.empty())
    {
        cout << path.top()->data << " ";
        path.pop();
    }
}