// Problem Link -https://leetcode.com/problems/add-two-numbers/
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
ListNode *add(ListNode *l1, ListNode *l2, int carry)
{
    if (l1 == NULL && l2 == NULL)
    {
        if (carry == 0)
            return NULL;
        ListNode *ans = new ListNode(carry);

        return ans;
    }
    if (l1 == NULL)
    {
        int sum = l2->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *ans = l2;
        ans->val = digit;
        l2 = l2->next;
        ans->next = add(l1, l2, carry);
        return ans;
    }
    if (l2 == NULL)
    {
        int sum = l1->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *ans = l1;
        ans->val = digit;
        l1 = l1->next;
        ans->next = add(l1, l2, carry);
        return ans;
    }
    int sum = l1->val + l2->val + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ListNode *ans = l1;
    ans->val = digit;
    l1 = l1->next;
    l2 = l2->next;
    ans->next = add(l1, l2, carry);
    return ans;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return add(l1, l2, 0);
}