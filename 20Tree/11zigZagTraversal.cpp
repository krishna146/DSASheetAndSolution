// Problem Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        bool isOddLevel = true;
        queue<TreeNode *> q;
        stack<int> st;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(isOddLevel){
                if(!front){
                    ans.push_back(temp);
                    temp.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                    isOddLevel = false;
                    continue;
                }
                else{
                    temp.push_back(front -> val);
                }
            }
            else{
                if(!front){
                    while(!st.empty()){
                        temp.push_back(st.top());
                        st.pop();
                    }
                    ans.push_back(temp);
                    temp.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                    isOddLevel = true;
                    continue;
                }else{
                    st.push(front -> val);
                }
            }
            if(front -> left){
                q.push(front -> left);
            }
            if(front -> right){
                q.push(front -> right);
            }
        }
        
        return ans;
    }
};
int main()
{
}