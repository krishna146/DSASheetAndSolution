// Problem Link1 - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/
//Problem Link2 - https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
Node *buildTree()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    Node *newNode = new Node(data);
    cout << "Enter the value for left child of " << data << endl;
    newNode->left = buildTree();
    cout << "Enter the value for right child of " << data << endl;
    newNode->right = buildTree();
    return newNode;
}
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
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
            //catch here
            if(!q.empty())
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
int height(Node *root){
    if(root == NULL) return -1;
    return max(1 + height(root -> left) , 1 + height(root -> right));
}

int main()
{
    Node *root = NULL;
    cout << "enter the value of root: " << endl;
    root = buildTree();
    cout << "printing pre order: " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "printing inorder: " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "printing postorder: " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "printing Level Order: " << endl;
    levelOrderTraversal(root);
    cout << "height of tree : " << height(root) << endl;
}