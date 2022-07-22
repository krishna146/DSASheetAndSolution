// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
class Info{
    public:
    Node* root;
    int leftInd;
    int rightInd;
    Info(Node* root, int leftIndex, int rightIndex){
        this -> root = root;
        this -> leftInd = leftIndex;
        this -> rightInd = rightIndex;
    }
    
};
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    unordered_map<int, int> mapping;
    for(int i = 0 ; i < n ; i++){
        mapping[inorder[i]] = i;
    }
    queue<Info> q;
    int levelIndex = 0;
    Node* root = new Node(levelOrder[levelIndex++]);
    Info temp(root, iStart, iEnd);
    q.push(temp);
    while(!q.empty()){
        Info front = q.front();
        q.pop();
        Node* root = front.root;
        int iStart = front.leftInd;
        int iEnd = front.rightInd;
        int idx = mapping[root -> key];
        int leftIndex = mapping[levelOrder[levelIndex]];
        if(leftIndex >= iStart && leftIndex < idx){
            Node* leftNode = new Node(levelOrder[levelIndex++]);
            root -> left = leftNode;
            Info temp(leftNode, iStart, idx - 1);
            q.push(temp);
        }
        else{
            root -> left = nullptr;
        }
        int rightIndex = mapping[levelOrder[levelIndex]];
        if(rightIndex > idx &&  rightIndex <= iEnd){
            Node* rightNode = new Node(levelOrder[levelIndex++]);
            root -> right = rightNode;
            Info temp(rightNode, idx + 1, iEnd);
            q.push(temp);
        }
        else{
            root -> right = nullptr;

        }

    }
    return root;


}
int main()
{
    int inorder[] = {1, 0, 2};
    int levelOrder[] = {0, 1, 2};
    Node * root = buildTree(inorder, levelOrder, 0, 2, 3);
}