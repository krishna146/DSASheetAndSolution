//Problem Link - https://leetcode.com/problems/add-two-numbers/
/* By Krishna Kumar */
#include<iostream>
using namespace std;
struct Node{
    int val;
    struct Node *next;
};
typedef struct Node ListNode;
ListNode* add(ListNode *l1 , ListNode * l2, int carry){
    if(l1 == NULL && l2 == NULL){
        if(carry == 0)
            return NULL;
        ListNode *ans = new ListNode;
        ans -> val = carry;
        ans -> next = NULL;
        return ans;
    }
    if(l1 == NULL){
        int sum = l2 ->val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *ans = l2;
        ans -> val = digit;
        l2 = l2 -> next;
        ans -> next = add(l1, l2, carry);
        return ans;
    }
    if(l2 == NULL){
        int sum = l1 -> val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode * ans = l1 ;
        ans -> val = digit;
        l1 = l1 -> next;
        ans -> next = add(l1, l2, carry);
        return ans;
    }
    int sum = l1 -> val + l2 -> val + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ListNode *ans = l1 ;
    ans -> val = digit;
    l1 = l1 -> next;
    l2 = l2 -> next;
    ans -> next = add(l1, l2, carry);
    return ans;
    
}
int main(){
    ListNode *l1 = new ListNode;
    l1 -> val = 2;
    ListNode *temp = new ListNode;
    temp -> val =4;
    l1 -> next = temp;
    temp = new ListNode;
    temp ->val = 3;
    l1 -> next -> next = temp;
    l1 -> next -> next -> next = NULL;
    ListNode *l2 = new ListNode;
    l2 -> val = 5;
    temp = new ListNode;
    temp -> val = 6;
    l2 -> next = temp;
    temp = new ListNode;
    temp ->val = 4;
    l2 -> next -> next = temp;
    l2 -> next -> next -> next = NULL;
    ListNode * ans = add(l1, l2, 0);
    while(ans != NULL){
        cout << ans ->val;
        ans = ans -> next;
    }

}