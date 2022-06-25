// Problem Link -https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
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
Node *reverse(Node *head, int k)
{
    if (head == NULL)
        return head;
    Node *curr = head;
    Node *prev = NULL;
    int count = k;
    while (curr != NULL && count--)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head->next = reverse(curr, k);
    return prev;
}
int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    insertAtTail(tail, 3);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 8);
    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    traverse(head);
    Node *ans = reverse(head, 2);
    traverse(ans);
}