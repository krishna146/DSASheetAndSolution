// Problem Link -https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
/* By Krishna Kumar */
#include <iostream>
#include<unordered_map>
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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, bool> visited;
    while (headA != NULL)
    {
        visited[headA] = true;
        headA = headA->next;
    }
    while (headB != NULL)
    {
        if (visited[headB])
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}