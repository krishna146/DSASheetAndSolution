// Problem Link -https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
/* By Krishna Kumar */
#include <iostream>
#include <unordered_map>
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
void solve(Node *head, int &rem)
{
    if (head == NULL)
    {
        return;
    }
    solve(head->next, rem);
    int temp = (head->data + rem) / 10;
    head->data = (head->data + rem) % 10;
    rem = temp;
}
Node *addOne(Node *head)
{
    int rem = 1;
    solve(head, rem);
    if (rem == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}