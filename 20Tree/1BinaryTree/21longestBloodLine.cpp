// Problem Link - https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Solution
{
private:
    pair<int,int> solve(Node *root){
        if(root == NULL){
            return {0, 0};
        }
        pair<int, int> leftAns = solve(root -> left);
        pair<int, int> rightAns = solve(root -> right);
        int currNodeHt = 1 + max(leftAns.second, rightAns.second);
        if(leftAns.second > rightAns.second){
            return {leftAns.first + root -> data, currNodeHt};
        }else if(leftAns.second < rightAns.second){
            return {rightAns.first + root -> data, currNodeHt};
        }
        return {max(leftAns.first, rightAns.first) + root -> data, currNodeHt};
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        pair<int, int> ans = solve(root);
        return ans.first;
    }
};
int main()
{
}