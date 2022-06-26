// Problem Link -https://leetcode.com/problems/rotate-list/
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
int getLength(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + getLength(head->next);
}
ListNode *rotateRight(ListNode *head, int k)
{
    int n = getLength(head);
    if (n == 0 || k == 0 || k % n == 0 || n == 1)
        return head;
    k = k % n;
    int temp = n - k - 1;
    ListNode *tempHead = head;
    while (temp--)
    {
        tempHead = tempHead->next;
    }
    ListNode *newHead = tempHead->next;
    tempHead->next = NULL;
    ListNode *newHeadTemp = newHead;
    while (newHeadTemp->next != NULL)
    {
        newHeadTemp = newHeadTemp->next;
    }
    newHeadTemp->next = head;
    return newHead;
}