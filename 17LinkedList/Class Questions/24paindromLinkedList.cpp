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

void reverse(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count & 1)
    {
        slow = slow->next;
    }
    prev->next = NULL;
    reverse(slow);
    while (slow != NULL)
    {
        if (head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
