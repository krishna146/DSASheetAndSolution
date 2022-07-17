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
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            // catch here
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}
Node *buildBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }
    else if (data > root->data)
    {
        root->right = buildBST(root->right, data);
    }
    else
    {
        root->left = buildBST(root->left, data);
    }
    return root;
}
void createBST(Node *&root)
{
    cout << " Enter the value of data for root Node" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        buildBST(root, data);
        cout << "Enter the data for next Node: " << endl;
        cin >> data;
    }
}
int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
}