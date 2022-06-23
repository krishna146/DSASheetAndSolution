// Problem Link -https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/* By Krishna Kumar */
#include <iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }
};
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->val == temp->val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}