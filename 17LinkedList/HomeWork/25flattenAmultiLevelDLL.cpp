//problem -> https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
 Node* flatten(Node* head) {
        Node *temp = head;
        while(temp != NULL){
            if(temp -> child != NULL){
                Node *childP = temp -> child;
                while(childP -> next != NULL){
                    childP = childP -> next;
                }
                temp -> child -> prev = temp;
                Node *forward = temp -> next;
                if(forward != NULL)
                    forward -> prev = childP;
                temp -> next = temp -> child;
                childP -> next = forward;
            }
            temp -> child = NULL;
            temp = temp -> next;
        }
        Node *temp1 = head;
        while(temp1 != NULL){
            cout << temp1 -> child ;
            temp1 = temp1 -> next;
        }
        return head;

    }