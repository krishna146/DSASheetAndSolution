// Problem Link -
/* By Krishna Kumar */
#include <iostream>
using namespace std;
// Function to sort a linked list of 0s, 1s and 2s.
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
Node *segregate(Node *head)
{

    // Add code here
    Node *zero = new Node(-1);
    Node *tempZero = zero;
    Node *one = new Node(-1);
    Node *tempOne = one;
    Node *two = new Node(-1);
    Node *tempTwo = two;
    while (head != NULL)
    {
        if (head->data == 0)
        {
            tempZero->next = head;
            tempZero = head;
            head = head->next;
            tempZero->next = NULL;
        }
        else if (head->data == 1)
        {
            tempOne->next = head;
            tempOne = head;
            head = head->next;
            tempOne->next = NULL;
        }
        else
        {
            tempTwo->next = head;
            tempTwo = head;
            head = head->next;
            tempTwo->next = NULL;
        }
    }
    zero = zero->next;
    one = one->next;
    two = two->next;
    if (zero == NULL)
    {
        if (one == NULL)
        {
            return two;
        }
        else
        {
            tempOne->next = two;
            return one;
        }
    }
    if (one == NULL)
    {
        tempZero->next = two;
        return zero;
    }
    tempZero->next = one;
    tempOne->next = two;
    return zero;
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
int main()
{
    Node *head = new Node(1);
    Node * tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    Node *ans = segregate(head);
    traverse(ans);
}