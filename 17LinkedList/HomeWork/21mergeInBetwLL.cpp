//Problem Link - https://leetcode.com/problems/merge-in-between-linked-lists/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1 = list1;
        int temp = a - 1;
        while(temp--){
            temp1 = temp1 -> next;
        }
        ListNode* temp2 = temp1 -> next;
        temp1 -> next = list2;
        b = b - a + 1;
        while(b--){
            temp2 = temp2 -> next;
        }
        while(list2 -> next != NULL){
            list2 = list2 -> next;
        }
        list2 -> next = temp2;
        return list1;
        
    }
};
int main(){
    
}