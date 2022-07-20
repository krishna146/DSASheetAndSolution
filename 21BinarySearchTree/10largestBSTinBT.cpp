// Problem Link1 - https://practice.geeksforgeeks.org/problems/largest-bst/1
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
class Info{
    public:
    int mini;
    int maxi;
    int size;
    bool isBST;
    public:
    Info(){
        this -> mini = INT_MAX;
        this -> maxi = INT_MIN;
        this -> size = 0;
        isBST = true;
    }
};
class Solution{
    private:
    Info solve(Node* root, int &ans){
        if(root == NULL){
            Info curr;
            return curr;
        }
        Info curr;
        Info leftSubtree= solve(root -> left, ans);
        Info rightSubtree = solve(root -> right, ans);
        if(leftSubtree.isBST && rightSubtree.isBST && root -> data > leftSubtree.maxi && root -> data < rightSubtree.mini){
            curr.size = 1 + leftSubtree.size + rightSubtree.size;
            curr.mini = min(leftSubtree.mini, root -> data);
            curr.maxi = max(rightSubtree.maxi, root -> data);
            ans = max(ans, curr.size);
        }else{
            curr.isBST =false;
        }
        return curr;
        
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = 0;
    	solve(root, ans);
    	return ans;
    	
    }
};