// Problem Link -https://leetcode.com/problems/middle-of-the-linked-list/submissions/
/* By Krishna Kumar */
#include <iostream>
#include <string>
using namespace std;
template <typename T>
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
Node<string>* findMiddle(Node<string> * &head){
    Node<string> * slow = head;
    Node<string> * fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    return slow;

}
int main()
{
    Node<string> *b = new Node<string>("krishna");
    Node<string> *head = b;
    Node<string> *tail = b;
    insertAtTail(tail, "sushma");
    insertAtTail(tail, "nisha");
    insertAtTail(tail, "kajal");
    Node<string>* middle = findMiddle(head);
    cout << middle -> data;
}