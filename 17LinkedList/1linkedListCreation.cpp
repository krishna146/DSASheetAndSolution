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
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
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
void insertAtTail(Node * &tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&head, int pos, int data)
{
    // TODO:tail updation , while inserting at the end
    // TODO :validate that position at max 1 more length greater than current length
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *prev = head;
    int t = pos - 2;
    while (t--)
    {
        prev = prev->next;
    }
    Node *newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}
void deleteNode(Node *&head, int target)
{
    // ToDo : tail updation
    if (head == NULL)
    {
        return;
    }
    if (head->data == target)
    {
        Node *temp = head;
        temp->next = NULL;
        delete temp;
        head = head->next;
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->data != target && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}
int length(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        Node *forward = current->next;
        current->next = prev;
        prev = current;
    }
    return prev;
}
int main()
{
    Node *b = new Node(3);
    Node *head = b;
    Node *tail = b;
    insertAtTail(tail, 19);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    insertAtHead(head, 9);
    insertAtHead(head, 11);
    traverse(head);
    insertAtPosition(head, 1, 12);
    traverse(head);
    insertAtPosition(head, 2, 100);
    traverse(head);
    insertAtPosition(head, 11, 1000);
    traverse(head);
    deleteNode(head, 19);
    traverse(head);
    cout << length(head) << endl;
    head = reverse(head);
    traverse(head);
}