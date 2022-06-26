// Problem Link -https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
/* By Krishna Kumar */
#include <iostream>
#include<unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *bottom = NULL;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};
Node * mergeTwoSortedLL(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head2;
    }
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummy = new Node(-1);
    Node *tempDummy = dummy;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data > temp2 -> data){
            tempDummy -> bottom = temp2;
            tempDummy = temp2;
            temp2 = temp2 -> bottom;
        }
        else{
            tempDummy ->bottom = temp1;
            tempDummy = temp1;
            temp1 = temp1 -> bottom;
        }
    }
    if(temp1 != NULL){
        tempDummy -> bottom = temp1;
        tempDummy = temp1;
    }
    if(temp2 != NULL){
        tempDummy -> bottom = temp2;
        tempDummy = temp2;
    }
    return dummy -> bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root -> next == NULL ){
       return root;
   }
  
   root -> next = flatten(root -> next);
   return mergeTwoSortedLL(root , root -> next);

    
}