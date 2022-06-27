// Problem Link -https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// O(n)
ListNode *removeZeroSumSublistsApproach2(ListNode *head)
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
        return removeZeroSumSublistsApproach2(temp->next);
    }
    head->next = removeZeroSumSublistsApproach2(head->next);
    return head;
}
// O(n^2)
ListNode *removeZeroSumSublistsApproach1(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tempDummy = dummy;
    dummy->next = head;
    unordered_map<int, ListNode *> ump;
    int sum = 0;
    while (tempDummy != NULL)
    {
        sum += tempDummy->val;
        ump[sum] = tempDummy;
        tempDummy = tempDummy->next;
    }
    tempDummy = dummy;
    sum = 0;
    while (tempDummy != NULL)
    {
        sum += tempDummy->val;
        if (ump[sum] != NULL)
            tempDummy->next = ump[sum]->next;
        else
        {
            tempDummy->next = NULL;
        }
        tempDummy = tempDummy->next;
    }
    return dummy->next;
}
