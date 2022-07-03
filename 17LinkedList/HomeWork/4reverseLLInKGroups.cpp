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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
            if (count == k)
            {
                break;
            }
        }
        if (count < k)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (count--)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
int main()
{
}