// Problem Link -
/* By Krishna Kumar */
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void traverse(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        tail = temp;
    }
    tail->next = temp;
    tail = temp;
}
Node * mergeTwoSortedLL(Node* &head1, Node* &head2){
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
            tempDummy -> next = temp2;
            tempDummy = temp2;
            temp2 = temp2 -> next;
        }
        else{
            tempDummy ->next = temp1;
            tempDummy = temp1;
            temp1 = temp1 -> next;
        }
    }
    if(temp1 != NULL){
        tempDummy -> next = temp1;
    }
    if(temp2 != NULL){
        tempDummy -> next = temp2;
    }
    return dummy -> next;
}
int main()
{
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);

    cout << "Priting first list " << endl;
    traverse(head1);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 8);
    insertAtTail(tail2, 10);

    traverse(head2);

    Node *head = mergeTwoSortedLL(head1, head2);
    traverse(head);
}