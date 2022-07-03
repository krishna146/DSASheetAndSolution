// Problem Link - https://leetcode.com/problems/merge-nodes-in-between-zeros/discuss/1784898/C%2B%2B-or-Easy-to-understand-or-Linked-List
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>

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
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp = head;

        while (head != NULL)
        {
            if (head->val == 0)
            {
                ListNode *temp = head->next;
                int sum = 0;
                while (temp->val != 0)
                {
                    sum += temp->val;
                    temp = temp->next;
                }
                head->val = sum;
                if (temp->next == NULL)
                {
                    head->next = NULL;
                }
                else
                {
                    head->next = temp;
                }
            }
            head = head->next;
        }
        return temp;
    }
};
using namespace std;
int main()
{
}