// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Finding Middle In Linked list and making root;
//TC = O(N^2);
class Approach1
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (prev)
        {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        else
        {
            root->left = sortedListToBST(prev);
        }
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
//Storing Linked List Value in an Vector
//TC = O(N)
class Approach2 {
private:
    TreeNode* solve(vector<int> &arr, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = solve(arr, left, mid - 1);
        root -> right = solve(arr, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> arr;
        while(head){
            arr.push_back(head -> val);
            ListNode* prev = head;
            head = head -> next;
            delete prev;
        }
        return solve(arr, 0, arr.size() - 1);
    }
};