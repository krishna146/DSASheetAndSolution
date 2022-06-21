// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include<string>
using namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(Node<string> *&tail, string data)
{
    Node<string> *temp = new Node<string>(data);
    if (tail == NULL)
    {
        tail = temp;
    }
    tail->next = temp;
    tail = temp;
}
Node<string> *reverse(Node<string> *&head)
{
    Node<string> *prev = NULL;
    Node<string> *current = head;
    while (current != NULL)
    {
        Node<string> *forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}
void traverse(Node<string> *&head)
{
    Node<string> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node<string> *b = new Node<string>("krishna");
    Node<string> *head = b;
    Node<string> *tail = b;
    insertAtTail(tail, "sushma");
    insertAtTail(tail, "nisha");
    insertAtTail(tail, "kajal");
    head = reverse(head);
    traverse(head);
}