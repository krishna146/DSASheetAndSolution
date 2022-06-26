// Problem Link -https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
ListNode *removeZeroSumSublists(ListNode *head)
{
    if (head == NULL)
        return head;
    int sum = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        sum = sum + temp->val;
        if (sum == 0)
            break;
        temp = temp->next;
    }
    if (sum == 0)
    {
        return removeZeroSumSublists(temp->next);
    }
    head->next = removeZeroSumSublists(head->next);
    return head;
}