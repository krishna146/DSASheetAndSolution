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
void insertAtPosition(Node *&head, int pos, int data)
{

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    if (pos > length(head) + 1)
    {
        return;
    }
    Node *prev = head;
    while (pos > 2)
    {
        prev = prev->next;
        pos--;
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
    while (temp != NULL && temp->data != target)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    delete temp;
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
    insertAtPosition(head, 9, 100);
    traverse(head);
    deleteNode(head, 19);
    traverse(head);
    cout << length(head) << endl;
}