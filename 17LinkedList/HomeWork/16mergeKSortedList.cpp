//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (right == NULL)
        {
            return left;
        }
        if (left == NULL)
        {
            return right;
        }
        ListNode *temp = new ListNode(-1);
        ListNode *tail = temp;
        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                tail = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                tail = right;
                right = right->next;
            }
        }
        if (left != NULL)
        {
            tail->next = left;
        }
        if (right != NULL)
        {
            tail->next = right;
        }
        return temp->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = NULL;
        for (int i = 0; i < lists.size(); i++)
        {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};
int main(){
    
}