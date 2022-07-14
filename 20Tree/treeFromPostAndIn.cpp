// Problem Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
class Solution {
private:
    unordered_map<int, int> ump;
private:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postIndex, int inStart, int inEnd){
        if(postIndex == -1 || inStart == inEnd + 1) return NULL;
        int val = postorder[postIndex--];
        int valIndex = ump[val];
        TreeNode* root = new TreeNode(val);
        root -> right = solve(inorder, postorder, postIndex, valIndex + 1, inEnd);
        root -> left = solve(inorder, postorder, postIndex, inStart, valIndex - 1);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0 ; i < inorder.size() ; i++){
            ump[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return solve(inorder, postorder, postIndex, 0, inorder.size() - 1);
     
        
    }
};
int main()
{
}