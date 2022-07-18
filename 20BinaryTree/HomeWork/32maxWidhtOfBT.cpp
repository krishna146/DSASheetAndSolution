//Problem Link - https://leetcode.com/problems/maximum-width-of-binary-tree/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
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
//Approach 1 : Since we r also pushing null nodes inside our queue hence we r getting TLE -> TC = O(2^No of Levels)
class Approach1 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, char>> q;
        char ch = 'N';
        q.push_back({root, ch});
        int ans = q.size();
        q.push_back({NULL, '$'});
        while(!q.empty()){
            pair<TreeNode*, char> front = q.front();
            q.pop_front();
            if(!front.first && front.second == '$'){
                while(!q.empty() && !q.back().first){
                   q.pop_back();
                }
                while(!q.empty() && !q.front().first){
                    q.pop_front();
                }
                if(!q.empty()){
                    int size = q.size();
                    ans = max(ans, size); 
                    q.push_back({NULL, '$'});
                }
               
            }else if(!front.first){
                q.push_back({NULL, ch});
                q.push_back({NULL, ch});
            }else{
                q.push_back({front.first -> left, ch});
                q.push_back({front.first -> right , ch});  
            }
        }
        return ans;
    }
};
//Approach2: here we will push ONLY NOT NULL inside our queue , TC = O(N)
class Approach2 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> q;
        q.push_back({root, 0});
        int ans = q.size();
        pair<TreeNode*, long long> separator = {NULL, -1};
        q.push_back(separator);
        while(!q.empty()){
           pair<TreeNode*, long long> front = q.front();
            q.pop_front();
            if(!front.first){

                if(!q.empty()){
                    int size = q.back().second - q.front().second + 1;
                    ans = max(ans, size);
                    q.push_back(separator);
                }
            }else{
                if(front.first -> left){
                    q.push_back({front.first -> left, 2*front.second + 1});
                }
                if(front.first -> right){
                    q.push_back({front.first -> right, 2*front.second + 2});
                }
            }
        }
        return ans;
    }
};