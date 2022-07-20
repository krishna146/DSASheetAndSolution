// Problem Link 1 - https://leetcode.com/problems/serialize-and-deserialize-bst/
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
class Codec {
private:
    string str;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return str;
        }
        str += to_string(root -> val);
        if(root -> left){
            str.push_back(',');
            serialize(root -> left);
        }
        if(root -> right)
            str.push_back(',');
            serialize(root -> right);
        return str;
        
        
    }
private:
    TreeNode* solve(string &data, int mini, int maxi, int &index){
        if(index >= data.size()){
           return NULL;
        }
        string temp ;
        int tempIndex = index;
        while(data[tempIndex] != ',' && tempIndex < data.size()){
            temp += data[tempIndex++];
        }
        tempIndex++;
        int val = stoi(temp);
        if(val > mini && val < maxi){
            index = tempIndex;
            TreeNode* root = new TreeNode(val);
            root -> left = solve(data, mini, root -> val, index);
            root -> right = solve(data, root -> val, maxi, index);
            return root;
        }
        return NULL;
    
    }
public:
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        cout << data << " ";
        return solve(data, INT_MIN, INT_MAX, index);
    }
};